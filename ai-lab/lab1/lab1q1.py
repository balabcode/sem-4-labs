class Queue():
    def __init__(self):
        self.instack = []
        self.outstack = []
    
    def enqueue(self, x):
        self.instack.append(x)
    def dequeue(self):
        if (len(self.outstack) == 0):
            while(len(self.instack) > 0):
                self.outstack.append(self.instack.pop())
        x = self.outstack.pop()
        while(len(self.outstack) > 0):
            self.instack.append(self.outstack.pop())
        return x
op = 1
q = Queue()
while(op != 0):
    op = int(input('Enter 1 to push, 2 to pop, 3 to display, and 0 to exit: '))
    if (op == 1):
        x = int(input('Enter a number: '))
        q.enqueue(x)
    elif (op == 2):
        print(q.dequeue())
    elif (op == 3):
        for elem in q.instack:
            print(elem)
    else:
        exit()