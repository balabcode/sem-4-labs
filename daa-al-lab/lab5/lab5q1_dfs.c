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

void toposort(Graph *g, int start, int *visited, Stack *s, Stack *topo)
{
    // DFS init:
    visited[start] = 1;
    push(s, start);

    // starting DFS Loop:
    while (!isEmpty(s))
    {
        int currentVertex = peek(s);
        Node *temp = g->AdjLists[currentVertex];
        while (temp != NULL)
        {
            if (visited[temp->data] != 1)
            {
                push(s, temp->data);
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
        while (peek(s) != currentVertex)
        {
            push(topo, pop(s));
        }
        push(topo, pop(s));
    }

    // checking if all nodes are visited
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
        toposort(g, unvisited, visited, s, topo);
    }
    else
    {
        printf("\nToposort: ");
        while (!isEmpty(topo))
        {
            printf("%d  ", pop(topo));
        }
        printf("\n");
    }
}

int main()
{
    Graph *g = createGraph(6);
    addEdge(g, 3, 1);
    addEdge(g, 2, 3);
    addEdge(g, 5, 2);
    addEdge(g, 5, 0);
    addEdge(g, 4, 0);
    addEdge(g, 4, 1);

    printList(g);

    Stack *s = createStack(10);
    int *visited = (int *)calloc(g->v, sizeof(int));
    Stack *topo = createStack(10);
    toposort(g, 0, visited, s, topo);
}