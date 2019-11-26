Module Module1

    Sub Main()
        Dim List As New List(Of Integer) From {1, 100}
        Dim Num(6) As Integer
        Dim CurrentItem As Integer
        Dim ItemToBeInserted
        Num(1) = 47
        Num(2) = 6
        Num(3) = 54
        Num(4) = 17
        Num(5) = 93
        Num(6) = 28
        For pointer = 2 To 6
            ItemToBeInserted = Num(pointer)
            CurrentItem = pointer - 1
            While Num(CurrentItem) > ItemToBeInserted And CurrentItem > 0
                Num(CurrentItem + 1) = Num(CurrentItem)
                CurrentItem = CurrentItem - 1
            End While
            Num(CurrentItem + 1) = ItemToBeInserted
        Next
        For count = 1 To 6
            Console.WriteLine(Num(count))
        Next
    End Sub

End Module
