Module Module1

    Sub Main()
        Dim List As New List(Of Integer) From {1, 1000}
        Dim Num(1001) As Integer
        Dim Dec As Integer = 0
        Dim RandomNum As New Random
        Dim x As Integer
        Dim count As Integer = 0
        Dim Dull As Integer

        For k = 1 To 1000
            List.Insert(k, k)
        Next

        Do
            x = RandomNum.Next(1, 1001)
            If List.Contains(x) Then
                Num(count) = x
                List.Remove(x)
                count += 1
            End If
        Loop Until count = 1001

        Console.WriteLine("____________________UNORGANISED____________________")
        Console.ReadLine()

        For k = 1 To 1000
            Console.WriteLine(Num(k))
        Next

        Console.ReadLine()
        Console.WriteLine("_____________________ORGANISED_____________________")
        Console.ReadLine()

        Do
            For j = 0 To 1000
                If Num(j) > Num(j + 1) Then
                    Dull = Num(j)
                    Num(j) = Num(j + 1)
                    Num(j + 1) = Dull
                End If
            Next
            Dec += 1
        Loop Until Dec = 1000

        For k = 1 To 1000
            Console.WriteLine(Num(k))
        Next
    End Sub

End Module