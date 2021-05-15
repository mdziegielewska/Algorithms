"""
Marta Dzięgielewska
Binary tree - generating, printing, inserting, deleting
26.02.2020
"""

from timeit import default_timer as timer
from numpy.random import randint


class Node:
    def __init__(self, data=None):
        self.data = data
        self.left = None
        self.right = None


def generate(node, N):
    if N == 0:
        node = None
    else:
        node = Node()
        x = randint(0, 100000)
        node.data = int(x)
        generate(node.left, N//2)
        generate(node.right, N - N//2 - 1)


COUNT = [1]


def printtree(root, h):
    if root == None:
        return

    h += COUNT[0]

    printtree(root.right, h)
    for i in range(COUNT[0], h):
        print(end="....")
    print(root.data)
    printtree(root.left, h)


def printbin(root):
    printtree(root, 0)


def insert(node, data):
    if node is None:
        return Node(data)
    else:
        if data < node.data:
            node.left = insert(node.left, data)
            return node
        else:
            if data > node.data:
                node.right = insert(node.right, data)
                return node
            else:
                pass


def minimumnode(node):
    current = node

    while current.left is not None:
        current = current.left
    return current


def delete(root, data):
    if root is None:
        return root

    if data < root.data:
        root.left = delete(root.left, data)

    elif data > root.data:
        root.right = delete(root.right, data)

    else:
        if root.left is None:
            temp = root.right
            root = None
            return temp

        elif root.right is None:
            temp = root.left
            root = None
            return temp

        temp = minimumnode(root.right)
        root.data = temp.data
        root.right = delete(root.right, temp.data)
    return root


root = None
for i in range(20):
    x = randint(0, 1000000)
    root = insert(root, x)
printbin(root)

# 100 ELEMENTÓW

start = timer()
root = None
for i in range(100):
    x = randint(0, 1000000)
    root = insert(root, x)
end = timer()
czas = end - start
print("czas wstawiania 100 losowych elementów wyniósł: ", czas)

start = timer()
root = None
for i in range(100):
    x = randint(0, 1000000)
    root = delete(root, x)
printbin(root)
end = timer()
czas = end - start
print("czas usuwania 100 losowych elementów wyniósł: ", czas)

print()
# 1000 ELEMENTÓW

start = timer()
root = None
for i in range(1000):
    x = randint(0, 1000000)
    root = insert(root, x)
end = timer()
czas = end - start
print("czas wstawiania 1000 losowych elementów wyniósł: ", czas)

start = timer()
root = None
for i in range(1000):
    x = randint(0, 1000000)
    root = delete(root, x)
printbin(root)
end = timer()
czas = end - start
print("czas usuwania 1000 losowych elementów wyniósł: ", czas)

print()
# 10000 ELEMENTÓW

start = timer()
root = None
for i in range(10000):
    x = randint(0, 1000000)
    root = insert(root, x)
end = timer()
czas = end - start
print("czas wstawiania 10000 losowych elementów wyniósł: ", czas)

start = timer()
root = None
for i in range(10000):
    x = randint(0, 1000000)
    root = delete(root, x)
printbin(root)
end = timer()
czas = end - start
print("czas usuwania 10000 losowych elementów wyniósł: ", czas)

print()
#100000 ELEMENTÓW

start = timer()
root = None
for i in range(100000):
    x = randint(0, 1000000)
    root = insert(root, x)
end = timer()
czas = end - start
print("czas wstawiania 100000 losowych elementów wyniósł: ", czas)

start = timer()
root = None
for i in range(100000):
    x = randint(0, 1000000)
    root = delete(root, x)
printbin(root)
end = timer()
czas = end - start
print("czas usuwania 100000 losowych elementów wyniósł: ", czas)