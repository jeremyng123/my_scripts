import ctypes

import ida_ida
import ida_funcs
import ida_graph
import ida_idaapi
import ida_kernwin
import ida_hexrays

from PyQt5 import QtWidgets, QtGui, QtCore, sip

from lucid.ui.sync import MicroCursorHighlight
from lucid.ui.subtree import MicroSubtreeView
from lucid.util.python import register_callback, notify_callback
from lucid.util.hexrays import get_microcode, get_mmat, get_mmat_name, get_mmat_levels 
from lucid.microtext import MicrocodeText, MicroInstructionToken, MicroOperandToken, AddressToken, BlockNumberToken, translate_mtext_position, remap_mtext_position

#------------------------------------------------------------------------------
# Microcode Explorer
#------------------------------------------------------------------------------
#
#    The Microcode Explorer UI is mostly implemented following a standard
#    Model-View-Controller pattern. This is a little abnormal for Qt, but 
#    I've come to appreciate it more for its portability and testability.
#

class MicrocodeExplorer(object):
    """
    The controller component of the microcode explorer.

    The role of the controller is to handle user gestures, map user actions to
    model updates, and change views based on controls. In theory, the
    controller should be able to drive the 'view' headlessly or simulate user
    UI interaction.
    """
    
    def __init__(self):
        self.model = MicrocodeExplorerModel()
        self.view = MicrocodeExplorerView(self, self.model)
        self.view._code_sync.enable_sync(True) # XXX/HACK

    def show(self, address=None):
        """
        Show the microcode explorer.
        """
        if address is None:
            address = ida_kernwin.get_screen_ea()
        self.select_function(address)
        self.view.show()

    def show_subtree(self, insn_token):
        """
        Show the sub-instruction graph for the given instruction token.
        """
        graph = MicroSubtreeView(insn_token.insn)
        graph.show()

        # TODO/HACK: this is dumb, but moving it breaks my centering code so
        # i'll figure it out later...
        gv = ida_graph.get_graph_viewer(graph.GetWidget())
        ida_graph.viewer_set_titlebar_height(gv, 15)

    #-------------------------------------------------------------------------
    # View Toggles
    #-------------------------------------------------------------------------

    def set_highlight_mutual(self, status):
        """
        Toggle the highlighting of lines containing the same active address.
        """
        if status:
            self.view._code_sync.hook()
        else:
            self.view._code_sync.unhook()
        ida_kernwin.refresh_idaview_anyway()

    def set_verbose(self, status):
        """
        Toggle the verbosity of the printed microcode text.
        """
        self.model.verbose = status
        ida_kernwin.refresh_idaview_anyway()
    
    #-------------------------------------------------------------------------
    # View Controls
    #-------------------------------------------------------------------------

    def select_function(self, address):
        """
        Switch the microcode view to the specified function.
        """
        func = ida_funcs.get_func(address)
        if not func:
            return False
        
        for maturity in get_mmat_levels():
            mba = get_microcode(func, maturity)
            mtext = MicrocodeText(mba, self.model.verbose)
            self.model.update_mtext(mtext, maturity)

        self.view.refresh()
        ida_kernwin.refresh_idaview_anyway()
        return True

    def select_maturity(self, maturity_name):
        """
        Switch the microcode view to the specified maturity level.
        """
        self.model.active_maturity = get_mmat(maturity_name)
        #self.view.refresh()

    def select_address(self, address):
        """
        Select a token in the microcode view matching the given address.
        """
        tokens = self.model.mtext.get_tokens_for_address(address)
        if not tokens:
            return None

        token_line_num, token_x = self.model.mtext.get_pos_of_token(tokens[0])
        rel_y = self.model.current_position[2]

        if self.model.current_position[2] == 0:
            rel_y = 30

        self.model.current_position = (token_line_num, token_x, rel_y)
        return tokens[0]

    def select_position(self, line_num, x, y):
        """
        Select the given text position in the microcode view.
        """
        self.model.current_position = (line_num, x, y)
        #print(" - hovered token: %s" % self.model.current_token.text)
        #print(" - hovered taddr: 0x%08X" % self.model.current_token.address)
        #print(" - hovered laddr: 0x%08X" % self.model.current_address)

    def activate_position(self, line_num, x, y):
        """
        Activate (eg. double click) the given text position in the microcode view.
        """
        token = self.model.mtext.get_token_at_position(line_num, x)

        if isinstance(token, AddressToken):
            ida_kernwin.jumpto(token.target_address, -1, 0)
            return

        if isinstance(token, BlockNumberToken) or (isinstance(token, MicroOperandToken) and token.mop.t == ida_hexrays.mop_b):
            blk_idx = token.blk_idx if isinstance(token, BlockNumberToken) else token.mop.b
            blk_token = self.model.mtext.blks[blk_idx]
            blk_line_num, _ = self.model.mtext.get_pos_of_token(blk_token.lines[0])
            self.model.current_position = (blk_line_num, 0, y)
            self.view._code_view.Jump(*self.model.current_position) 
            return

