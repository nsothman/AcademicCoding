Module Module1

    Dim Table(10, 10) As Char
    Dim ColumnNum As Integer
    Dim RowNum As Integer
    Dim count As Integer
    Dim pass As Integer
    Dim Again As String
    Sub FirstTable()
        For Row = 1 To 6
            For Column = 1 To 7
                Table(Row, Column) = "-"
            Next
        Next
    End Sub
    Sub TableOut()
        For i = 1 To 6
            Console.Write("|")
            For j = 1 To 7
                Console.Write(Table(i, j))
                Console.Write("|")
            Next
            Console.WriteLine()
        Next
    End Sub
    Function Skip()
        Do Until Table(RowNum, ColumnNum) = "-"
            If Table(RowNum, ColumnNum) <> "-" Then
                RowNum = RowNum - 1
            End If
        Loop
    End Function
    Sub Player1()
        Dim NoError As Integer
        Do Until NoError = 1
            Console.Write("Player 1, enter column number: ")
            ColumnNum = Console.ReadLine()
            If ColumnNum > 7 Or ColumnNum < 1 Then
                Console.WriteLine("Column number is out of range")
                NoError = 0
            Else
                NoError = 1
            End If
        Loop
        RowNum = 6
        Call Skip()
        Table(RowNum, ColumnNum) = "O"
    End Sub
    Sub Player2()
        Dim NoError As Integer
        Do Until NoError = 1
            Console.Write("Player 2, enter column number: ")
            ColumnNum = Console.ReadLine()
            If ColumnNum > 7 Or ColumnNum < 1 Then
                Console.WriteLine("Column number is out of range")
                NoError = 0
            Else
                NoError = 1
            End If
        Loop
        RowNum = 6
        Call Skip()
        Table(RowNum, ColumnNum) = "X"
    End Sub
    Sub Main()
        Call FirstTable()
        Call TableOut()
        Do While pass = 0
            Do While count <= 42
                Call Player1()
                Console.Clear()
                Call TableOut()
                For i = 1 To 6
                    For j = 1 To 7
                        If Table(i, j) = "O" And Table(i, (j + 1)) = "O" And Table(i, (j + 2)) = "O" And Table(i, (j + 3)) = "O" Then
                            Console.WriteLine("Player 1 wins!")
                            Exit Do
                        End If

                        If Table(i, j) = "O" And Table((i + 1), j) = "O" And Table((i + 2), j) = "O" And Table((i + 3), j) = "O" Then
                            Console.WriteLine("Player 1 wins!")
                            Exit Do
                        End If
                    Next
                Next
                For i = 1 To 3
                    For j = 1 To 4
                        If Table(i, j) = "O" And Table((i + 1), (j + 1)) = "O" And Table((i + 2), (j + 2)) = "O" And Table((i + 3), (j + 3)) = "O" Then
                            Console.WriteLine("Player 1 wins!")
                            Exit Do
                        End If
                    Next
                Next
                For i = 1 To 3
                    For j = 3 To 7
                        If Table(i, j) = "O" And Table((i + 1), (j - 1)) = "O" And Table((i + 2), (j - 2)) = "O" And Table((i + 3), (j - 3)) = "O" Then
                            Console.WriteLine("Player 1 wins!")
                            Exit Do
                        End If
                    Next
                Next
                For i = 4 To 6
                    For j = 1 To 4
                        If Table(i, j) = "O" And Table((i - 1), (j + 1)) = "O" And Table((i - 2), (j + 2)) = "O" And Table((i - 3), (j + 3)) = "O" Then
                            Console.WriteLine("Player 1 wins!")
                            Exit Do
                        End If
                    Next
                Next
                For i = 4 To 6
                    For j = 4 To 7
                        If Table(i, j) = "O" And Table((i - 1), (j - 1)) = "O" And Table((i - 2), (j - 2)) = "O" And Table((i - 3), (j - 3)) = "O" Then
                            Console.WriteLine("Player 1 wins!")
                            Exit Do
                        End If
                    Next
                Next
                Call Player2()
                Console.Clear()
                Call TableOut()
                For i = 1 To 6
                    For j = 1 To 7
                        If Table(i, j) = "X" And Table(i, (j + 1)) = "X" And Table(i, (j + 2)) = "X" And Table(i, (j + 3)) = "X" Then
                            Console.WriteLine("Player 2 wins!")
                            Exit Do
                        End If

                        If Table(i, j) = "X" And Table((i + 1), j) = "X" And Table((i + 2), j) = "X" And Table((i + 3), j) = "X" Then
                            Console.WriteLine("Player 2 wins!")
                            Exit Do
                        End If
                    Next
                Next
                For i = 1 To 3
                    For j = 1 To 4
                        If Table(i, j) = "X" And Table((i + 1), (j + 1)) = "X" And Table((i + 2), (j + 2)) = "X" And Table((i + 3), (j + 3)) = "X" Then
                            Console.WriteLine("Player 2 wins!")
                            Exit Do
                        End If
                    Next
                Next
                For i = 1 To 3
                    For j = 3 To 7
                        If Table(i, j) = "X" And Table((i + 1), (j - 1)) = "X" And Table((i + 2), (j - 2)) = "X" And Table((i + 3), (j - 3)) = "X" Then
                            Console.WriteLine("Player 2 wins!")
                            Exit Do
                        End If
                    Next
                Next
                For i = 4 To 6
                    For j = 1 To 4
                        If Table(i, j) = "X" And Table((i - 1), (j + 1)) = "X" And Table((i - 2), (j + 2)) = "X" And Table((i - 3), (j + 3)) = "X" Then
                            Console.WriteLine("Player 2 wins!")
                            Exit Do
                        End If
                    Next
                Next
                For i = 4 To 6
                    For j = 4 To 7
                        If Table(i, j) = "X" And Table((i - 1), (j - 1)) = "X" And Table((i - 2), (j - 2)) = "X" And Table((i - 3), (j - 3)) = "X" Then
                            Console.WriteLine("Player 2 wins!")
                            Exit Do
                        End If
                    Next
                Next
            Loop
            Console.Write("Try again? ")
            Again = Console.ReadLine()
            If Again = "yes" Then
                pass = 0
                Console.Clear()
                Call FirstTable()
                Call TableOut()
            ElseIf Again = "no" Then
                pass = 1
            End If
        Loop
    End Sub

End Module
