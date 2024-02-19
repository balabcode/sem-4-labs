#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

Node *nodeArray[MAX_NODES];
int top = -1;

Node *peek()
{
    if (top == -1)
        return NULL;
    return nodeArray[top];
}

void push(Node *node)
{
    if (top == MAX_NODES - 1)
        return;
    nodeArray[++top] = node;
}

Node *pop()
{
    if (top == -1)
        return NULL;
    return nodeArray[top--];
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(Node *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

Node *insertNode(Node *root, int data)
{
    Node *new_node = newNode(data);
    if (root == NULL)
        return new_node;

    Node *current = root;

    while (current != NULL)
    {
        push(current);
        if (data < current->data)
            current = current->left;
        else if (data > current->data)
            current = current->right;
        else
        {
            free(new_node);
            return root;
        }
    }

    Node *parent = peek();
    if (data < parent->data)
        parent->left = new_node;
    else
        parent->right = new_node;

    while (top != -1)
    {
        current = pop();
        current->height = 1 + max(height(current->left), height(current->right));
        int balance = getBalance(current);

        if (balance > 1 && data < current->left->data)
            current = rightRotate(current);
        else if (balance < -1 && data > current->right->data)
            current = leftRotate(current);
        else if (balance > 1 && data > current->left->data)
        {
            current->left = leftRotate(current->left);
            current = rightRotate(current);
        }
        else if (balance < -1 && data < current->right->data)
        {
            current->right = rightRotate(current->right);
            current = leftRotate(current);
        }

        if (top == -1)
            root = current;
        else
        {
            parent = peek();
            if (current->data < parent->data)
                parent->left = current;
            else
                parent->right = current;
        }
    }

    return root;
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    // 25 26 28 23 22 24 27
    // 5 6 8 3 2 4 7
    Node *root = NULL;

    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int temp;
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        root = insertNode(root, temp);
    }

    printf("\nPreorder: ");
    preorder(root);
    printf("\n");

    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Node
// {
//     int data;
//     struct Node *left;
//     struct Node *right;
//     int height;
// } Node;

// // Structure for stack
// typedef struct StackNode
// {
//     Node *node;
//     struct StackNode *next;
// } StackNode;

// // Functions for stack operations
// StackNode *createStackNode(Node *node)
// {
//     StackNode *stackNode = (StackNode *)malloc(sizeof(StackNode));
//     stackNode->node = node;
//     stackNode->next = NULL;
//     return stackNode;
// }

// int isEmpty(StackNode *root)
// {
//     return !root;
// }

// void push(StackNode **root, Node *node)
// {
//     StackNode *stackNode = createStackNode(node);
//     stackNode->next = *root;
//     *root = stackNode;
// }

// Node *pop(StackNode **root)
// {
//     if (isEmpty(*root))
//         return NULL;
//     StackNode *temp = *root;
//     *root = (*root)->next;
//     Node *popped = temp->node;
//     free(temp);
//     return popped;
// }

// Node *peek(StackNode *root)
// {
//     if (isEmpty(root))
//         return NULL;
//     return root->node;
// }

// int max(int a, int b)
// {
//     return (a > b) ? a : b;
// }

// int height(Node *node)
// {
//     if (node == NULL)
//         return 0;
//     return node->height;
// }

// Node *newNode(int data)
// {
//     Node *node = (Node *)malloc(sizeof(Node));
//     node->data = data;
//     node->left = NULL;
//     node->right = NULL;
//     node->height = 1;
//     return node;
// }

// Node *rightRotate(Node *y)
// {
//     Node *x = y->left;
//     Node *T2 = x->right;

//     x->right = y;
//     y->left = T2;

//     y->height = max(height(y->left), height(y->right)) + 1;
//     x->height = max(height(x->left), height(x->right)) + 1;

//     return x;
// }

// Node *leftRotate(Node *x)
// {
//     Node *y = x->right;
//     Node *T2 = y->left;

//     y->left = x;
//     x->right = T2;

//     x->height = max(height(x->left), height(x->right)) + 1;
//     y->height = max(height(y->left), height(y->right)) + 1;

//     return y;
// }

// int getBalance(Node *node)
// {
//     if (node == NULL)
//         return 0;
//     return height(node->left) - height(node->right);
// }

// Node *insertNode(Node *root, int data)
// {
//     Node *new_node = newNode(data); // Renamed from newNode to new_node
//     if (root == NULL)
//         return new_node;

//     // Initialize a stack to backtrack through the nodes
//     StackNode *stack = NULL;
//     Node *current = root;

//     // Traverse the tree to find the insertion point while pushing nodes onto the stack
//     while (current != NULL)
//     {
//         push(&stack, current);
//         if (data < current->data)
//             current = current->left;
//         else if (data > current->data)
//             current = current->right;
//         else // If data is already present in the tree
//         {
//             free(new_node);
//             return root;
//         }
//     }

//     // Insert the new node at the appropriate position
//     Node *parent = peek(stack);
//     if (data < parent->data)
//         parent->left = new_node;
//     else
//         parent->right = new_node;

//     // Update height of the ancestor nodes and perform rotations if necessary
//     while (!isEmpty(stack))
//     {
//         current = pop(&stack);
//         current->height = 1 + max(height(current->left), height(current->right));
//         int balance = getBalance(current);

//         if (balance > 1 && data < current->left->data)
//             current = rightRotate(current);
//         else if (balance < -1 && data > current->right->data)
//             current = leftRotate(current);
//         else if (balance > 1 && data > current->left->data)
//         {
//             current->left = leftRotate(current->left);
//             current = rightRotate(current);
//         }
//         else if (balance < -1 && data < current->right->data)
//         {
//             current->right = rightRotate(current->right);
//             current = leftRotate(current);
//         }

//         // Update root if necessary
//         if (isEmpty(stack))
//             root = current;
//         else
//         {
//             parent = peek(stack);
//             if (current->data < parent->data)
//                 parent->left = current;
//             else
//                 parent->right = current;
//         }
//     }

//     return root;
// }

// void preorder(Node *root)
// {
//     if (root != NULL)
//     {
//         printf("%d ", root->data);
//         preorder(root->left);
//         preorder(root->right);
//     }
// }

// int main()
// {
//     Node *root = NULL;

//     int n;
//     printf("Enter number of elements: ");
//     scanf("%d", &n);

//     int temp;
//     printf("Enter elements: ");
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &temp);
//         root = insertNode(root, temp);
//     }

//     printf("\nPreorder: ");
//     preorder(root);
//     printf("\n");

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Node
// {
//     int data;
//     struct Node *left;
//     struct Node *right;
//     int height;
// } Node;

// int max(int a, int b)
// {
//     return (a > b) ? a : b;
// }

// int height(Node *node)
// {
//     if (node == NULL)
//         return 0;
//     return node->height;
// }

// Node *newNode(int data)
// {
//     Node *node = (Node *)malloc(sizeof(Node));
//     node->data = data;
//     node->left = NULL;
//     node->right = NULL;
//     node->height = 1;
//     return node;
// }

// Node *rightRotate(Node *y)
// {
//     Node *x = y->left;
//     Node *T2 = x->right;

//     x->right = y;
//     y->left = T2;

//     y->height = max(height(y->left), height(y->right)) + 1;
//     x->height = max(height(x->left), height(x->right)) + 1;

//     return x;
// }

// Node *leftRotate(Node *x)
// {
//     Node *y = x->right;
//     Node *T2 = y->left;

//     y->left = x;
//     x->right = T2;

//     x->height = max(height(x->left), height(x->right)) + 1;
//     y->height = max(height(y->left), height(y->right)) + 1;

//     return y;
// }

// int getBalance(Node *node)
// {
//     if (node == NULL)
//         return 0;
//     return height(node->left) - height(node->right);
// }

// Node *insertNode(Node *root, int data)
// {
//     Node *new_node = newNode(data); // Renamed from newNode to new_node
//     if (root == NULL)
//         return new_node;

//     Node *current = root;
//     Node *parent = NULL;

//     while (current != NULL)
//     {
//         parent = current;
//         if (data < current->data)
//             current = current->left;
//         else if (data > current->data)
//             current = current->right;
//         else // If data is already present in the tree
//         {
//             free(new_node);
//             return root;
//         }
//     }

//     if (data < parent->data)
//         parent->left = new_node;
//     else
//         parent->right = new_node;

//     // Update height of the ancestor nodes and perform rotations if necessary
//     current = new_node;
//     while (current != NULL)
//     {
//         current->height = 1 + max(height(current->left), height(current->right));
//         int balance = getBalance(current);

//         if (balance > 1 && data < current->left->data)
//             current = rightRotate(current);
//         else if (balance < -1 && data > current->right->data)
//             current = leftRotate(current);
//         else if (balance > 1 && data > current->left->data)
//         {
//             current->left = leftRotate(current->left);
//             current = rightRotate(current);
//         }
//         else if (balance < -1 && data < current->right->data)
//         {
//             current->right = rightRotate(current->right);
//             current = leftRotate(current);
//         }

//         if (current->data == root->data)
//             break; // If the root has been changed
//         current = (data < current->data) ? current->left : current->right;
//     }

//     return root;
// }

// void preorder(Node *root)
// {
//     if (root != NULL)
//     {
//         printf("%d ", root->data);
//         preorder(root->left);
//         preorder(root->right);
//     }
// }

// int main()
// {
//     Node *root = NULL;

//     int n;
//     printf("Enter number of elements: ");
//     scanf("%d", &n);

//     int temp;
//     printf("Enter elements: ");
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &temp);
//         root = insertNode(root, temp);
//     }

