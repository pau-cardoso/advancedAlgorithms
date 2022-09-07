def sameWeight(weights):
    currentWeight = 0
    totalWeights = sum(weights)
    limit = totalWeights/2

    for w in weights:
        if currentWeight+w <= limit:
            currentWeight += w
        if limit == currentWeight:
            return "YES"

    return "NO"


# Default code
n = int(input())
for i in range(n):
    weights = input().split()
    weights = [int(i) for i in weights]
    weights.sort(reverse=True)
    print(sameWeight(weights))