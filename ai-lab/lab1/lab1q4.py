class Node:

    def __init__(self, data):
        self.data = data
        self.llink = None
        self.rlink = None

def create_bst(inp):

    head = None

    for i in inp:

        i = int(i)
        node = Node(i)

        if(head==None):
            head = node

        else:

            curr = head
            prev = head

            flag = False

            while(curr!=None):
                prev = curr

                if(i>curr.data):
                    curr = curr.rlink
                elif(i<curr.data):
                    curr = curr.llink
                else:
                    flag = True
                    break

            if(flag):
                continue

            if(i>prev.data):
                prev.rlink = node
            else:
                prev.llink = node

    return head

def inorder(head):
    if(head==None):
        return
    inorder(head.llink)
    print(head.data,end=",")
    inorder(head.rlink)

def preorder(head):
    if(head==None):
        return
    print(head.data,end=",")
    preorder(head.llink)
    preorder(head.rlink)

def postorder(head):
    if(head==None):
        return
    postorder(head.llink)
    postorder(head.rlink)
    print(head.data,end=",")

def main():

    print("Enter tree:")
    inp = input().split()

    head = create_bst(inp)

    print("Inorder: ",end="")
    inorder(head)

    print("\nPreorder: ",end="")
    preorder(head)

    print("\nPostorder: ",end="")
    postorder(head)

    print("\n")

if __name__ == "__main__":
    main()