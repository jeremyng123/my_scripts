Sub Reverse_String()
Dim s As Range
Set s = Application.Selection
s.Offset(0, 1).Value = StrReverse(s)
End Sub
