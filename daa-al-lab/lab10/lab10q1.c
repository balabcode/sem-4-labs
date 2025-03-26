#include <stdio.h>
#define MAXV 4

void transitiveClosure(int graph[MAXV][MAXV], int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
        }
    }
    printf("\nTransitive closure:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d\t", graph[i][j]);
        printf("\n");
    }
}

int main()
{
    int graph[MAXV][MAXV] = {{1, 1, 0, 1},
                             {0, 1, 1, 0},
                             {0, 0, 1, 1},
                             {0, 0, 0, 1}};

    printf("Input:\n");
    for (int i = 0; i < MAXV; i++)
    {
        for (int j = 0; j < MAXV; j++)
            printf("%d\t", graph[i][j]);
        printf("\n");
    }
    transitiveClosure(graph, MAXV);

    return 0;
}
