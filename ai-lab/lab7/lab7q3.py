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
        if 0 <= elem[0] < len(mat) and 0 <= elem[1] < len(mat[0]):
            temp = [row[:] for row in mat]
            temp[elem[0]][elem[1]], temp[x][y] = temp[x][y], temp[elem[0]][elem[1]]
            children.append(temp)
    return children

def heu(mat, ans):
    count = 0
    for i in range(len(mat)):
        for j in range(len(mat)):
            if mat[i][j] != ans[i][j]:
                count += 1
    return count

def aStar(start, end):
    q = [(heu(start, end), start, [start], 0)]  # [heucost, node, [path], numMoves]        
    while q:
        q.sort(key = lambda x: (x[0], x[3]))
        curr = q.pop(0)
        if(curr[1] == end):
            return curr
        for neighbor in genchild(curr[1]):
            if neighbor not in curr[2]:
                q.append((curr[0] + heu(neighbor, end),
                        neighbor,
                        curr[2] + [neighbor],
                        curr[3] + 1))

mat = [[1,2,3], [0,4,6], [7,5,8]]
# mat = [[1,2,3], [8,0,4], [7,6,5]]
# mat = [[2,8,3], [1,6,4], [7,0,5]]
# mat = [[2,8,1], [0,4,3], [7,6,5]]
ans = [[1,2,3], [4,5,6], [7,8,0]]
print(aStar(mat, ans))