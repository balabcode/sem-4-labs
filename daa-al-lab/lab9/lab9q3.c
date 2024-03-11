#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
#define DELETED -1

typedef struct Node
{
    char a[MAX];
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

void insertNode(Node *hashTable[], int sum, Node *newNode, int size)
{
    int index = sum % size;

    while (hashTable[index] != NULL && strcmp(hashTable[index]->a, newNode->a) != 0)
    {
        index = (index + 1) % size;
    }

    if (hashTable[index] == NULL || strcmp(hashTable[index]->a, newNode->a) == 0)
    {
        hashTable[index] = newNode;
    }
}

Node **createHashTable(char sentence[], int size)
{
    Node **hashTable = (Node **)calloc(size, sizeof(Node *));

    Node *newNode;
    char wordBuffer[50];
    int wordLength = -1;

    for (int i = 0; i < strlen(sentence); i++)
    {
        if (sentence[i] == ' ' || sentence[i] == '.' || sentence[i] == '\0')
        {
            int sum = findSum(wordBuffer, wordLength);
            newNode = (Node *)malloc(sizeof(Node));
            makeCopy(newNode->a, wordBuffer, wordLength);
            insertNode(hashTable, sum, newNode, size);
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
        printf("%d:", i);

        if (hashTable[i] != NULL)
        {
            printf(" %s", hashTable[i]->a);
        }

        printf("\n");

        // Free memory for nodes in hash table
        free(hashTable[i]);
    }

    // Free memory for hash table array
    free(hashTable);

    return 0;
}
