Module Module1

    Sub Main()
        Dim NumSac As Integer
        Dim OrderS As Integer
        Dim OrderG As Integer
        Dim OrderC As Integer
        Dim TotalPriceI As Integer
        Dim TotalPriceF As Integer
        Dim Pass As Integer


        Console.WriteLine("Please input number of sacs: ")
        NumSac = Console.ReadLine

        Dim SacWeight(NumSac) As Integer
        Dim SacType(NumSac) As Char

        For count = 1 To NumSac
            Do
                Console.WriteLine("Please input sac type: ")
                SacType(count) = Console.ReadLine
                If SacType(count) = "S" Or SacType(count) = "C" Or SacType(count) = "G" Then
                    Pass = 1
                Else
                    Console.WriteLine("Invalid sac type")
                    Pass = 0
                End If
            Loop Until Pass = 1
            Pass = 0
            If SacType(count) = "S" Then
                Do
                    Console.WriteLine("Please input sac weight: ")
                    SacWeight(count) = Console.ReadLine
                    If SacWeight(count) > 49.9 And SacWeight(count) < 50.1 Then
                        OrderS = OrderS + 1
                        Pass = 1
                    ElseIf SacWeight(count) > 50.1 Then
                        Console.WriteLine("Sac is overwieght")
                        Pass = 0
                    ElseIf SacWeight(count) < 49.9 Then
                        Console.WriteLine("Sac is underweight")
                        Pass = 0
                    End If
                Loop Until Pass = 1
                Pass = 0
            ElseIf SacType(count) = "G" Then
                Do
                    Console.WriteLine("Please input sac weight: ")
                    SacWeight(count) = Console.ReadLine
                    If SacWeight(count) > 24.9 And SacWeight(count) < 25.1 Then
                        Console.WriteLine("Sac " & SacType(count) & " Weighs " & SacWeight(count) & " Kg")
                        OrderG = OrderG + 1
                        Pass = 1
                    ElseIf SacWeight(count) > 25.1 Then
                        Console.WriteLine("Sac is overwieght")
                        Pass = 0
                    ElseIf SacWeight(count) < 24.9 Then
                        Console.WriteLine("Sac is underweight")
                        Pass = 0
                    End If
                Loop Until Pass = 1
            ElseIf SacType(count) = "C" Then
                Do
                    Console.WriteLine("Please input sac weight: ")
                    SacWeight(count) = Console.ReadLine
                    If SacWeight(count) > 49.9 And SacWeight(count) < 50.1 Then
                        Console.WriteLine("Sac " & SacType(count) & " Weighs " & SacWeight(count) & " Kg")
                        OrderG = OrderG + 1
                        Pass = 1
                    ElseIf SacWeight(count) > 50.1 Then
                        Console.WriteLine("Sac is overwieght")
                        Pass = 0
                    ElseIf SacWeight(count) < 49.9 Then
                        Console.WriteLine("Sac is underweight")
                        Pass = 0
                    End If
                Loop Until Pass = 1
            Else
                Console.WriteLine("You must choose between cement(C), gravel(G), and sand(S)")
            End If
        Next
        Do
            TotalPriceI = OrderS * 2 + OrderG * 2 + OrderC * 3
            OrderS = OrderS - 2
            OrderC = OrderC - 1
            OrderG = OrderG - 2

            If OrderS > 0 And OrderC > 0 And OrderG > 0 Then
                TotalPriceI = TotalPriceI - 1
                TotalPriceF = TotalPriceI
                Pass = 1
            Else
                Pass = 0
            End If
        Loop Until Pass = 1
    End Sub

End Module
