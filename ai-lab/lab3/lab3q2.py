class Graph:
    def __init__(self):
        self.edges = {}
        self.indegree = {}

    def addNodes(self, nodes):
        for node in nodes:
            self.edges[node] = []
            self.indegree[node] = 0

    def addEdge(self, node1, node2):
        self.edges[node1].append(node2)
        self.indegree[node2] += 1

    def getSub(self, node):
        return self.edges[node]
    
    def printList(self):
        for node in self.edges:
            print(f"Vertex {node}: {self.edges[node]}")
    
    def cyclicDFS(self):
        visited = {}
        visited_rec = {}
        for key in self.edges:
            visited[key] = False
            visited_rec[key] = False

        for key in self.edges.keys():
            for sub in self.getSub(key):
                

        

    

