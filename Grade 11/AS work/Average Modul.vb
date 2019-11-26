Module Module1
    Dim Num(10) As Integer
    Dim Total As Integer
    Dim Avrg As Integer

    Sub Input()
        For count = 1 To 10
            Console.Write("Input number: ")
            Num(count) = Console.ReadLine()
            Call TotalCalc()
        Next
    End Sub

    Function TotalCalc()
        Dim count As Integer
        Total = Total + Num(count)
    End Function
    Sub AvrgCalc()
        Avrg = Total / 10
    End Sub
    Sub Main()
        Call Input()
        Call AvrgCalc()
        Console.WriteLine(Avrg)
    End Sub
End Module
