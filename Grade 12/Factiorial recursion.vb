Module Module1
    Dim Num, Answer, Result As Integer

    Sub Main()

        Console.Write("Enter a number (0 to 12): ")
        Num = Console.ReadLine
        Answer = Factorial(Num)
        Console.WriteLine("The factorial of " & Num & " is: " & Answer)

    End Sub

    Function Factorial(ByVal Num) As Integer

        If Num = 0 Then
            Result = 1
        Else
            Result = Num * Factorial(Num - 1)
        End If

        Return Result

    End Function

End Module
