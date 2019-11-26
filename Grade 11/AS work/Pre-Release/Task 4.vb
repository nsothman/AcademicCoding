Module Module1

    Sub Main()
        Dim Command As Integer
        Console.WriteLine("1- Create a new file")
        Console.WriteLine("2- Append file")
        Console.WriteLine("3- Search")
        Console.Write("Enter command number: ")
        Command = Console.ReadLine
        If Command = 1 Then
            Call Create()
        ElseIf Command = 2 Then
            Call Append()
        ElseIf Command = 3 Then
            Call Search()
        End If
    End Sub

    Sub Search()
        Dim SearchFile As IO.StreamReader
        Dim MembershipNum As Integer = 1
        Dim SearchLine As String
        Dim c As Integer
        Dim Pass As Boolean
        While True
            Do
                SearchFile = New IO.StreamReader("C:\Users\Anas\Desktop\Attendance Log.txt", True)
                Console.Write("Enter the membership number: ")
                MembershipNum = Console.ReadLine
                If MembershipNum = 0 Then
                    Exit While
                ElseIf Len(CStr(MembershipNum)) <> 6 Then
                    Console.WriteLine("Invalid input")
                    Pass = False
                Else
                    Pass = True
                End If
            Loop While Pass = False
            c = 0
            Do Until SearchFile.EndOfStream
                SearchLine = SearchFile.ReadLine()
                If Mid(SearchLine, 1, 6) = CStr(MembershipNum) Then
                    Console.WriteLine("The visit date for the membership number " & MembershipNum & " is " & Mid(SearchLine, 8, 8))
                    c = 1
                End If
            Loop
            If c <> 1 Then
                Console.WriteLine("No such data found")
            End If
        End While
        Console.Clear()
        Call Main()
    End Sub

    Sub Create()
        Dim CreateFile As IO.StreamWriter
        Dim MembershipNum As Integer = 1
        Dim WriteAns As String

        CreateFile = New IO.StreamWriter("C:\Users\Anas\Desktop\Attendance Log.txt")

        Console.Write("Do you want to write to the new file? ")
        WriteAns = Console.ReadLine
        If WriteAns = "yes" Or WriteAns = "Yes" Then
            CreateFile.Close()
            Call Append()
        End If
        CreateFile.Close()
        Console.Clear()
        Call Main()
    End Sub


    Sub Append()
        Dim AppendFile As IO.StreamWriter
        Dim MembershipNum As Integer = 1
        Dim VisitDate As String
        Dim Concat As String
        Dim Pass1 As Boolean
        Dim Pass2 As Boolean
        AppendFile = New IO.StreamWriter("C:\Users\Anas\Desktop\Attendance Log.txt", True)

        While True
            Do
                Console.Write("Enter the membership number (integers only are valid): ")
                MembershipNum = Console.ReadLine
                If MembershipNum = 0 Then
                    Exit While
                ElseIf Len(CStr(MembershipNum)) <> 6 Then
                    Console.WriteLine("Invalid membership number format")
                    Pass1 = False
                Else
                    Pass1 = True
                End If
            Loop While Pass1 = False
            Do
                Console.Write("Enter the date: ")
                VisitDate = Console.ReadLine
                If Len(VisitDate) = 8 Then
                    Concat = CStr(MembershipNum) & " " & VisitDate
                    AppendFile.WriteLine(Concat)
                    Pass2 = True
                Else
                    Console.WriteLine("Invalid date format")
                    Pass2 = False
                End If
            Loop While Pass2 = False
        End While
        AppendFile.Close()
        Console.ReadLine()
        Console.Clear()
        Call Main()
    End Sub

End Module
