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
                    queue.sort(key=lambda a: a[2])
        
        print(f"Minimum Path: {min_path}\nMinimum Cost: {min_cost}\n")
        return min_path, min_cost


g = Graph()
g.addNodes(['S', '1', '2', '3', '4', '5', 'G'])
g.addEdge('S', '1', 2)
g.addEdge('S', '3', 5)
g.addEdge('3', '1', 5)
g.addEdge('3', 'G', 6)
g.addEdge('1', 'G', 1)
g.addEdge('3', '4', 2)
g.addEdge('G', '4', 7)
g.addEdge('4', '5', 3)
g.addEdge('4', '2', 4)
g.addEdge('5', 'G', 3)
g.addEdge('2', '1', 4)
g.addEdge('5', '2', 6)

g.uniformCostSearch('S', 'G')