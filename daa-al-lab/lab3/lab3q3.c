// #include <stdio.h>

// int opcount = 0;

// void partition(int nums[], int size)
// {
//     int target = 0;
//     for (int i = 0; i < size; i++)
//     {
//         opcount++;
//         target += nums[i];
//     }
//     if (target % 2 == 1)
//     {
//         printf("Partitioning not possible!\n");
//         return;
//     }

//     target /= 2;

//     for (int i = 0; i < size; i++)
//     {
//         for (int j = 0; j < size; j++)
//         {
//             opcount++;
//             if (nums[i] + nums[j] == target)
//             {
//                 printf("{%d, %d} ", nums[i], nums[j]);
//             }
//         }
//     }
// }

// int main()
// {
//     int nums[] = {1, 2, 3, 4};
//     partition(nums, 4);
//     printf("\nOpcount: %d\n", opcount);
// }

#include <stdio.h>
int opcount = 0;

int isEqualSum(int set[], int n, int subsetSum)
{
    int currentSum = 0;
    for (int i = 0; i < n; i++)
    {
        opcount++;
        if ((subsetSum & (1 << i)) != 0)
        {
            currentSum += set[i];
        }
    }
    return currentSum == subsetSum;
}

void findPartition(int set[], int n)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        opcount++;
        totalSum += set[i];
    }

    if (totalSum % 2 == 1)
    {
        printf("Partition is not possible.\n");
        return;
    }

    int subsetSum = totalSum / 2;

    for (int i = 0; i < (1 << n); i++)
    {
        int currentSubsetSum = 0;
        for (int j = 0; j < n; j++)
        {
            opcount++;
            if ((i & (1 << j)) != 0)
            {
                currentSubsetSum += set[j];
            }
        }

        if (currentSubsetSum == subsetSum)
        {
            printf("{");
            for (int j = 0; j < n; j++)
            {
                opcount++;
                if ((i & (1 << j)) != 0)
                    printf(" %d", set[j]);
            }
            printf(" }\n");

            printf("{");
            for (int j = 0; j < n; j++)
            {
                opcount++;
                if ((i & (1 << j)) == 0)
                    printf(" %d", set[j]);
            }
            printf(" }\n");
            return;
        }
    }

    printf("Partition is not possible.\n");
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int set[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    findPartition(set, n);

    printf("\nOpcount: %d\n", opcount);

    return 0;
}
