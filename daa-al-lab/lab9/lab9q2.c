// Write a program to construct the Open hash table. Find the number of key
// comparisons in successful search and unsuccessful search. This should be done by
// varying the load factor of the hash table. You may consider varying the number of
// keys for a fixed value of hash table size say m=10 and n=50, 100, and 200. This
// should be repeated for at least four different hash table sizes say m= 20, m=50.

#include <stdio.h>
#include <stdlib.h>

typedef struct ll
{
    int data;
    struct ll *next;
} Node;

Node *createNode(int x)
{
    Node *temp = (Node *)calloc(1, sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void insertNode(Node **head, int x)
{
    Node *ins = createNode(x);
    Node *temp = (*head);
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = ins;
    ((*head)->data)++;
}

int *linkedToList(Node *head)
{
    int count = head->data + 1;
    int *list = (int *)calloc(count, sizeof(int));

    Node *temp = head->next;
    int i = 0;
    while (temp != NULL)
    {
        list[i] = temp->data;
        temp = temp->next;
        i++;
    }
    return list;
}

int main()
{
    Node *head = createNode(0);
    insertNode(&head, 100);
    insertNode(&head, 200);
    insertNode(&head, 300);
    int *list = linkedToList(head);
    int n = head->data;
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", list[i]);
    }
    printf("\n");
}