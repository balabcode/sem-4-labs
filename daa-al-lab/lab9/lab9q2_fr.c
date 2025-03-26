#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
typedef struct Node
{
    char a[MAX];
    struct Node *next;
} Node;

int findSum(char *b, int j)
{
    int sum = 0;
    for (int i = 0; i <= j; i++)
    {
        sum += (b[i] - 'a' + 1);
    }
    return sum;
}

void makeCopy(char dest[], char src[], int length)
{
    for (int i = 0; i <= length; i++)
    {
        dest[i] = src[i];
    }
    dest[length + 1] = '\0';
}

void insertNode(Node **hashTable, int sum, Node *newNode)
{
    Node *current = hashTable[sum];
    if (!current)
        hashTable[sum] = newNode;
    else
    {
        while (current->next)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

Node **createHashTable(char sentence[], int size)
{
    Node **hashTable = (Node **)calloc(size, sizeof(Node *));
    for (int i = 0; i < size; i++)
    {
        hashTable[i] = NULL;
    }

    Node *newNode;
    char wordBuffer[50];
    int wordLength = -1;

    for (int i = 0; i < strlen(sentence); i++)
    {
        if (sentence[i] == ' ' || sentence[i] == '.' || sentence[i] == '\0')
        {
            int sum = findSum(wordBuffer, wordLength) % size;
            newNode = (Node *)malloc(sizeof(Node));
            newNode->next = NULL;
            makeCopy(newNode->a, wordBuffer, wordLength);
            insertNode(hashTable, sum, newNode);
            wordLength = -1;
        }
        else
        {
            wordBuffer[++wordLength] = sentence[i];
        }
    }

    return hashTable;
}

int main()
{
    char input[100];
    int tsize;

    printf("Enter the value of k: ");
    scanf("%d", &tsize);

    printf("Enter the sentence: ");
    getchar();
    fgets(input, sizeof(input), stdin);

    Node **hashTable = createHashTable(input, tsize);

    for (int i = 0; i < tsize; i++)
    {
        int count = 0;
        printf("%d:", i);
        Node *curr = hashTable[i];

        while (curr)
        {
            count++;
            printf(" %s,", curr->a);
            curr = curr->next;
        }
        printf("\n");
        // printf(" (%d)\n", count);
    }

    return 0;
}
