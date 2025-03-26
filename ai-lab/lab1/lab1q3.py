def euc(p1,p2):
    dimension = len(p1)
    distance = 0
    for i in range(dimension):
        distance += (p1[i]-p2[i])**2
    return distance

def bubblesort(arr):
    n = len(arr)
    for i in range(n-1):
        for j in range(n-1-i):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

x = [(1,2),(3,4)]
y = [(9,8),(7,6)]

outlist = []
for i in range(len(x)):
    outlist.append(euc(x[i],y[i]))

bubblesort(outlist)
print(outlist)
