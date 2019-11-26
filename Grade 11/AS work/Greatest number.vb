Module Module1

    Sub Main()
        Dim Num(30) As Integer
        Dim Greatest As Integer
        Dim count As Integer

        count = 0
        Greatest = -1000000000

        For count = 1 To 10
            Console.Write("Enter number: ")
            Num(count) = Console.ReadLine
            If Num(count) > Greatest Then
                Greatest = Num(count)
            End If
        Next
        Console.WriteLine("The greatest number is " & Greatest)
    End Sub

End Module
