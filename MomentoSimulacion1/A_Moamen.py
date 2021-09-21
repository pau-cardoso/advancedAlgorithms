# Paulina Cardoso - A01701490
def moamen(n, k, array):
    sortedArray = sorted(array)
    subarrays = 0
    nextOrdered = {}
    for i in range(n-1):
        nextOrdered[sortedArray[i]] = sortedArray[i+1]

    for i in range(n):
        if i == n-1:
            subarrays += 1
            break
        if nextOrdered.get(array[i]) != array[i+1]:
            subarrays += 1
        
    if subarrays > k:
        return "NO"
    else:
        return "YES"


# Default code
n = input()
for i in range(int(n)):
    variables = input().split()
    n = int(variables[0])
    k = int(variables[1])
    array = input().split()
    array = [int(i) for i in array]
    print(moamen(n, k, array))