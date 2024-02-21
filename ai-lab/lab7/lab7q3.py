
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
        if (elem[0] >= 0 and elem[1] >= 0):
            temp = mat[:]
            temp[elem[0]][elem[1]], temp[x][y] = temp[x][y], temp[elem[0]][elem[1]]
            children.append(temp)
    return children


mat = [[1,2,3], [0,4,6], [7,5,8]]
for i in genchild(mat):
    print(i)
                