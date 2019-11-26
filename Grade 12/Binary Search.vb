Module Module1
    Dim List As New List(Of Integer) From {1, 1000}
    Dim Num(510) As Integer
    Dim RandomNum As New Random
    Dim x, Dull, Dec As Integer
    Dim count As Integer = 0

    Sub Main()

        Call RandomNumber()
        'Creates a list of 500 random numbers in the range of 1 to 1000

        Call BubbleSort()
        'Sorts the list by a bubble sorting algorithm

        For k = 1 To 500
            Console.WriteLine(Num(k))
        Next

        Console.WriteLine()

        Call BinarySearch()
        'Inputs and searches for a number in the organised list using binary search algorithm

    End Sub

    Sub BubbleSort()

        Do
            For j = 0 To 500
                If Num(j) > Num(j + 1) Then
                    Dull = Num(j)
                    Num(j) = Num(j + 1)
                    Num(j + 1) = Dull
                End If
            Next
            Dec += 1
        Loop Until Dec = 500

    End Sub

    Sub RandomNumber()

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
        Loop Until count = 500

    End Sub

    Sub BinarySearch()

        Dim Max As Integer = 500
        Dim Min As Integer = 1
        Dim Found As Boolean = False
        Dim SearchFail As Boolean = False
        Dim Num2BFound, Mid As Integer

        Console.Write("Enter a number you want to find (1 - 1000): ")
        Num2BFound = Console.ReadLine()

        Console.WriteLine()

        While Not Found And Not SearchFail
            Mid = (Max + Min) \ 2
            If Num(Mid) = Num2BFound Then
                Found = True
            ElseIf Min >= Max Then
                SearchFail = True
            ElseIf Num(Mid) > Num2BFound Then
                Max = Mid - 1
            Else
                Min = Mid + 1
            End If
        End While

        If Found = True Then
            Console.WriteLine("Number was found")
        Else
            Console.WriteLine("Number was not found")
        End If
        Console.WriteLine()

    End Sub
End Module
