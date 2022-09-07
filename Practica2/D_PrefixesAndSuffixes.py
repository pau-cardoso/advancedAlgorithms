def timesRepeated(string, n):
    countRepetitions = [0]*n
    countRepetitions[0] = 0
    l, r = 0, 0

    for i in range(1,n):
        if i >= 1 and i <= r:
            countRepetitions.append(min(countRepetitions[i-l], r-i+1))
        
        while i+countRepetitions[i]<n and string[countRepetitions[i]]==string[i+countRepetitions[i]]:
            countRepetitions[i] += 1

        if i+countRepetitions[i]-1<n and i+countRepetitions[i]-1>r:
            l = i
            r = i + countRepetitions[i] - 1
    
    return countRepetitions;

def prefixSuffix(string):
    n = len(string)
    repetitions = timesRepeated(string, n)
    prefSuf = [False]*n
    res = 0;

    for i in range(n):
        if i+repetitions[i] == n:
            res += 1
            prefSuf[repetitions[i]] = True
    
    counterPrefixes = [0]*(n+1)
    for i in range(n):
        counterPrefixes[repetitions[i]] += 1

    for i in range(n-1, -1, -1):
        counterPrefixes[i] += counterPrefixes[i+1]
    
    print(res)

    for i in range(1, n+1):
        if prefSuf[i-1] == True:
            print(i, counterPrefixes[i-1])



# Default code
string = input()
prefixSuffix(string)