# Implement the following undirected weighted graph using class, methods, and data structures of Python.
# Print the adjacency list and adjacency matrix.

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.alphabet = ['A','B','C','D','E']
        self.graph = [[0 for column in range(vertices)]
                            for row in range(vertices)]

    def printAdjMat(self):
        print("\nAdjacency Matrix:")
        for i in range(self.V):
            for j in range(self.V):
                print(f"{self.graph[i][j]}", end = " ")
            print()
    
    def addEdgeUndirected(self, v, w, weight=1):
        print(f"Adding an directed edge between {self.alphabet[v]} and {self.alphabet[w]}")
        self.graph[v][w] = weight
        self.graph[w][v] = weight

    def printAdjList(self):
        c = 0
        print('\nAdjacency List:')
        for row in self.graph:
            print(f"{self.alphabet[c]}: [", end = '')
            for index,val in enumerate(row):
                if(val != 0):
                    print(f"{self.alphabet[index]}", end = ',')
            c+=1
            print(']')


g = Graph(5)
g.addEdgeUndirected(0,2)
g.addEdgeUndirected(0,1)
g.addEdgeUndirected(1,2)
g.addEdgeUndirected(0,4)
g.addEdgeUndirected(2,4)
g.addEdgeUndirected(2,3)


g.printAdjList()
g.printAdjMat()