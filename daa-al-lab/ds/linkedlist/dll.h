#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List

typedef struct n
{
    int data;
    struct n *next;
    struct n *prev;
} node;

node *createNode(int x)
{
    node *temp = (node *)calloc(1, sizeof(node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void addFront(node **head, int x)
{
    node *temp = createNode(x);
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    (*head)->prev = temp;
    temp->next = (*head);
    (*head) = temp;
}

void addRear(node **head, int x)
{
    node *temp = createNode(x);
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    node *p;
    for (p = *head; p->next != NULL; p = p->next);
    p->next = temp;
    temp->prev = p;
}

void delFront(node **head)
{
    (*head) = (*head)->next;
    printf("Data Popped: %d\n", (*head)->prev->data);
    free((*head)->prev);
    (*head)->prev = NULL;
}

void delRear(node **head)
{
    node *p;
    for (p = (*head); p->next->next != NULL; p = p->next);
    printf("Data Popped: %d\n", (p)->next->data);
    free(p->next);
    p->next = NULL;
}

void display(node *head)
{
    printf("\nList: ");
    node *p;
    for (p = head; p->next != NULL; p = p->next)
        printf("%d -> ", p->data);
    printf("%d\n", p->data);
}

node* createList(int arr[], int n){
    node *temp = NULL;
    for(int i = 0; i < n; i++){
        addRear(&temp, arr[i]);
    }
    display(temp);
    return temp;
}

void reverse(node **head){
    node *curr = (*head);
    node *temp = NULL;

    while(curr != NULL){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if(temp != NULL){
        (*head) = temp->prev;
    }
}