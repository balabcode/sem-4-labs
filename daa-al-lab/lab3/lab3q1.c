#include <stdio.h>

void bubblesort(int a[], int n)
{
    int comp = 0, swaps = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            comp++;
            if (a[j] > a[j + 1])
            {
                swaps++;
                a[j + 1] = (a[j] + a[j + 1]) - (a[j] = a[j + 1]);
            }
        }
    }
    printf("\nComparisons: %d\n", comp);
    printf("Swaps: %d\n", swaps);
    printf("Total Opcount: %d\n", swaps + comp);
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    bubblesort(a, n);
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d  ", a[i]);
    printf("\n");
}