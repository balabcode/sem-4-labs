#include <stdio.h>
#include <stdlib.h>
int opcount = 0;

// Total number of nodes in a BT

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

Node *createBSTRec(Node *root, int x)
{
    if (root == NULL)
    {
        return createNode(x);
    }
    else if (x < root->data)
    {
        root->left = createBSTRec(root->left, x);
    }
    else
    {
        root->right = createBSTRec(root->right, x);
    }
    return root;
}

Node *makeTheBST(int arr[], int size)
{
    Node *root = NULL;
    for (int i = 0; i < size; i++)
        root = createBSTRec(root, arr[i]);
    return root;
}

int numberOfNodes(Node *root)
{
    opcount++;
    if (root != NULL)
        return 1 + numberOfNodes(root->left) + numberOfNodes(root->right);
    else
        return 0;
}

int main()
{
    int nums[] = {5, 3, 1, 2, 11, 4, 6, 8, 9, 10, 12, 7};
    Node *root = makeTheBST(nums, sizeof(nums) / sizeof(nums[0]));
    printf("Number of Nodes: %d\n", numberOfNodes(root));
    printf("Opcount: %d\n", opcount);
    return 0;
}