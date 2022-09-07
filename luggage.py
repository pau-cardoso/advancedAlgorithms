def knapsackAlgorithm(w, sum):
    n = len(w)
    m = sum/2
    matrix = [[0 for x in range(n)] for y in range(m)] 

    for i in range(1, n):
        for j in range(1,m+1):
            if j < w[i]:
                matrix[i][j] = matrix[i-1][j]
            else:
                matrix[i][j] = max(w[i]+matrix[i-1][j-w[i]], matrix[i-1][j-w[i]])
    
    if matrix[n-1][m] == (sum/2):
        return True
    return False

testCases = input()
for input in range(int(testCases)):
    weights = input().split()
    weights = [int(i) for i in weights]
    sumWeights = sum(weights)

if(sum%2 == 0):
    if knapsackAlgorithm(weights, sumWeights):
        print("YES")
    else: print("NO")
else: print("NO")

