Module Module1

    Dim NullPointer As Integer = 0

    Public Structure ListNode
        Dim Data As String
        Dim Pointer As Integer
    End Structure

    Dim StartPointer As Integer
    Dim FreeListPtr As Integer
    Dim List(7) As ListNode

    Sub InitialiseList()
        StartPointer = NullPointer
        FreeListPtr = 1
        For count = 1 To 6
            List(count).Pointer = count + 1
        Next
        List(7).Pointer = NullPointer
    End Sub

    Sub Main()
        Call InitialiseList()
    End Sub

End Module
