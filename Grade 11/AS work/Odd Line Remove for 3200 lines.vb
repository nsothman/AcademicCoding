Module Module1

    Sub Main()
        Dim line(1600) As String
        Dim line2(1600) As String
        Dim ReadFile As IO.StreamReader
        Dim WriteFile As IO.StreamWriter
        ReadFile = New IO.StreamReader("C:\Users\Anas\Desktop\people.txt", True)
        WriteFile = New IO.StreamWriter("C:\Users\Anas\Desktop\people2.txt")
        For i = 1 To 1600
            line(i) = ReadFile.ReadLine()
            line2(i) = ReadFile.ReadLine()
            If line(i) = "" Then
                line(i) = line2(i)
            End If
        Next
        For j = 1 To 1600
            WriteFile.WriteLine(line(j))
        Next
        WriteFile.Close()
    End Sub

End Module
