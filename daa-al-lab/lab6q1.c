#include <stdio.h>
#include <stdlib.h>

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
    static int count = 0;
    if (root != NULL)
    {
        numberOfNodes(root->left);
        count++;
        numberOfNodes(root->right);
    }
    return count;
}

int main()
{
    int nums[] = {5, 3, 1, 2, 11, 4, 6, 8, 9, 10, 12, 7};
    Node *root = makeTheBST(nums, sizeof(nums) / sizeof(nums[0]));
    printf("Number of Nodes: %d\n", numberOfNodes(root));
    return 0;
}