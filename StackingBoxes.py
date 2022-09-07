
# cambiar xd
def DFS(vertex, graph, reached, stack):
    reached[vertex] = 1
    for node in graph:
        if node[0] == vertex and reached[node[1]] == 0:
            DFS(node[1], graph, reached, stack)
    stack.append(vertex)
    return stack
    

def topologicalSort(graph, reached, stack):
    for vertex in graph:
        if(vertex == 0):
            stack = DFS(vertex, graph, reached, stack)
    return stack
# cambiar xd




# Funcion para saber si la caja A cabe en la caja B
def canFitBox(boxA, boxB):
    for i in range(len(boxA)):
        if (boxA[i] >= boxB[i]): 
            return False
    return True

# Creacion del grafo
def createGraph(boxes, k):
    graph = []

    for i in range(k):
        row =[]
        for j in range(k):
            if i == j :
                continue
            if canFitBox(boxes[i], boxes[j]):
                row.append(1)
            else:
                row.append(0)
        row.append(1)
        graph.append(row)

    start = [1]*k
    graph.insert(0, start)

    return graph



def stackingBoxes(k, n, boxes):
    # Ordena las cajas por dimensiones de mas chica a mas grande
    for box in boxes:
        box.sort(reverse = True)
    
    # Crea el grafo
    graph = createGraph(boxes, k)
    print("Graph:")
    for row in graph:
        print(row)
    


# Default code 
userInput = input()
while userInput:
    k, n = int(userInput.split()[0]), int(userInput.split()[1])
    boxes = []

    for i in range(k):
        dimensions = input().split()
        box = []
        for dimension in dimensions:
            box.append(int(dimension))
        boxes.append(box)
    print("Boxes:", boxes)
    stackingBoxes(k, n, boxes)
    userInput = input()

