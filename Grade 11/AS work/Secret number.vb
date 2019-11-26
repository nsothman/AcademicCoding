Module Module1

    Sub Main()
        Dim Pass As Integer
        Dim SecretNumber As Integer
        Dim Guess As Integer
        Pass = 0
        SecretNumber = 56982
        While Pass = 0
            Console.WriteLine("Please enter guess:")
            Guess = Console.ReadLine
            If Guess > SecretNumber Then
                Console.WriteLine("Secret number is smaller")
            ElseIf Guess < SecretNumber Then
                Console.WriteLine("Secret number is greater")
            Else
                Console.WriteLine("You've guessed the secret number!")
                Pass = 1
            End If
        End While

    End Sub

End Module
