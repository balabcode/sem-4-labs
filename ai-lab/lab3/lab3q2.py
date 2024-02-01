from collections import defaultdict

class Graph:
    def __init__(self, vertices):
        self.graph = defaultdict(list)
        self.vertices = vertices

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def isCyclicUtil(self, v, visited, recStack, cycle):
        visited[v] = True
        recStack[v] = True

        for neighbor in self.graph[v]:
            if not visited[neighbor]:
                if self.isCyclicUtil(neighbor, visited, recStack, cycle):
                    cycle.append(neighbor)
                    return True
            elif recStack[neighbor]:
                cycle.append(neighbor)
                return True

        recStack[v] = False
        return False

    def isCyclic(self):
        visited = [False] * self.vertices
        recStack = [False] * self.vertices
        cycles = []

        for node in range(self.vertices):
            if not visited[node]:
                cycle = []
                if self.isCyclicUtil(node, visited, recStack, cycle):
                    cycle.append(node)
                    cycles.append(cycle)

        if cycles:
            for cycle in cycles:
                print("Cycle:", end=" ")
                for node in cycle:
                    print(node, end=" ")
                print()
            return True
        else:
            return False

g = Graph(4)
g.addEdge(0, 1)
g.addEdge(1, 2)
g.addEdge(0, 2)
g.addEdge(2, 0)
g.addEdge(2, 3)
g.addEdge(3, 3)

g.isCyclic()

# class Graph:
#     def __init__(self):
#         self.edges = {}
#         self.color = {}

#     def addNodes(self, nodes):
#         for node in nodes:
#             self.edges[node] = []
#             self.color[node] = 'W'

#     def addEdge(self, node1, node2):
#         self.edges[node1].append(node2)

#     def cyclic(self, u, visited, cycle_nodes):
#         if u in cycle_nodes:
#             cycle_nodes.append(u)
#             print(cycle_nodes[cycle_nodes.index(u):])
#             return
#         cycle_nodes.append(u)
#         for v in self.edges[u]:
#             if v not in visited or v != cycle_nodes[-2]:
#                 self.cyclic(v, visited, cycle_nodes)
#         cycle_nodes.pop()

#     def findCycles(self):
#         for u in self.edges.keys():
#             visited = set()
#             cycle_nodes = []
#             self.cyclic(u, visited, cycle_nodes)

#     def resetGraph(self):
#         for u in self.edges.keys():
#             self.color[u] = 'W'

# g = Graph()
# g.addNodes([0, 1, 2, 3])
# g.addEdge(0, 1)
# g.addEdge(1, 2)
# g.addEdge(0, 2)
# g.addEdge(2, 0)
# g.addEdge(2, 3)
# g.addEdge(3, 3)

# g.findCycles()



# class Graph:
#     def __init__(self):
#         self.edges = {}
#         self.color = {}

#     def addNodes(self, nodes):
#         for node in nodes:
#             self.edges[node] = []
#             self.color[node] = 'W'

#     def addEdge(self, node1, node2):
#         self.edges[node1].append(node2)
    
#     def printList(self):
#         for node in self.edges:
#             print(f"Vertex {node}: {self.edges[node]}")
    
#     def cyclic(self, u, color, cycle_nodes):
#         self.color[u] = 'G'
#         cycle_nodes.append(u)

#         for v in self.edges[u]:
#             if self.color[v] == 'W':
#                 self.cyclic(v, self.color, cycle_nodes)
#             elif self.color[v] == 'G' and v in cycle_nodes and (len(cycle_nodes) == 2 or v != cycle_nodes[-2]):
#                 index = cycle_nodes.index(v)
#                 print(f"Cycle Found: {cycle_nodes[index:]}")

#         self.color[u] = 'B'
#         cycle_nodes.pop()

#     def findCycles(self):
#         for u in self.edges.keys():
#             if self.color[u] == 'W':
#                 cycle_nodes = []
#                 self.cyclic(u, self.color, cycle_nodes)
    
#     def resetGraph(self):
#         for u in self.edges.keys():
#             self.color[u] = 'W'

# g = Graph()
# g.addNodes([0,1,2,3])
# g.addEdge(0,1)
# g.addEdge(1,2)
# g.addEdge(0,2)
# g.addEdge(2,0)
# g.addEdge(2,3)
# g.addEdge(3,3)

# g.findCycles()