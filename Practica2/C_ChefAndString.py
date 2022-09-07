def answers(string, n):
    L = {}
    for i in range(n):
        for j in range(n-i):
            print("i:", i, "j:", j)
            print(string[i:j+1])
            L[string[i:j+1]] = L.get(string[i:j+1], 1) + 1
    print(L)





#Default code
answers("ababa", 5)

'''
n = int(input())
for i in range(n):
    userInput = input().split()
    positions = KMP(userInput[0], userInput[1])
    if len(positions) == 0:
        print("Not Found")
    else:
        print(len(positions))
        print(*positions, sep=' ')
'''