#include <stdio.h>
#include <stdlib.h>
int opcount = 0;

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
                opcount++;
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
    printf("\nOpcount: %d\n", opcount);
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// void clearArray(int arr[], int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         arr[i] = 0;
//     }
// }

// void copyArray(int destination[], int source[], int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         destination[i] = source[i];
//     }
// }

// void assignment(int rowsize, int colsize, int costMat[][colsize])
// {
//     int visited[colsize], currRes[colsize], prevRes[colsize];
//     clearArray(visited, colsize);
//     clearArray(currRes, colsize);
//     clearArray(prevRes, colsize);

//     int count = -1;
//     int currSum = 0, prevSum = 9999999;
//     for (int row = 0; row < rowsize; row++)
//     {
//         for (int col = 0; col < colsize; col++)
//         {
//             if (visited[col] == 0)
//             {
//                 currSum += costMat[row][col];
//                 currRes[col] = ++count;
//                 visited[col] = 1;
//                 // testing
//                 printf("Visited: \n");
//                 for (int i = 0; i < colsize; i++)
//                 {
//                     printf(" %d  ", visited[i]);
//                 }
//                 printf("ENd of visited\n");
//                 //
//             }
//         }
//         if (prevSum > currSum)
//         {
//             prevSum = currSum;
//             copyArray(prevRes, currRes, colsize);
//         }
//         clearArray(visited, colsize);
//         clearArray(currRes, colsize);
//         currSum = 0;
//         count = -1;
//     }

//     for (int i = 0; i < colsize; i++)
//     {
//         printf("%d  ", prevRes[i]);
//     }
//     printf("\n");
// }

// int main()
// {
//     int costMat[][4] = {{10, 3, 8, 9}, {7, 5, 4, 8}, {6, 9, 2, 9}, {8, 7, 10, 5}};
//     assignment(4, 4, costMat);
// }

// #include <stdio.h>
// #include <stdlib.h>

// int fact(int n)
// {
//     int f = 1;
//     for (int i = 2; i < n; i++)
//     {
//         f = f * i;
//     }
//     return f;
// }

// int assignment(int size, int costMat[][size])
// {
//     for (int i = 0; i < fact(size); i++)
//     {
//     }
// }