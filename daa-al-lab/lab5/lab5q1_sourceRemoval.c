#include <stdio.h>
#include <stdlib.h>
// #include "../ds/StackPrint.h"
#include "../ds/intStack.h"

typedef struct n
{
    int data;
    struct n *next;
} Node;

typedef struct gr
{
    int v;
    Node **AdjLists;
} Graph;

Node *createNode(int x)
{
    Node *temp = (Node *)calloc(1, sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

Graph *createGraph(int v)
{
    Graph *temp = (Graph *)calloc(1, sizeof(Graph));
    temp->v = v;
    temp->AdjLists = (Node **)calloc(v, sizeof(Node *));
    for (int i = 0; i < v; i++)
        temp->AdjLists[i] = NULL;
    return temp;
}

void addEdge(Graph *graph, int s, int d)
{
    Node *tempNode = createNode(d);
    tempNode->next = graph->AdjLists[s];
    graph->AdjLists[s] = tempNode;
}

void printList(Graph *graph)
{
    printf("\nAdjacency Lists: \n");
    for (int v = 0; v < graph->v; v++)
    {
        Node *temp = graph->AdjLists[v];
        printf("\n Vertex %d: ", v);
        while (temp != NULL)
        {
            printf("%d   ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

void toposort(Graph *g, int start)
{
}