class MicrocodeExplorerModel(object):
    """
    The model component of the microcode explorer.
    
    The role of the model is to encapsulate application state, respond to
    state queries, and notify views of changes. Ideally, the model could be
    serialized / unserialized to save and restore state.
    """

    def __init__(self):

        #
        # 'mtext' is short for MicrocodeText objects (see microtext.py)
        #
        # this dictionary will contain a mtext object (the renderable text
        # mapping of a given hexrays mba_t) for each microcode maturity level
        # of the current function. 
        #
        # at any given time, one mtext will be 'active' in the model, and
        # therefore visible in the UI/Views 
        #

        self._mtext = {x: None for x in get_mmat_levels()}

        # 
        # there is a 'cursor' (ViewCursor) for each microcode maturity level /
        # mtext object. cursors don't actually contain the 'position' in the
        # rendered text (line_num, x), but also information to position the
        # cursor within the line view (y)
        #

        self._view_cursors = {x: None for x in get_mmat_levels()}

        #
        # the currently active / selected maturity level of the model. this
        # determines which mtext is currently visible / active in the
        # microcode view, and which cursor will be used
        #

        self._active_maturity = ida_hexrays.MMAT_GENERATED

        # this flag tracks the verbosity toggle state
        self._verbose = False

        #----------------------------------------------------------------------
        # Callbacks
        #----------------------------------------------------------------------

        self._mtext_refreshed_callbacks = []
        self._position_changed_callbacks = []
        self._maturity_changed_callbacks = []
    
    #-------------------------------------------------------------------------
    # Read-Only Properties
    #-------------------------------------------------------------------------

    @property
    def mtext(self):
        """
        Return the microcode text mapping for the current maturity level.
        """
        return self._mtext[self._active_maturity]

    @property
    def current_line(self):
        """
        Return the line token at the current viewport cursor position.
        """
        if not self.mtext:
            return None
        line_num, _, _ = self.current_position
        return self.mtext.lines[line_num] 

    @property
    def current_function(self):
        """
        Return the current function address.
        """
        if not self.mtext:
            return ida_idaapi.BADADDR
        return self.mtext.mba.entry_ea

    @property
    def current_token(self):
        """
        Return the token at the current viewport cursor position.
        """
        return self.mtext.get_token_at_position(*self.current_position[:2])
    
    @property
    def current_address(self):
        """
        Return the address at the current viewport cursor position.
        """
        return self.mtext.get_address_at_position(*self.current_position[:2])

    @property
    def current_cursor(self):
        """
        Return the current viewport cursor.
        """
        return self._view_cursors[self._active_maturity]

    #-------------------------------------------------------------------------
    # Mutable Properties
    #-------------------------------------------------------------------------

    @property
    def current_position(self):
        """
        Return the current viewport cursor position (line_num, view_x, view_y).
        """
        return self.current_cursor.viewport_position

    @current_position.setter
    def current_position(self, value):
        """
        Set the cursor position of the viewport.
        """
        self._gen_cursors(value, self.active_maturity)
        self._notify_position_changed()

    @property
    def verbose(self):
        """
        Return the microcode verbosity status of the viewport.
        """
        return self._verbose

    @verbose.setter
    def verbose(self, value):
        """
        Set the verbosity of the microcode displayed by the viewport.
        """
        if self._verbose == value:
            return

        # update the active verbosity setting
        self._verbose = value

        # verbosity must have changed, so force a mtext refresh
        self.refresh_mtext()
    
    @property
    def active_maturity(self):
        """
        Return the active microcode maturity level.
        """
        return self._active_maturity
    
    @active_maturity.setter
    def active_maturity(self, new_maturity):
        """
        Set the active microcode maturity level.
        """
        self._active_maturity = new_maturity
        self._notify_maturity_changed()

    #----------------------------------------------------------------------
    # Misc
    #----------------------------------------------------------------------

    def update_mtext(self, mtext, maturity):
        """
        Set the mtext for a given microcode maturity level.
        """
        self._mtext[maturity] = mtext
        self._view_cursors[maturity] = ViewCursor(0, 0, 0)

    def refresh_mtext(self):
        """
        Regenerate the rendered text for all microcode maturity levels.

        TODO: This is a bit sloppy, and is basically only used for the
        verbosity toggle.
        """
        for maturity, mtext in self._mtext.items():
            if maturity == self.active_maturity:
                new_mtext = MicrocodeText(mtext.mba, self.verbose)
                self._mtext[maturity] = new_mtext
                self.current_position = translate_mtext_position(self.current_position, mtext, new_mtext)
                continue
            mtext.refresh(self.verbose)
        self._notify_mtext_refreshed()

    def _gen_cursors(self, position, mmat_src):
        """
        Generate the cursors for all levels from a source position and maturity.
        """
        mmat_levels = get_mmat_levels()
        mmat_first, mmat_final = mmat_levels[0], mmat_levels[-1]

        # clear out all the existing cursor mappings 
        self._view_cursors = {x: None for x in mmat_levels}

        # save the starting cursor
        line_num, x, y = position 
        self._view_cursors[mmat_src] = ViewCursor(line_num, x, y, True)

        # map the cursor backwards from the source maturity
        mmat_lower = range(mmat_first, mmat_src)[::-1]
        current_maturity = mmat_src
        for next_maturity in mmat_lower:
            self._transfer_cursor(current_maturity, next_maturity)
            current_maturity = next_maturity

        # map the cursor forward from the source maturity
        mmat_higher = range(mmat_src+1, mmat_final + 1)
        current_maturity = mmat_src
        for next_maturity in mmat_higher:
            self._transfer_cursor(current_maturity, next_maturity)
            current_maturity = next_maturity

    def _transfer_cursor(self, mmat_src, mmat_dst):
        """
        Translate the cursor position from one maturity to the next.
        """
        position = self._view_cursors[mmat_src].viewport_position
        mapped = self._view_cursors[mmat_src].mapped

        # attempt to translate the position in one mtext to another
        projection = translate_mtext_position(position, self._mtext[mmat_src], self._mtext[mmat_dst])

        # if translation failed, we will generate an approximate cursor
        if not projection:
            mapped = False
            projection = remap_mtext_position(position, self._mtext[mmat_src], self._mtext[mmat_dst])

        # save the generated cursor
        line_num, x, y = projection
        self._view_cursors[mmat_dst] = ViewCursor(line_num, x, y, mapped)

    #----------------------------------------------------------------------
    # Callbacks
    #----------------------------------------------------------------------

    def mtext_refreshed(self, callback):
        """
        Subscribe a callback for mtext refresh events.
        """
        register_callback(self._mtext_refreshed_callbacks, callback)

    def _notify_mtext_refreshed(self):
        """
        Notify listeners of a mtext refresh event.
        """
        notify_callback(self._mtext_refreshed_callbacks)

    def position_changed(self, callback):
        """
        Subscribe a callback for cursor position changed events.
        """
        register_callback(self._position_changed_callbacks, callback)

    def _notify_position_changed(self):
        """
        Notify listeners of a cursor position changed event.
        """
        notify_callback(self._position_changed_callbacks)

    def maturity_changed(self, callback):
        """
        Subscribe a callback for maturity changed events.
        """
        register_callback(self._maturity_changed_callbacks, callback)

    def _notify_maturity_changed(self):
        """
        Notify listeners of a maturity changed event.
        """
        notify_callback(self._maturity_changed_callbacks)

