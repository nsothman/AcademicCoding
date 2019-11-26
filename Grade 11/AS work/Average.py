Total = 0
Num = 0
Avrg = 0
count = 0
while count < 10:
	Num = input("Enter number: ")
	Total = int(Total) + int(Num)
	count = int(count) + 1
Avrg = int(Total) / 10
print ("The average is " , Avrg)