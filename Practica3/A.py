from collections import defaultdict

def topologicalSort(graph, n):
    employeeRank = [0]*n

    for node in graph:
        for child in graph[node]:
            employeeRank[child] += 1
    print("EmployeeRank:", employeeRank)

    queue = []
    for i in range(n):
        if employeeRank[i] == 0:
            queue.append(i)
    
    count = 0
    orderedResult = []

    while queue:
        u = queue.pop(0)
        print("u", u)
        orderedResult.append(u)

        for i in graph[u]:
            employeeRank[i] -= 1
            if employeeRank[i] == 0:
                queue.append(i)
        
        count += 1

    if count != n:
        print(-1)
    else: 
        print(orderedResult)


# Default code
nr = input().split()
n = int(nr[0]) # Numero de empleados
r = int(nr[1]) # Numero de relaciones

graph = defaultdict(list)

for i in range(r):
    uv = input().split()
    u = int(uv[0])
    v = int(uv[1])
    graph[u].append(v)

print(graph)
topologicalSort(graph, n)