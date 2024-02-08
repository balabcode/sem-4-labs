# travelling salesman - UNWEIGHTED????? IDK BRO

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
        for node, neighbors in self.edges.items():
            print(f"Node {node}: ", end=' ')
            for neighbor in neighbors:
                print(f"{neighbor}", end=' ')
            print()
    
    def travellingSalesman(self, start):
        queue = [start]
        path = []
        visited = set(start)
        while queue:
            current = queue.pop(0)
            path.append(current)
            for neighbor in self.edges[current]:
                if(neighbor not in visited):
                    visited.add(neighbor)
                    queue.append(neighbor)
        print(path)
        return path

g = Graph()
g.addNodes(['A', 'B', 'C', 'D'])
g.addEdge('A','B')
g.addEdge('A','C')
g.addEdge('A','D')
g.addEdge('B','A')
g.addEdge('B','C')
g.addEdge('B','D')
g.addEdge('C','A')
g.addEdge('C','B')
g.addEdge('C','D')
g.addEdge('D','A')
g.addEdge('D','B')
g.addEdge('D','C')
g.printList()


g.travellingSalesman('A')







# class Graph:
#     def __init__(self):
#         self.edges = {}
#         self.indegree = {}
    
#     def addNodes(self, nodes):
#         for node in nodes:
#             self.edges[node] = []
#             self.indegree[node] = 0
    
#     def addEdge(self, node1, node2, weight):
#         self.edges[node1].append((node2,weight))
#         self.indegree[node2] += 1
    
#     def printList(self):
#         for node, list in self.edges.items():
#             print(f"Node {node}: ", end = ' ')
#             for neighbor, weight in list:
#                 print(f"{neighbor}: {weight}  ", end='')
#             print()
# g = Graph()
# g.addNodes(['A', 'B', 'C', 'D'])
# g.addEdge('A','B',2)
# g.addEdge('A','C',3)
# g.addEdge('A','D',1)
# g.addEdge('B','A',2)
# g.addEdge('B','C',4)
# g.addEdge('B','D',2)
# g.addEdge('C','A',3)
# g.addEdge('C','B',4)
# g.addEdge('C','D',3)
# g.addEdge('D','A',1)
# g.addEdge('D','B',2)
# g.addEdge('D','C',3)

# g.printList()
    