#-----------------------------------------------------------------------------
# UI Components
#-----------------------------------------------------------------------------

class MicrocodeExplorerView(QtWidgets.QWidget):
    """
    The view component of the Microcode Explorer.
    """

    WINDOW_TITLE = "Microcode Explorer"

    def __init__(self, controller, model):
        super(MicrocodeExplorerView, self).__init__()
        self.visible = False

        # the backing model, and controller for this view (eg, mvc pattern)
        self.model = model
        self.controller = controller
        
        # initialize the plugin UI
        self._ui_init()
        self._ui_init_signals()

    #--------------------------------------------------------------------------
    # Pseudo Widget Functions
    #--------------------------------------------------------------------------

    def show(self):
        self.refresh()

        # show the dockable widget
        flags = ida_kernwin.PluginForm.WOPN_DP_RIGHT | 0x200 # WOPN_SZHINT
        ida_kernwin.display_widget(self._twidget, flags)
        ida_kernwin.set_dock_pos(self.WINDOW_TITLE, "IDATopLevelDockArea", ida_kernwin.DP_RIGHT)

        self._code_sync.hook()

    def _cleanup(self):
        self.visible = False
        self._twidget = None
        self.widget = None
        self._code_sync.unhook()
        self._ui_hooks.unhook()
        # TODO cleanup controller / model

    #--------------------------------------------------------------------------
    # Initialization - UI
    #--------------------------------------------------------------------------

    def _ui_init(self):
        """
        Initialize UI elements.
        """
        self._ui_init_widget()

        # initialize our ui elements
        self._ui_init_list()
        self._ui_init_code()
        self._ui_init_settings()

        # layout the populated ui just before showing it
        self._ui_layout()

    def _ui_init_widget(self):
        """
        Initialize an IDA widget for this UI control.
        """

        # create a dockable widget, and save a reference to it for later use
        self._twidget = ida_kernwin.create_empty_widget(self.WINDOW_TITLE)

        # cast the IDA 'twidget' to a less opaque QWidget object
        self.widget = ida_kernwin.PluginForm.TWidgetToPyQtWidget(self._twidget)

        # hooks to help track the container/widget lifetime 
        class ExplorerUIHooks(ida_kernwin.UI_Hooks):
            def widget_invisible(_, twidget):
                if twidget == self._twidget:
                    self.visible = False
                    self._cleanup()
            def widget_visible(_, twidget):
                if twidget == self._twidget:
                    self.visible = True

        # install the widget lifetime hooks 
        self._ui_hooks = ExplorerUIHooks()
        self._ui_hooks.hook()

    def _ui_init_list(self):
        """
        Initialize the microcode maturity list.
        """
        self._maturity_list = LayerListWidget()

    def _ui_init_code(self):
        """
        Initialize the microcode view(s).
        """
        self._code_view = MicrocodeView(self.model)
        self._code_sync = MicroCursorHighlight(self.controller, self.model)
        self._code_sync.track_view(self._code_view.widget)

    def _ui_init_settings(self):
        """
        Initialize the explorer settings groupbox.
        """
        self._checkbox_cursor = QtWidgets.QCheckBox("Highlight mutual")
        self._checkbox_cursor.setCheckState(QtCore.Qt.Checked)
        self._checkbox_verbose = QtWidgets.QCheckBox("Show use/def")
        self._checkbox_sync = QtWidgets.QCheckBox("Sync hexrays")
        self._checkbox_sync.setCheckState(QtCore.Qt.Checked)
        
        self._groupbox_settings = QtWidgets.QGroupBox("Settings")
        layout = QtWidgets.QVBoxLayout()
        layout.addWidget(self._checkbox_cursor)
        layout.addWidget(self._checkbox_verbose)
        layout.addWidget(self._checkbox_sync)
        self._groupbox_settings.setLayout(layout)

    def _ui_layout(self):
        """
        Layout the major UI elements of the widget.
        """
        layout = QtWidgets.QGridLayout()

        # arrange the widgets in a 'grid'         row  col  row span  col span
        layout.addWidget(self._code_view.widget,    0,   0,        0,        1)
        layout.addWidget(self._maturity_list,       0,   1,        1,        1)
        layout.addWidget(self._groupbox_settings,   1,   1,        1,        1)

        # apply the layout to the widget
        self.widget.setLayout(layout)
        
    def _ui_init_signals(self):
        """
        Connect UI signals.
        """
        self._maturity_list.currentItemChanged.connect(lambda x, y: self.controller.select_maturity(x.text()))
        self._code_view.connect_signals(self.controller)
        self._code_view.OnClose = self.hide # HACK

        # checkboxes
        self._checkbox_cursor.stateChanged.connect(lambda x: self.controller.set_highlight_mutual(bool(x)))
        self._checkbox_verbose.stateChanged.connect(lambda x: self.controller.set_verbose(bool(x)))
        self._checkbox_sync.stateChanged.connect(lambda x: self._code_sync.enable_sync(bool(x)))

        # model signals
        self.model.mtext_refreshed(self.refresh)
        self.model.maturity_changed(self.refresh)
    
    #--------------------------------------------------------------------------
    # Misc
    #--------------------------------------------------------------------------

    def refresh(self):
        """
        Refresh the microcode explorer UI based on the model state.
        """
        self._maturity_list.setCurrentRow(self.model.active_maturity - 1)
        self._code_view.refresh()

