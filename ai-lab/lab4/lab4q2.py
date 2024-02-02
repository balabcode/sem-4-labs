# Consider the following directed graph for detecting cycles in the graph using BFS
# algorithm using Python.
from collections import deque
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


def find_cycles(graph):
    cycles = []
    visited = set()

    for node in graph:
        if node not in visited:
            bfs_queue = deque([(node, [])])

            while bfs_queue:
                current_node, current_path = bfs_queue.popleft()

                if current_node in visited:
                    cycle = current_path + [current_node]
                    cycles.append(cycle)
                    continue

                visited.add(current_node)

                for neighbor in graph[current_node]:
                    bfs_queue.append((neighbor, current_path + [current_node]))

    return cycles


g = Graph()
g.addNodes([0, 1, 2, 3])
g.addEdge(0, 1)
g.addEdge(1, 2)
g.addEdge(0, 2)
g.addEdge(2, 0)
g.addEdge(2, 3)
g.addEdge(3, 3)

print(find_cycles(g.edges))
