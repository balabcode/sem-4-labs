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
Node *leftest(Node *node)
{
    Node *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node *rightest(Node *node)
{
    Node *current = node;
    while (current && current->right != NULL)
        current = current->right;
    return current;
}

Node *successor(Node *root, int key)
{
    Node *current = root;
    Node *successor = NULL;

    while (current != NULL)
    {
        if (current->data > key)
        {
            successor = current;
            current = current->left;
        }
        else if (current->data < key)
            current = current->right;
        else
        {
            if (current->right != NULL)
                return leftest(current->right);
            break;
        }
    }
    return successor;
}

Node *predecessor(Node *root, int key)
{
    Node *current = root;
    Node *predecessor = NULL;

    while (current != NULL)
    {
        if (current->data < key)
        {
            predecessor = current;
            current = current->right;
        }
        else if (current->data > key)
            current = current->left;
        else
        {
            if (current->left != NULL)
                return rightest(current->left);
            break;
        }
    }
    return predecessor;
}

void display(Node *root, int key)
{
    Node *succ = successor(root, key);
    Node *pred = predecessor(root, key);

    printf("Successor of %d is: %d\n", key, succ ? succ->data : -1);
    printf("Predecessor of %d is: %d\n", key, pred ? pred->data : -1);
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

    display(root, 23);

    return 0;
}