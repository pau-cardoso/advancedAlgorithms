def caninePoetry(poem, n):
    count = 0
    poem = list(poem)
    for i in range(n):
        if i+1<n and poem[i]==poem[i+1] and poem[i]!='|':
            count += 1
            poem[i+1] = '|'
        if i+2<n and poem[i]==poem[i+2] and poem[i]!='|':
            count += 1
            poem[i+2] = '|'
    print(count)

# Default code
testCases = int(input())
for i in range(testCases):
    poem = input()
    n = len(poem)
    caninePoetry(poem, n)
 