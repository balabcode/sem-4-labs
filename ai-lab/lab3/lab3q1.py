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

g.addNodes([0,1,2,3])

g.addEdge(0,1)
g.addEdge(0,2)
g.addEdge(1,2)
g.addEdge(2,0)
g.addEdge(2,3)
g.addEdge(3,3)

g.printList()