class LayerListWidget(QtWidgets.QListWidget):
    """
    The microcode maturity list widget
    """

    def __init__(self):
        super(LayerListWidget, self).__init__()

        # populate the list widget with the microcode maturity levels
        self.addItems([get_mmat_name(x) for x in get_mmat_levels()])

        # select the first maturity level, by default
        self.setCurrentRow(0)

        # make the list widget a fixed size, slightly wider than it needs to be
        width = self.sizeHintForColumn(0)
        self.setMaximumWidth(int(width + width * 0.10))

    def wheelEvent(self, event):
        """
        Handle mouse wheel scroll events.
        """
        y = event.angleDelta().y()

        # scrolling down, clamp to last row
        if y < 0:
            next_row = min(self.currentRow()+1, self.count()-1)

        # scrolling up, clamp to first row (0)
        elif y > 0:
            next_row = max(self.currentRow()-1, 0)
        
        # horizontal scroll ? nothing to do..
        else:
            return

        self.setCurrentRow(next_row)

class MicrocodeView(ida_kernwin.simplecustviewer_t):
    """
    An IDA-based text area that will render the Hex-Rays microcode.

    TODO: I'll probably rip this out in the future, as I'll have finer
    control over the interaction / implementation if I just roll my own
    microcode text widget.

    For that reason, excuse its hacky-ness / lack of comments.
    """

    def __init__(self, model):
        super(MicrocodeView, self).__init__()
        self.model = model
        self.Create()

    def connect_signals(self, controller):
        self.controller = controller
        self.OnCursorPosChanged = lambda: controller.select_position(*self.GetPos())
        self.OnDblClick = lambda _: controller.activate_position(*self.GetPos())
        self.model.position_changed(self.refresh_cursor)

    def refresh(self):
        self.ClearLines()
        for line in self.model.mtext.lines:
            self.AddLine(line.tagged_text)
        self.refresh_cursor()

    def refresh_cursor(self):
        if not self.model.current_position:
            return
        self.Jump(*self.model.current_position)

    def Create(self):
        if not super(MicrocodeView, self).Create(None):
            return False
        self._twidget = self.GetWidget()
        self.widget = ida_kernwin.PluginForm.TWidgetToPyQtWidget(self._twidget)
        return True

    def OnClose(self):
        pass

    def OnCursorPosChanged(self):
        pass

    def OnDblClick(self, shift):
        pass

    def OnPopup(self, form, popup_handle):
        controller = self.controller

        #
        # so, i'm pretty picky about my UI / interactions. IDA puts items in
        # the right click context menus of custom (code) viewers.
        #
        # these items aren't really relevant (imo) to the microcode viewer,
        # so I do some dirty stuff here to filter them out and ensure only
        # my items will appear in the context menu.
        #
        # there's only one right click context item right now, but in the
        # future i'm sure there will be more.
        #

        class FilterMenu(QtCore.QObject):
            def __init__(self, qmenu):
                super(QtCore.QObject, self).__init__()
                self.qmenu = qmenu
        
            def eventFilter(self, obj, event):
                if event.type() != QtCore.QEvent.Polish:
                    return False
                for action in self.qmenu.actions():
                    if action.text() in ["&Font...", "&Synchronize with"]: # lol..
                        qmenu.removeAction(action)
                self.qmenu.removeEventFilter(self)
                self.qmenu = None
                return True

        p_qmenu = ctypes.cast(int(popup_handle), ctypes.POINTER(ctypes.c_void_p))[0]
        qmenu = sip.wrapinstance(int(p_qmenu), QtWidgets.QMenu)
        self.filter = FilterMenu(qmenu)
        qmenu.installEventFilter(self.filter)

        # only handle right clicks on lines containing micro instructions
        ins_token = self.model.mtext.get_ins_for_line(self.model.current_line)
        if not ins_token:
            return False

        class MyHandler(ida_kernwin.action_handler_t):
            def activate(self, ctx):
                controller.show_subtree(ins_token)
            def update(self, ctx):
                return ida_kernwin.AST_ENABLE_ALWAYS

        # inject the 'View subtree' action into the right click context menu
        desc = ida_kernwin.action_desc_t(None, 'View subtree', MyHandler())
        ida_kernwin.attach_dynamic_action_to_popup(form, popup_handle, desc, None)
        
        return True

#-----------------------------------------------------------------------------
# Util
#-----------------------------------------------------------------------------

class ViewCursor(object):
    """
    TODO
    """
    def __init__(self, line_num, x, y, mapped=True):
        self.line_num = line_num
        self.x = x
        self.y = y
        self.mapped = mapped

    @property 
    def text_position(self):
        return (self.line_num, self.x)

    @property
    def viewport_position(self):
        return (self.line_num, self.x, self.y)
