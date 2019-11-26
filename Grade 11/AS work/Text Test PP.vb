Module Module1

    Sub Main()
        Dim FileCreate As IO.StreamWriter
        Dim CDTitle, CDArtist, CDLocation As String

        FileCreate = New IO.StreamWriter("C:\Users\Anas\Desktop\CD Details.txt", True)
        Do Until CDTitle = "##"
            Console.Write("Enter CD title: ")
            CDTitle = Console.ReadLine
            If CDTitle = "##" Then
                Exit Do
            End If
            Console.Write("Enter CD artist: ")
            CDArtist = Console.ReadLine
            Console.Write("Enter CD location: ")
            CDLocation = Console.ReadLine
            FileCreate.WriteLine(CDTitle & " " & CDArtist & " " & CDLocation)
            Console.WriteLine("Details stored, enter ## as CD title if done.")
        Loop
        FileCreate.Close()
    End Sub

End Module
