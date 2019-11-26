Module Module1

    'List declaration function

    Public Structure ListNode
        Dim Data As Integer
        Dim Pointer As Integer
    End Structure

    Dim List(7) As ListNode
    Dim NullPointer As Integer = 0
    Dim StartPointer As Integer

    Sub InitialiseList()
        StartPointer = NullPointer
        FreeListPtr = 1
        For index = 1 To 6
            List(index).Pointer = index + 1
        Next
        List(7).Pointer = NullPointer
    End Sub

    Sub Main()

        Call InitialiseList()

        Dim FreeListPtr, NewNodePtr, ThisNodePtr, NewItem, PreviousNodePtr As Integer
        Dim DataItem As String

        'Inserting a node to the list:

        List(1).Data = 100
        List(2).Data = 300
        List(3).Data = 400
        FreeListPtr = 4
        NewItem = 200

        If FreeListPtr <> NullPointer Then
            NewNodePtr = FreeListPtr
            List(NewNodePtr).Data = NewItem
            FreeListPtr = List(FreeListPtr).Pointer
            ThisNodePtr = StartPointer

            While ThisNodePtr <> NullPointer And List(ThisNodePtr).Data < NewItem
                PreviousNodePtr = ThisNodePtr
                ThisNodePtr = List(ThisNodePtr).Pointer
            End While

            If PreviousNodePtr = StartPointer Then
                List(NewNodePtr).Pointer = StartPointer
                StartPointer = NewNodePtr
            Else
                List(NewNodePtr).Pointer = List(PreviousNodePtr).Pointer
                List(PreviousNodePtr).Pointer = NewNodePtr
            End If
        End If

        'Deleting a node from the list

        ThisNodePtr = StartPointer

        While ThisNodePtr <> NullPointer And List(ThisNodePtr).Data <> DataItem
            PreviousNodePtr = ThisNodePtr
            ThisNodePtr = List(ThisNodePtr).Pointer
        End While
        If ThisNodePtr <> NullPointer Then
            If ThisNodePtr = StartPointer Then
                StartPointer = List(StartPointer).Pointer
            Else
                List(PreviousNodePtr).Pointer = List(ThisNodePtr).Pointer
            End If
            List(ThisNodePtr).Pointer = FreeListPtr
            FreeListPtr = ThisNodePtr
        End If

    End Sub

End Module
