#include <stdio.h>
#include <stdlib.h>
#include "..\ds\circularQueue.h"

typedef struct n
{
    int data;
    struct n *next;
} Node;

typedef struct gr
{
    int v;
    Node **AdjLists;
    int *indegree;
} Graph;

Node *createNode(int x)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

Graph *createGraph(int v)
{
    Graph *temp = (Graph *)calloc(1, sizeof(Graph));
    temp->v = v;
    temp->AdjLists = (Node **)calloc(v, sizeof(Node *));
    temp->indegree = (int *)calloc(v, sizeof(int));
    for (int i = 0; i < v; i++)
        temp->AdjLists[i] = NULL;
    return temp;
}

void addEdge(Graph *g, int s, int d)
{
    Node *tempNode = createNode(d);
    tempNode->next = g->AdjLists[s];
    g->AdjLists[s] = tempNode;
    g->indegree[d]++;
}

void printList(Graph *g)
{
    printf("\nAdjacency Lists: \n");
    for (int v = 0; v < g->v; v++)
    {
        Node *temp = g->AdjLists[v];
        printf("\n Vertex %d: ", v);
        while (temp != NULL)
        {
            printf("%d   ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

void toposort(Graph *g)
{
    int *result = (int *)calloc(g->v, sizeof(int));
    Queue *q = createQueue(g->v);

    // adding all nodes w indegree 0 to q
    for (int i = 0; i < g->v; ++i)
    {
        if (g->indegree[i] == 0)
        {
            insertQ(q, i);
        }
    }

    int index = 0;

    while (!isQEmpty(q))
    {
        int current = deleteQ(q);
        result[index++] = current;

        Node *temp = g->AdjLists[current];

        while (temp != NULL)
        {
            if (--(g->indegree[temp->data]) == 0)
            {
                insertQ(q, temp->data);
            }
            temp = temp->next;
        }
    }

    printf("Topological Sort: ");
    for (int i = 0; i < g->v; ++i)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
}

int main()
{
    Graph *g = createGraph(6);
    addEdge(g, 5, 0);
    addEdge(g, 4, 0);
    addEdge(g, 4, 1);
    addEdge(g, 3, 1);
    addEdge(g, 2, 3);
    addEdge(g, 5, 2);

    printList(g);
    toposort(g);

    free(g->AdjLists);
    free(g->indegree);
    free(g);

    return 0;
}