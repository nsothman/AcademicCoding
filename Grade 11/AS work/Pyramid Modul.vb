Module Module1
    Dim Symbol As Char
    Dim MaxSymbol As Integer
    Dim SpaceNumber As Integer
    Dim SymbolNumber As Integer
    Sub InputValidation()
        If MaxSymbol Mod 2 = 0 Then
            Console.WriteLine("Max number of symbol should be odd")
        End If
    End Sub
    Sub Inputs()

        Console.Write("Enter symbol to make pyramid: ")
        Symbol = Console.ReadLine()

        Do Until MaxSymbol Mod 2 = 1
            Console.Write("Enter the max number of symbols: ")
            MaxSymbol = Console.ReadLine
            Call InputValidation()
        Loop
    End Sub
    Sub SpaceCalc()
        SpaceNumber = (MaxSymbol - 1) / 2
        SymbolNumber = 1
    End Sub
    Sub LoopCalc()
        SymbolNumber = SymbolNumber + 2
        SpaceNumber = SpaceNumber - 1
    End Sub
    Sub Main()
        Call inputs()
        Call Spacecalc()
        Do While SymbolNumber <= MaxSymbol
            For i = 1 To SpaceNumber
                Console.Write(" ")
            Next
            For j = 1 To SymbolNumber
                Console.Write(Symbol)
            Next
            Console.WriteLine()
            Call LoopCalc()
        Loop
    End Sub
End Module
