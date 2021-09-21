class Node:
    def __init__(self, info): 
        self.info = info  
        self.left = None  
        self.right = None 
        self.level = None 

    def __str__(self):
        return str(self.info) 

class BinarySearchTree:
    def __init__(self): 
        self.root = None

    def create(self, val):  
        if self.root == None:
            self.root = Node(val)
        else:
            current = self.root
         
            while True:
                if val < current.info:
                    if current.left:
                        current = current.left
                    else:
                        current.left = Node(val)
                        break
                elif val > current.info:
                    if current.right:
                        current = current.right
                    else:
                        current.right = Node(val)
                        break
                else:
                    break

"""
Node is defined as
self.left (the left child of the node)
self.right (the right child of the node)
self.info (the value of the node)
"""
s = ""

def topLeft(node):
    global s
    if node == None: 
        return
    else:
        topLeft(node.left)
        s += str(node.info) + " "

def topRight(node):
    global s
    if node == None: 
        return
    else:
        s += str(node.info) + " "
        topRight(node.right)

def topView(root):
    #Write your code here
    global s
    topLeft(root)
    topRight(root.right)
    print(s)
    

# Default code
tree = BinarySearchTree()
t = int(input())

arr = list(map(int, input().split()))

for i in range(t):
    tree.create(arr[i])

topView(tree.root)