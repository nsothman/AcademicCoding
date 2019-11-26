Module Module1
    Dim Word(10) As String
    Dim CamelString As String
    Sub EmptyArray()
        For count = 1 To 10
            Word(count) = "(EMPTY)"
        Next
    End Sub
    Sub Input()
        Do Until Left(CamelString, 1) >= "A" And Left(CamelString, 1) <= "Z"
            Console.Write("Input sentence in CamelCase: ")
            CamelString = Console.ReadLine()
            If Mid(CamelString, 1, 1) >= "a" And Mid(CamelString, 1, 1) <= "z" Then
                Console.WriteLine("First letter must be capital")
            End If
        Loop
    End Sub
    Sub Check()
        Dim counter As Integer
        For j = 1 To 10
            If Len(CamelString) = 0 Then
                Exit For
            End If
            counter = 0
            If Mid(CamelString, 1, 1) >= "A" And Mid(CamelString, 1, 1) <= "Z" Then
                For i = 2 To Len(CamelString)
                    If Mid(CamelString, i, 1) >= "a" And Mid(CamelString, i, 1) <= "z" Then
                        counter = counter + 1
                    Else
                        Exit For
                    End If
                Next
                If counter > 0 Then
                    Word(j) = Mid(CamelString, 1, counter + 1)
                    CamelString = Mid(CamelString, (counter + 2), (Len(CamelString) - counter - 1))
                Else
                    Word(j) = Mid(CamelString, 1, 1)
                    CamelString = Mid(CamelString, 2, Len(CamelString) - 1)
                End If
            Else
                Console.WriteLine("String must only include letters")
                Exit For
            End If
        Next
    End Sub
    Sub Output()
        For count = 1 To 10
            Console.WriteLine(Word(count))
        Next
    End Sub
    Sub Main()
        Call EmptyArray()
        Call Input()
        Call Check()
        Call Output()
    End Sub
End Module
