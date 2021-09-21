class Node:
    def __init__(self, data): 
        self.data = data  
        self.left = None  
        self.right = None 
        self.level = None 

    def __str__(self):
        return str(self.data) 

class BinarySearchTree:
    def __init__(self): 
        self.root = None

    def create(self, val):  
        if self.root == None:
            self.root = Node(val)
        else:
            current = self.root
         
            while True:
                if val < current.data:
                    if current.left:
                        current = current.left
                    else:
                        current.left = Node(val)
                        break
                elif val > current.data:
                    if current.right:
                        current = current.right
                    else:
                        current.right = Node(val)
                        break
                else:
                    break


def helperLeft(node, rootValue):
    queue = []
    queue.append(node)
    flag = True

    while len(queue) != 0:
        node = queue.pop(0)

        if node.left:
            if node.left.data > node.data and node.left.data > rootValue:
                flag = False
                break
            queue.append(node.left)
        if node.right:
            if node.right.data < node.data and node.right.data > rootValue:
                flag = False
                break
            queue.append(node.right)
    return flag


def helperRight(node, rootValue):
    queue = []
    queue.append(node)
    flag = True

    while len(queue) != 0:
        node = queue.pop(0)

        if node.left:
            if node.left.data > node.data and node.left.data < rootValue:
                flag = False
                break
            queue.append(node.left)
        if node.right:
            if node.right.data < node.data and node.right.data < rootValue:
                flag = False
                break
            queue.append(node.right)
    return flag

def check_binary_search_tree_(root):
    answerLeft, answerRight = True, True

    if root.left:
        answerLeft = helperLeft(root.left, root.data)

    if root.right:
        answerRight = helperRight(root.right, root.data)

    if answerRight == False or answerLeft == False:
        return False
    else:
        return True


# Default code
tree = BinarySearchTree()
t = int(input())

arr = list(map(int, input().split()))

for i in range(t):
    tree.create(arr[i])

print(check_binary_search_tree_(tree.root))