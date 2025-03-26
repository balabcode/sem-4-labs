#include <stdio.h>
#include <stdlib.h>

void copyArray(int destination[], int source[], int size)
{
    for (int i = 0; i < size; i++)
    {
        destination[i] = source[i];
    }
}

void assignment(int tempRes[], int size, int currRow, int costMat[][size], int *minCost, int *result)
{
    if (currRow == size)
    {
        int currCost = 0;
        for (int i = 0; i < size; i++)
        {
            currCost += costMat[i][tempRes[i]];
        }

        if (currCost < *minCost)
        {
            *minCost = currCost;
            copyArray(result, tempRes, size);
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (tempRes[i] == 0)
            {
                tempRes[i] = currRow;
                assignment(tempRes, size, currRow + 1, costMat, minCost, result);
                tempRes[i] = 0;
            }
        }
    }
}

int main()
{
    int size = 4;
    int minCost = 9999999;

    int costMat[][4] = {{10, 3, 8, 9}, {7, 5, 4, 8}, {6, 9, 2, 9}, {8, 7, 10, 5}};

    int result[size];
    int tempRes[size];

    for (int i = 0; i < size; i++)
    {
        tempRes[i] = 0;
    }

    assignment(tempRes, size, 0, costMat, &minCost, result);

    printf("Result: { ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", result[i] + 1);
    }
    printf("}\n");
    return 0;
}