//     printf("\nPreorder: ");
//     preorder(root);
//     printf("\n");

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct n
// {
//     int data;
//     Node *left;
//     Node *right;
//     int height;
// } Node;

// int max(int a, int b)
// {
//     return (a > b) ? a : b;
// }

// int height(Node *node)
// {
//     if (node == NULL)
//         return 0;
//     return node->height;
// }

// Node *newNode(int data)
// {
//     Node *node = (Node *)malloc(sizeof(Node));
//     node->data = data;
//     node->left = NULL;
//     node->right = NULL;
//     node->height = 1;
//     return node;
// }

// Node *rightRotate(Node *y)
// {
//     Node *x = y->left;
//     Node *T2 = x->right;

//     x->right = y;
//     y->left = T2;

//     y->height = max(height(y->left), height(y->right)) + 1;
//     x->height = max(height(x->left), height(x->right)) + 1;

//     return x;
// }

// Node *leftRotate(Node *x)
// {
//     Node *y = x->right;
//     Node *T2 = y->left;

//     y->left = x;
//     x->right = T2;

//     x->height = max(height(x->left), height(x->right)) + 1;
//     y->height = max(height(y->left), height(y->right)) + 1;

//     return y;
// }

// int getBalance(Node *node)
// {
//     if (node == NULL)
//         return 0;
//     return height(node->left) - height(node->right);
// }

