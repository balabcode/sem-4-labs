# Implement the following directed weighted graph using class, methods, and data structures of Python.

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
    
    def addEdgeDirected(self, v, w, weight):
        print(f"Adding an directed edge between {v} and {w}")
        self.graph[v][w] = weight

    def printAdjList(self):
        c = 0
        print('\nAdjacency List:')
        for row in self.graph:
            # print(f"{c}: ", end = '  ')
            for index,val in enumerate(row):
                if(val != 0):
                    print(f"({c} -> {index},{val})", end = ' ')
            c+=1
            print()
 
g = Graph(6)
g.addEdgeDirected(0,1,6)
g.addEdgeDirected(1,2,7)
g.addEdgeDirected(2,1,4)
g.addEdgeDirected(3,2,10)
g.addEdgeDirected(2,0,5)
g.addEdgeDirected(4,5,1)
g.addEdgeDirected(5,4,3)


# g.printAdjMat()
g.printAdjList()