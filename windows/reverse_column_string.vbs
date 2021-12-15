Sub LoopReverseS()
'
' LoopReverse Macro
'

'
    Dim x
    x = 2
    Do While x < 19489
    	Range("S" & x).Select
	Application.Run "traffic.xlsm!ThisWorkbook.Reverse_String"
    	x = x + 1
    Loop
    
End Sub

