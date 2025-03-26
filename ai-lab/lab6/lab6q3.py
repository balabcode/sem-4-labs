import random

def misplaced(mat, ans):
    count = 0
    for i in range(len(mat)):
        for j in range(len(mat)):
            if mat[i][j] != ans[i][j]:
                count += 1
    return count

def find(mat):
    for i in range(len(mat)):
        for j in range(len(mat)):
            if(mat[i][j] == 0):
                return i,j

def genchild(mat):
    x,y = find(mat)
    val = [(x-1, y), (x, y-1), (x+1, y), (x, y+1)]
    children = []
    for elem in val:
        if (len(mat) > elem[0] >= 0 and len(mat) > elem[1] >= 0):
            temp = [row[:] for row in mat]
            temp[elem[0]][elem[1]], temp[x][y] = temp[x][y], temp[elem[0]][elem[1]]
            children.append(temp)
    return children

def hcs(start, end, iter=1000):
    path = [start]
    for i in range(iter):
        mat = path[-1]
        children = genchild(mat)
        children.sort(key= lambda x: misplaced(x, end))
        path.append(children[0])
        if children[0] == end:
            return path
    return path


mat = [[1,2,3], [0,4,6], [7,5,8]]
ans = [[1,2,3], [4,5,6], [7,8,0]]
print(hcs(mat, ans, 100))