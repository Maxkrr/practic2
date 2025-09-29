# Хэш - таблицы:
class HashTable:
    def __init__(self, size=10):
        self.size = size
        self.table = [[] for _ in range(size)]

    def hash_function(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        index = self.hash_function(key)
        for kvp in self.table[index]:
            if kvp[0] == key:
                kvp[1] = value
                return
        self.table[index].append([key, value])

    def search(self, key):
        index = self.hash_function(key)
        for kvp in self.table[index]:
            if kvp[0] == key:
                return kvp[1]
        return None

    def delete(self, key):
        index = self.hash_function(key)
        for i, kvp in enumerate(self.table[index]):
            if kvp[0] == key:
                del self.table[index][i]
                return

# Пример использования
ht = HashTable()
ht.insert('apple', 5)
print(ht.search('apple'))  # 5
ht.delete('apple')
print(ht.search('apple'))  # None
# Куча Фибоначчи:
class Node:
    def __init__(self, key):
        self.key = key
        self.left = self.right = self
        self.child = self.parent = None
        self.degree = 0

class FibHeap:
    def __init__(self):
        self.min = None

    def insert(self, x):
        if not self.min:
            self.min = x
        else:
            x.left, x.right = self.min, self.min.right
            self.min.right.left = x
            self.min.right = x
            if x.key < self.min.key:
                self.min = x

    def extract_min(self):
        z = self.min
        if z:
            if z.child:
                c = z.child
                children = []
                while True:
                    children.append(c)
                    c = c.right
                    if c == z.child:
                        break
                for child in children:
                    child.parent = None
                    child.left.right = child.right
                    child.right.left = child.left
                    child.left = self.min
                    child.right = self.min.right
                    self.min.right.left = child
                    self.min.right = child
            z.left.right = z.right
            z.right.left = z.left
            self.min = z.right if z != z.right else None
        return z.key if z else None
        
