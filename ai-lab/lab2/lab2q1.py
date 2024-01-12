# Implement the following directed unweighted graph using class, methods, and data structures of Python.

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)]
                            for row in range(vertices)]

    def printAdjMat(self):
        print("\nAdjacency Matrix:")
        for i in range(self.V):
            for j in range(self.V):
                print(f"{self.graph[i][j]}", end = " ")
            print()
    
    def addEdgeDirected(self, v, w):
        print(f"Adding an directed edge between {v} and {w}")
        self.graph[v][w] = 1

    def printAdjList(self):
        c = 0
        print('\nAdjacency List:')
        for row in self.graph:
            # print(f"{c+1}: ", end = '  ')
            for index,val in enumerate(row):
                if(val != 0):
                    print(f"({c} -> {index})", end = ' ')
            c+=1
            print()
 
g = Graph(6)
g.addEdgeDirected(0,1)
g.addEdgeDirected(1,2)
g.addEdgeDirected(2,1)
g.addEdgeDirected(3,2)
g.addEdgeDirected(2,0)
g.addEdgeDirected(4,5)
g.addEdgeDirected(5,4)


# g.printAdjMat()
g.printAdjList()