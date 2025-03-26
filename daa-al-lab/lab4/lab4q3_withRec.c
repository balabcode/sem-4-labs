#include <stdio.h>
#include <stdlib.h>
#include "../ds/circularQueue.h"

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
        while (temp->next != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
    printf("\n");
}

void BFS(Graph *g, int start, int *visited, Queue *q, Queue *result)
{
    // starting from start
    visited[start] = 1;
    insertQ(q, start);

    // starting BFS loop
    while (!isQEmpty(q))
    {
        int currentVertex = deleteQ(q);
        insertQ(result, currentVertex);
        // printf("Deleting: %d\n", currentVertex);
        // exploring neighbors:
        Node *temp = g->AdjLists[currentVertex];
        while (temp != NULL)
        {
            if (!visited[temp->data])
            {
                insertQ(q, temp->data);
                // printf("Inserting: %d\n", temp->data);
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }

    int unvisited = -1;
    for (int i = 0; i < g->v; i++)
    {
        if (visited[i] != 1)
        {
            unvisited = i;
            break;
        }
    }
    if (unvisited != -1)
    {
        BFS(g, unvisited, visited, q, result);
    }
}

int main()
{
    Graph *g = createGraph(4);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 2, 3);
    addEdge(g, 3, 0);
    addEdge(g, 2, 1);

    printList(g);
    Queue *q = createQueue(10);
    int *visited = (int *)calloc(g->v, sizeof(int));
    Queue *result = createQueue(10);
    BFS(g, 0, visited, q, result);
    displayQ(result);
}