#include <stdio.h>
#include <stdlib.h>

typedef struct n
{
    int data;
    struct n *left;
    struct n *right;
} Node;

Node *createNode(int x)
{
    Node *temp = (Node *)calloc(1, sizeof(Node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Node *createBST(Node *root, int x)
// {
//     if (root == NULL)
//     {
//         root = createNode(x);
//         return root;
//     }
//     else
//     {
//         if (x < root->data)
//         {
//             root->left = createBST(root->left, x);
//         }
//         else if (x > root->data)
//         {
//             root->right = createBST(root->right, x);
//         }
//         return root;
//     }
// }

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d  ", root->data);
        inOrder(root->right);
    }
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d  ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d  ", root->data);
}