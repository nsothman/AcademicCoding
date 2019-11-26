Pass = 0
SecretNumber = 56982
Guess = 0
while Pass == 0:
	Guess = input ("Please enter guess:")
	if int(Guess) > int(SecretNumber):
		print ("Secret number is smaller")
		Pass = 0
	elif int(Guess) < int(SecretNumber):
		print ("Secret number is greater")
		Pass = 0
	else:
		print ("You've guessed the secret number!")
		Pass = 1
