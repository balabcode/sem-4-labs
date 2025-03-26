#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int data;
    struct n *left;
    struct n *right;
} node;

node* createNode(int x){
    node *temp = (node*)calloc(1,sizeof(node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

typedef struct{
    node** nodes;
    int top;
    int size;
} nodeStack;

nodeStack *createNodeStack(int size)
{
    nodeStack *temp = (nodeStack *)calloc(1, sizeof(nodeStack));
    temp->size = size;
    temp->nodes = (node **)calloc(size, sizeof(node*));
    temp->top = -1;
    return temp;
}

void push(nodeStack *ns, node* x)
{
    if (!(ns->top == ns->size - 1))
        ns->nodes[++(ns->top)] = x;
    else
        printf("Stack is full!\n");
}

node* pop(nodeStack *ns)
{
    if (!(ns->top == -1))
        return (ns->nodes[(ns->top)--]);
    else
        return NULL;
}


// TRAVERSALS:
void inOrder(node *root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(node *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void preOrder(node *root){
    if(root != NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void iterativeInOrder(node *root)
{
    nodeStack* ns = createNodeStack(10);
    node* temp = root;
    while(temp != NULL || ns->top != -1)
    {
        while(temp != NULL)
        {
            push(ns, temp);
            temp = temp->left;
        }
        temp = pop(ns);
        printf("%d ", temp->data);
        temp = temp->right;
    }
    printf("\n");
}

void iterativePostOrder(node *root)
{
    nodeStack *ns = createNodeStack(10);
    node *temp = root;
    node *prev = NULL;
    do {
        while (temp != NULL) {
            push(ns, temp);
            temp = temp->left;
        }

        while (temp == NULL && ns->top != -1) {
            temp = ns->nodes[ns->top];

            if (temp->right == NULL || temp->right == prev) {
                printf("%d ", temp->data);
                prev = temp;
                pop(ns);
                temp = NULL;
            } else {
                temp = temp->right;
            }
        }
    } while (ns->top != -1);
    printf("\n");
}

void iterativePreOrder(node *root)
{
    nodeStack *ns = createNodeStack(10);
    node *temp = root;
    while (temp != NULL || ns->top != -1)
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            push(ns, temp);
            temp = temp->left;
        }
        temp = pop(ns);
        temp = temp->right;
    }
    printf("\n");
}


// CREATING THE TREES

node* createBinaryTree(int item)
{
    int x;
    if(item == -1){
        return NULL;
    }
    else
    {
        node* newNode = createNode(item);

        printf("Enter the left child: ");
        scanf("%d", &x);
        newNode->left = createBinaryTree(x);

        printf("Enter the right child: ");
        scanf("%d", &x);
        newNode->right = createBinaryTree(x);

        return newNode;
    }
}

node* createBSTRec(node *root, int x){
    if(root == NULL){
        return createNode(x);
    } else if(x < root->data){
        root->left = createBSTRec(root->left, x);
    } else {
        root->right = createBSTRec(root->right, x);
    }
    return root;
}

node* makeTheBST(int arr[],int size){
    node *root = NULL;
    for(int i=0;i<size;i++)
        root = createBSTRec(root,arr[i]);
    inOrder(root);
    return root;
}







// node* makeTheTree() {
//     node *root = NULL;
//     printf("Enter root data: ");
//     int x;
//     scanf("%d", &x);
//     getchar();
//     root = createNode(x);

//     char option;
//     int data;
//     while (1) {
//         printf("Enter the option (X,L,R) or 'E' to exit: ");
//         scanf(" %c", &option);
        
//         if (option == 'E') {
//             break;
//         }

//         if (option != 'X') {
//             printf("Enter the data: ");
//             scanf("%d", &data);
//             getchar();
//         } else {
//             data = 0;
//         }

//         root = createTree(root, data, option);
//     }

//     printf("In-order traversal: ");
//     inOrder(root);

//     return root;
// }

// node* createTree(node *tree, int data, char option) {
//     if (tree == NULL) {
//         return createNode(data);
//     }
//     if (option == 'X') {
//         return tree;
//     } else if (option == 'L') {
//         tree->left = createTree(tree->left, data, option);
//     } else if (option == 'R') {
//         tree->right = createTree(tree->right, data, option);
//     }

//     return tree;
// }