Module Module1

    Sub Main()
        Dim MaxColumn As Integer
        Dim MaxRow As Integer
        Dim Table(5, 5) As Char
        Console.Write("Enter number of rows: ")
        MaxRow = Console.ReadLine()
        Console.Write("Enter number of columns: ")
        MaxColumn = Console.ReadLine()
        For Row = 1 To MaxRow
            For Column = 1 To MaxColumn
                Console.Write("Enter value: ")
                Table(Row, Column) = Console.ReadLine()
            Next
        Next
        For count = 1 To 5
            For count1 = 1 To 5
                Console.Write(Table(count, count1))
            Next
            Console.WriteLine()
        Next
    End Sub

End Module
