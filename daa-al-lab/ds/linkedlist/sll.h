#include <stdio.h>
#include <stdlib.h>

// Singly Linked List

typedef struct n
{
    int data;
    struct n *next;
} node;

node *createNode(int x)
{
    node *temp = (node *)calloc(1, sizeof(node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void addFront(node **head, int x)
{
    node *temp = createNode(x);
    temp->next = (*head);
    (*head) = temp;
}

void addRear(node **head, int x)
{
    if ((*head) == NULL)
    {
        (*head) = createNode(x);
        return;
    }
    node *p;
    for (p = (*head); p->next != NULL; p = p->next);
    p->next = createNode(x);
}

int delFront(node **head)
{
    if ((*head) == NULL)
    {
        printf("List is empty!\n");
        return -69;
    }
    int x = (*head)->data;
    node *temp = (*head);
    (*head) = (*head)->next;
    free(temp);
    return x;
}

int delRear(node **head)
{
    if ((*head) == NULL)
    {
        printf("List is empty!\n");
        return -69;
    }
    node *p;
    for (p = (*head); p->next->next != NULL; p = p->next);
    int x = p->next->data;
    free(p->next);
    p->next = NULL;
    return x;
}

void display(node *head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    printf("\nList: ");
    node *p;
    for (p = head; p->next != NULL; p = p->next)
        printf("%d -> ", p->data);
    printf("%d\n", p->data);
}

void reverse(node **head){
    node *prev = NULL;
    node *curr = (*head);
    node *next = NULL;

    while(curr != NULL){
        next = curr->next; 
        curr->next = prev; 

        prev = curr;
        curr = next;
    }
    *head = prev;
}

node* createList(int arr[], int n){
    node *temp = NULL;
    for(int i = 0; i < n; i++){
        addRear(&temp, arr[i]);
    }
    display(temp);
    return temp;
}