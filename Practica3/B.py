from collections import defaultdict

# A recursive function used by topologicalSort
def topologicalSortUtil(graph, v, visited, stack):

    # Mark the current node as visited.
    visited[v] = True

    # Recur for all the vertices adjacent to this vertex
    for i in graph[v]:
        if visited[i] == False:
            topologicalSortUtil(graph, i, visited, stack)

    # Push current vertex to stack which stores result
    stack.append(v)

# The function to do Topological Sort. It uses recursive
# topologicalSortUtil()
def topologicalSort(graph, n):
    # Mark all the vertices as not visited
    visited = [False]*n
    stack = []

    # Call the recursive helper function to store Topological
    # Sort starting from all vertices one by one
    for i in range(n):
        if visited[i] == False:
            topologicalSortUtil(graph, i, visited, stack)

    # Print contents of the stack
    print(stack[::-1])  # return list in reverse order

# Default code
nm = input().split()
n = int(nm[0])
m = int(nm[1])

graph = defaultdict(list)

for i in range(m):
    uv = input().split()
    u = uv[0]
    v = uv[1]
    graph[u].append(v)

print(graph)
topologicalSort(graph, n)