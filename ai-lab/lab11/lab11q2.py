# Write a Python program to find all possible solution for 8 queens problem using Breadth First Search algorithm.
import random

def gen_board(size=8):
    x = [i for i in range(size)]
    random.shuffle(x)
    return tuple(x)


def calc_attacks(board):
    attacks = 0
    size = len(board)
    for i in range(size):
        for j in range(i + 1, size):
            if board[i] == board[j] or abs(board[i] - board[j]) == j - i:
                attacks += 1
    return attacks

def gen_neigh(board):
    size = len(board)
    neigh = []
    for i in range(size):
        for j in range(size):
            if j != board[i]:
                neigh_board = list(board).copy()
                neigh_board[i] = j
                neigh.append(tuple(neigh_board))
    return neigh

def bfs():
    visited = set()
    q = [gen_board()]
    visited.add(q[0])

    while q:
        curr_board = q.pop(0)
        if calc_attacks(curr_board) == 0:
            return curr_board
        neighbours = gen_neigh(curr_board)
        for n in neighbours:
            if n not in visited:
                visited.add(n)
                q.append(n)
    return None

print(bfs())