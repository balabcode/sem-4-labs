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
                print(f"{neighbor}:{weight}     ", end='')
            print()
    def uniformCostSearch(self, start, goal):
        queue = [(start, [start], 0)]
        min_cost = float('inf')
        min_path = []

        while queue:
            curr, path, cost = queue.pop(0)
            if curr == goal:
                if cost < min_cost:
                    min_cost = cost
                    min_path = path
            for neighbor in self.edges[curr]:
                if neighbor not in path and self.edges[curr][neighbor] != 0:
                    queue.append((neighbor, path + [neighbor], cost + self.edges[curr][neighbor]))
        
        # print(f"Minimum Path: {min_path}\nMinimum Cost: {min_cost}\n")
        return min_path, min_cost


g = Graph()
g.addNodes(['S', 'A', 'B', 'C', 'D', 'E', 'F', 'G1', 'G2', 'G3'])
g.addEdge('S', 'A', 5)
g.addEdge('S', 'B', 9)
g.addEdge('C', 'S', 6)
g.addEdge('S', 'D', 6)
g.addEdge('A', 'B', 3)
g.addEdge('B', 'A', 3)
g.addEdge('B', 'C', 1)
g.addEdge('D', 'C', 2)
g.addEdge('D', 'E', 2)
g.addEdge('E', 'G3', 7)
g.addEdge('F', 'G3', 8)
g.addEdge('F', 'D', 2)
g.addEdge('C', 'F', 7)
g.addEdge('C', 'G2', 5)
g.addEdge('A', 'G1', 9)

goal = ['G1', 'G2', 'G3']
min_cost = float('inf')
for node in goal:
    path, cost = g.uniformCostSearch('S', node)
    if cost < min_cost:
        min_cost, min_path = cost, path
print(f"Minimum Path: {min_path}\nMinimum Cost: {min_cost}\n")