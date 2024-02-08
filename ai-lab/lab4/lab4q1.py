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
    
    def printList(self):
        for node, list in self.edges:
            print(f"Node {node}: ", end = ' ')
            for neighbor in list:
                print(f"{neighbor  }", end='')
    
    def toposort(self):
        queue = []
        solution = []

        # Source Removal Method
        # searching for nodes w 0 indegree and adding to q
        for node in self.edges.keys():
            if self.indegree[node] == 0:
                queue.append(node)

        # while q is not empty, pop for BFS and then add neighbors into q, check indegree and jazz
        while queue:
            current_node = queue.pop(0)
            solution.append(current_node)

            for neighbor in self.edges[current_node]:
                self.indegree[neighbor] -= 1
                if self.indegree[neighbor] == 0:
                    queue.append(neighbor)
        print(solution)

g = Graph()
g.addNodes([0,1,2,3,4,5])

g.addEdge(3,1)
g.addEdge(2,3)
g.addEdge(5,2)
g.addEdge(5,0)
g.addEdge(4,0)
g.addEdge(4,1)
g.toposort()