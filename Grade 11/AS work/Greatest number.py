Num = list(range(1,11))
Greatest = -999999999
count = 1
while count < 10:
	Num[int(count)] = input("Enter number: ")
	if int(Num[int(count)]) > Greatest:
		Greatest = int(Num[int(count)])
	count = count + 1
print("The greatest number is ", Greatest)