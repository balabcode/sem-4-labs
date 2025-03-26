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
        
        print(f"Minimum Path: {min_path}\nMinimum Cost: {min_cost}\n")
        return min_path, min_cost

g = Graph()
g.addNodes(['D', 'B', 'H', 'F', 'T', 'C', 'M'])
g.addEdge('D', 'B', 17)
g.addEdge('B', 'D', 15)
g.addEdge('H', 'D', 53)
g.addEdge('H', 'B', 40)
g.addEdge('F', 'B', 46)
g.addEdge('T', 'F', 3)
g.addEdge('H', 'T', 31)
g.addEdge('C', 'H', 17)
g.addEdge('T', 'C', 29)
g.addEdge('F', 'M', 11)
g.addEdge('M', 'T', 8)
g.addEdge('C', 'M', 40)

g.uniformCostSearch('M', 'D')