# travelling salesman using BFS
class Graph:
    def __init__(self):
        self.edges = {}
    def addNodes(self, nodes):
        for node in nodes:
            self.edges[node] = {}
    def addEdge(self, node1, node2, weight = 1):
        self.edges[node1][node2] = weight
    def printList(self):
        for node, sub in self.edges.items():
            print(f"Node {node}: ", end = ' ')
            for neighbor, weight in sub.items():
                print(f"{neighbor}: {weight}  ", end='')
            print()
    def travellingSalesman(self, start):
        queue = [(start, [start], 0)]
        min_cost = float('inf')  # max integer
        min_path = []

        while queue:
            curr, path, cost = queue.pop(0)
            if len(path) == len(self.edges) and self.edges[curr][start] != 0:
                cost += self.edges[curr][start]
                if cost < min_cost:
                    min_cost = cost
                    min_path = path + [start]
            for neighbor in self.edges[curr]:
                if neighbor not in path and self.edges[curr][neighbor] != 0:
                    queue.append((neighbor, path + [neighbor], cost + self.edges[curr][neighbor]))
        print(f"Minimum Path: {min_path}\nMininum Cost:{min_cost}\n")

        return min_path, min_cost

g = Graph()
g.edges = {
    'A': {'B': 2, 'C': 3, 'D': 1},
    'B': {'A': 2, 'C': 4, 'D': 2},
    'C': {'A': 3, 'B': 4, 'D': 3},
    'D': {'A': 1, 'B': 2, 'C': 3}
}

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
# def BFS(self, start):
#         queue = [start]
#         path = []
#         visited = set(start)
#         while queue:
#             current = queue.pop(0)
#             path.append(current)
#             for neighbor in self.edges[current]:
#                 if(neighbor not in visited):
#                     visited.add(neighbor)
#                     queue.append(neighbor)
#         print(path)
#         return path
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