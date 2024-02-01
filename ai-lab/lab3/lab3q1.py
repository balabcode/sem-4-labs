class Graph:
    def __init__(self):
        self.edges = {}

    def addNodes(self, nodes):
        for node in nodes:
            self.edges[node] = []

    def addEdge(self, node1, node2):
        self.edges[node1].append(node2)

    def getSub(self, node):
        return self.edges[node]

    def toposort(self):
        vis={}
        for c in self.edges.keys():
            vis[c]=False
        stack=[]
        for d in self.edges.keys():
            if not vis[d]:
                self.dfs(d,vis,stack)
        return stack[::-1]

    def dfs(self,v,vis,stack):
        vis[v]=True
        for d in self.edges[v]:
            if not vis[d]:
                self.dfs(d,vis,stack)
        stack.append(v)

    def printList(self):
        for node in self.edges:
            print(f"Vertex {node}: {self.edges[node]}")

g = Graph()

g.addNodes([0,1,2,3,4,5])

g.addEdge(3,1)
g.addEdge(2,3)
g.addEdge(5,2)
g.addEdge(5,0)
g.addEdge(4,0)
g.addEdge(4,1)

print(g.toposort())

g.printList()
