Module Module1

    Sub Main()
        Dim MaxColumn As Integer
        Dim MaxRow As Integer
        Dim Table(10, 2) As String
        MaxRow = 10
        MaxColumn = 2
        For Row = 1 To MaxRow
            For Column = 1 To 1
                Console.Write("Enter name: ")
                Table(Row, Column) = Console.ReadLine()
                For Column2 = 2 To 2
                    Console.Write("Enter grade: ")
                    Table(Row, Column2) = Console.ReadLine()

                Next
            Next
        Next
        For count = 1 To MaxRow
            For count1 = 1 To MaxColumn
                Console.Write(Table(count, count1) & " ")
            Next
            Console.WriteLine()
        Next
    End Sub

End Module
