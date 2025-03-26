import random

def f(x):
    return x**2 + x**3

def hcs(func = f, bound = (-10, 10), step = 0.1, iter = 1000):
    ans = [0,0]
    for i in range(iter):
        x = random.randint(bound[0], bound[1])
        while True:
            x1, x2 = max(x-step, bound[0]), min(x+step, bound[1])
            tempMax = max(func(x), func(x1), func(x2))
            if tempMax == func(x):
                ans[0] = round(max(ans[0], func(x)), 3)
                if(ans[0] == func(x)):
                    ans[1] = x
                break
            if tempMax == func(x2):
                x = x2
            else:
                x = x1
    return ans

print(hcs())