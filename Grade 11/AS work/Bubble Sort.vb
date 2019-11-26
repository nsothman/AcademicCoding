Module Module1

    Sub Main()

        Dim List As New List(Of Integer) From {1, 1000}
        Dim Num(1001) As Integer
        Dim Dec As Integer = 1000
        Dim RandomNum As New Random
        Dim x As Integer
        Dim Dull As Integer
        Dim count As Integer = 0

        For k = 1 To 1000
            List.Insert(k, k)
        Next

        Do Until count = 1000
            x = RandomNum.Next(1, 1000)
            If List.Contains(x) Then
                Num(count) = x
                List.Remove(x)
                count += 1
            End If
        Loop

        Do
            For i = 1 To 1000
                If Num(i) > Num(i + 1) Then
                    Dull = Num(i)
                    Num(i) = Num(i + 1)
                    Num(i + 1) = Dull
                End If
            Next
            Dec = Dec - 1
        Loop Until Dec = 0

        For j = 1 To 1001
            Console.WriteLine(Num(j))
        Next

    End Sub

End Module
