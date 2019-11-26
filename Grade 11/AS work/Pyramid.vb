Module Module1

    Sub Main()
        Dim Symbol As Char
        Dim MaxSymbol As Integer
        Dim SpaceNumber As Integer
        Dim SymbolNumber As Integer

        Console.Write("Enter symbol to make pyramid: ")
        Symbol = Console.ReadLine()

        Do Until MaxSymbol Mod 2 = 1
            Console.Write("Enter the max number of symbols: ")
            MaxSymbol = Console.ReadLine
            If MaxSymbol Mod 2 = 0 Then
                Console.WriteLine("Max number of symbol should be odd")
            End If
        Loop

        SpaceNumber = (MaxSymbol - 1) / 2
        SymbolNumber = 1

        Do While SymbolNumber <= MaxSymbol
            For i = 1 To SpaceNumber
                Console.Write(" ")
            Next
            For j = 1 To SymbolNumber
                Console.Write(Symbol)
            Next
            Console.WriteLine()
            SymbolNumber = SymbolNumber + 2
            SpaceNumber = SpaceNumber - 1
        Loop
    End Sub

End Module
