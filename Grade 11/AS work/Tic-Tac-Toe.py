import os
check = True
Table = ["_"] * 5
for a in range(5):
	Table[a] = ["_"] * 5


def PrintTable():
	for b in range(3):
		for c in range(3):
			print(" |", Table[b][c], end="")
		print(" |")

def PlayerX():
	while True:
		PlayerXRow = int(input("Player X, choose row number: "))
		PlayerXColumn = int(input("Choose column number: "))
		if PlayerXRow in range(1, 4) and PlayerXColumn in range(1,4):
			if Table[PlayerXRow - 1][PlayerXColumn - 1] == "_":
				Table[int(PlayerXRow - 1)].pop(int(PlayerXColumn - 1))
				Table[int(PlayerXRow - 1)].insert(int(PlayerXColumn - 1), "X")
				break
			else:
				print("Position already used")
		else:
			print("Position out of range")

def PlayerO():
	while True:
		PlayerORow = int(input("Player O, choose row number: "))
		PlayerOColumn = int(input("Choose column number: "))
		if PlayerORow in range(1, 4) and PlayerOColumn in range(1,4):
			if Table[PlayerORow - 1][PlayerOColumn - 1] == "_":
				Table[int(PlayerORow - 1)].pop(int(PlayerOColumn - 1))
				Table[int(PlayerORow - 1)].insert(int(PlayerOColumn - 1), "O")
				break
			else:
				print("Position already used")
		else:
			print("Position out of range")

os.system('cls')
PrintTable()
while True:
	PlayerX()
	os.system('cls')
	PrintTable()
	for d in range(3):
		for e in range(3):
			if Table[d][e] == "X" and Table[d][e + 1] == "X" and Table[d][e + 2] == "X":
				print("Player X wins!")
				check = False
			elif Table[d + 1][e] == "X" and Table[d + 2][e] == "X" and Table[d][e] == "X":
				print("Player X wins!")
				check = False
			elif Table[d][e] == "X" and Table[d + 1][e + 1] == "X" and Table[d + 2][e + 2] == "X":
				print("Player X wins!")
				check = False
			elif Table[d][e] == "X" and Table[d - 1][e + 1] == "X" and Table[d - 2][e + 2] == "X":
				print("Player X wins!")
				check = False
	if check == False:
		break
	PlayerO()
	os.system('cls')
	PrintTable()
	for f in range(3):
		for g in range(3):
			if Table[f][g] == "O" and Table[f][g + 1] == "O" and Table[f][g + 2] == "O":
				print("Player O wins!")
				check = False
			elif Table[f + 1][g] == "O" and Table[f + 2][g] == "O" and Table[f][g] == "O":
				print("Player O wins!")
				check = False
			elif Table[f][g] == "O" and Table[f + 1][g + 1] == "O" and Table[f + 2][g + 2] == "O":
				print("Player O wins!")
				check = False
			elif Table[f][g] == "O" and Table[f - 1][g + 1] == "O" and Table[f - 2][g + 2] == "O":
				print("Player O wins!")
				check = False
	if check == False:
		break