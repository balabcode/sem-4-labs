#include <stdio.h>
#include <stdlib.h>

typedef struct n
{
    int data;
    struct n *next;
} Node;

typedef struct gr
{
    int vertices;
    Node **AdjLists;
    int **AdjMat;
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

    // Initializing the adjacency matrix
    temp->AdjMat = (int **)calloc(v, sizeof(int *));

    // Initializing the adjacency lists
    temp->AdjLists = (Node **)calloc(v, sizeof(Node *));

    // Setting default values
    for (int i = 0; i < v; i++)
    {
        temp->AdjMat[i] = (int *)calloc(v, sizeof(int));
        temp->AdjLists[i] = NULL;
    }

    return temp;
}

void addEdge(Graph *graph, int s, int d)
{
    // List
    Node *tempNode = createNode(d);
    tempNode->next = graph->AdjLists[s];
    graph->AdjLists[s] = tempNode;

    // Matrix
    graph->AdjMat[s][d] = 1;
}

void printList(Graph *graph)
{
    printf("\nAdjacency Lists: \n");
    for (int v = 0; v < graph->vertices; v++)
    {
        Node *temp = graph->AdjLists[v];
        printf("\n Vertex %d\n: ", v);
        while (temp)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void printGraph(Graph *graph)
{
    printf("\nAdjacency Matrix:\n");
    for (int v = 0; v < graph->vertices; v++)
    {
        for (int w = 0; w < graph->vertices; w++)
        {
            printf("%d  ", graph->AdjMat[v][w]);
        }
    }
    printf("\n");
}

int main()
{
    Graph *graph = createGraph(4);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 0);

    printList(graph);
    printGraph(graph);
}