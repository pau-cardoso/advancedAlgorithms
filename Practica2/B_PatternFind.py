def prefixArray(pattern, n):
    length = 0
    prefixArray = [0]
    i = 1
    while i < n:
        if pattern[i] == pattern[length]:
            length += 1
            prefixArray.append(length)
        else:
            if length != 0:
                length = prefixArray[length-1]
                i -= 1
            else:
                prefixArray.append(0)
        i += 1
    print(prefixArray)
    return prefixArray


def KMP(message, pattern):
    n, m = len(message), len(pattern)
    prefArray = prefixArray(pattern, m)
    positions = []
    
    i, j = 0, 0
    while i < n:
        if message[i] == pattern[j]:
            i += 1
            j += 1
        else:
            if j != 0:
                j = prefArray[j-1]
            else: 
                i += 1
        if j == m:
            positions.append(i-j+1)
            j = prefArray[j-1]
    
    return positions


# Default code
n = int(input())
for i in range(n):
    userInput = input().split()
    positions = KMP(userInput[0], userInput[1])
    if len(positions) == 0:
        print("Not Found")
    else:
        print(len(positions))
        print(*positions, sep=' ')