// Node *insertNode(Node *node, int data)
// {
//     if (node == NULL)
//         return newNode(data);

//     if (data < node->data)
//         node->left = insertNode(node->left, data);
//     else if (data > node->data)
//         node->right = insertNode(node->right, data);
//     else
//         return node;

//     node->height = 1 + max(height(node->left), height(node->right));

//     int balance = getBalance(node);

//     if (balance > 1 && data < node->left->data)
//         return rightRotate(node);

//     if (balance < -1 && data > node->right->data)
//         return leftRotate(node);

//     if (balance > 1 && data > node->left->data)
//     {
//         node->left = leftRotate(node->left);
//         return rightRotate(node);
//     }

//     if (balance < -1 && data < node->right->data)
//     {
//         node->right = rightRotate(node->right);
//         return leftRotate(node);
//     }

//     return node;
// }

// void preorder(Node *root)
// {
//     if (root != NULL)
//     {
//         printf("%d ", root->data);
//         preorder(root->left);
//         preorder(root->right);
//     }
// }

// int main()
// {
//     Node *root = NULL;

//     // 25 26 28 23 22 24 27
//     // 5 6 8 3 2 4 7

//     int n;
//     printf("Enter number of elements: ");
//     scanf("%d", &n);

//     int temp;
//     printf("Enter elements: ");
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &temp);
//         root = insertNode(root, temp);
//     }

//     printf("\nPreorder: ");
//     preorder(root);
//     printf("\n");

//     return 0;
// }
