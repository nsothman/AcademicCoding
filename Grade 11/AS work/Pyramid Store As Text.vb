Module Module1
    Dim MaxSymbol As Integer
    Sub Main()
        Dim Symbol As Char
        Dim SpaceNumber As Integer
        Dim SymbolNumber As Integer
        Dim CreateFile As IO.StreamWriter
        CreateFile = New IO.StreamWriter("C:\Users\ARROWAD\Desktop\Anas\Test file.txt")
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
                CreateFile.Write(" ")
            Next
            For j = 1 To SymbolNumber
                CreateFile.Write(Symbol)
            Next
            CreateFile.WriteLine()
            SymbolNumber = SymbolNumber + 2
            SpaceNumber = SpaceNumber - 1
        Loop
        CreateFile.Close()
        Call ReadFile()
    End Sub
    Sub ReadFile()
        Dim Reader As String
        Dim ReadFile As IO.StreamReader
        ReadFile = New IO.StreamReader("C:\Users\ARROWAD\Desktop\Anas\Test file.txt")
        Do Until ReadFile.EndOfStream
            Reader = ReadFile.ReadLine()
            Console.WriteLine(Reader)
        Loop
    End Sub
End Module
