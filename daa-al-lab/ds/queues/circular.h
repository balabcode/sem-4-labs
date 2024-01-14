#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int front;
    int rear;
    int size;
} Queue;

Queue *createQueue(int size)
{
    Queue *temp = (Queue *)calloc(1, sizeof(Queue));
    temp->size = size;
    temp->data = (int *)calloc(size, sizeof(int));
    temp->front = -1;
    temp->rear = -1;
    return temp;
}

int isQFull(Queue *q)
{
    return ((q->rear + 1) % q->size == q->front);
}

int isQEmpty(Queue *q)
{
    return (q->rear == -1 && q->front == -1);
}

void insertQ(Queue *q, int x)
{
    if (isQFull(q))
    {
        printf("Queue is full!");
        return;
    }
    else if (isQEmpty(q))
    {
        q->front = 0;
        q->rear = 0;
        // q->data[] = x;
    }
    else
    {
        q->rear = (q->rear + 1) % (q->size);
    }
    q->data[q->rear] = x;
}

int deleteQ(Queue *q){
    if(isQEmpty(q)){
        printf("Queue is empty!\n");
        return -69;
    }
    int x = q->data[q->front];
    if(q->front == q->rear){
        q->rear = -1;
        q->front = -1;
    }
    else
        q->front = (q->front+1)%(q->size);
    
    return x;
}

void displayQ(Queue *q)
{
    if(isQEmpty(q)){
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue: ");
    for(int i = q->front; i != (q->rear+1)%(q->size); i = (i+1)%q->size)
        printf("%d ", q->data[i]);
    printf("\n");
}