def risk(string):
	prev = string[0]
	cont = 1
	for i in range(1, len(string)):
		letter = string[i]
		if letter == prev:
			cont += 1
		else:
			cont = 1
			prev = letter
		if cont >= 7:
			return "YES"
	return "NO"


positions = input()
print(risk(positions))