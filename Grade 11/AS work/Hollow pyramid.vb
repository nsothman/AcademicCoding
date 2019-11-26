Module Module1

    Sub Main()
        Dim Symbol As Char
        Dim MaxSymbol As Integer
        Dim SpaceNumber As Integer
        Dim SymbolNumber As Integer
        Dim MidSpace As Integer
        Dim MidSpaceMax As Integer

        Console.Write("Enter symbol to make pyramid: ")
        Symbol = Console.ReadLine()

        Do Until MaxSymbol Mod 2 = 1
            Console.Write("Enter the max number of symbols: ")
            MaxSymbol = Console.ReadLine() 
            If MaxSymbol Mod 2 = 0 Then
                Console.WriteLine("Max number of symbol should be odd")
            End If
        Loop

        SpaceNumber = (MaxSymbol - 1) / 2
        SymbolNumber = 1
        MidSpace = 0
        MidSpaceMax = MaxSymbol - 4

        Do While SymbolNumber < MaxSymbol
            For i = 1 To SpaceNumber
                Console.Write(" ")
            Next
            Console.Write(Symbol)
            For j = 1 To MidSpace
                Console.Write(" ")
            Next
            If MidSpace > 0 Then
                Console.Write(Symbol)
            End If
            Console.WriteLine()
            SymbolNumber = SymbolNumber + 2
            SpaceNumber = SpaceNumber - 1
            MidSpace = MidSpace + 2
        Loop
        For k = 0 To MaxSymbol
            Console.Write(Symbol)
        Next
        Console.WriteLine()
    End Sub

End Module
