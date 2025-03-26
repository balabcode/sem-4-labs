#include "../ds/trees.h"

Node *createBST(Node *root, int x)
{
    if (root == NULL)
    {
        root = createNode(x);
        return root;
    }
    else
    {
        if (x < root->data)
        {
            root->left = createBST(root->left, x);
        }
        else if (x > root->data)
        {
            root->right = createBST(root->right, x);
        }
        return root;
    }
}

void searchBST(Node *root, int key)
{
    int found = 0;

    while (root != NULL && !found)
    {
        if (key < root->data)
            root = root->left;
        else if (key > root->data)
            root = root->right;
        else
            found = 1;
    }

    if (found)
        printf("Found!\n");
    else
        printf("Not Found :(\n");
}

int main()
{

    Node *root = NULL;
    int n;
    printf("Enter length of array: ");
    scanf("%d", &n);
    int nums[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    for (int i = 0; i < n; i++)
    {
        root = createBST(root, nums[i]);
    }

    inOrder(root);
    printf("Root: %d\n", root->data);
    printf("\n");

    printf("Enter key to be searched: ");
    int target;
    scanf("%d", &target);

    searchBST(root, target);
    return 0;
}