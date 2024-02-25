#include <stdio.h>
#include <stdlib.h>
int opcount = 0;

// Sort given set of integers using Quick sort and analyze its efficiency.

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int arr[], int first, int last)
{
    int i, j, pivot;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while (i < j)
        {
            while (arr[i] <= arr[pivot] && i <= last)
            {
                opcount++;
                i++;
            }
            while (arr[j] >= arr[pivot] && j > first)
            {
                opcount++;
                j--;
            }
            if (i < j)
            {
                opcount++;
                swap(&arr[i], &arr[j]);
            }
        }
        opcount++;
        swap(&arr[j], &arr[pivot]);
        quicksort(arr, first, j - 1);
        quicksort(arr, j + 1, last);
    }
}

int main()
{
    int nums[] = {5, 3, 1, 2, 11, 4, 6, 8, 9, 10, 0, 12, 7, 0};
    // int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    // int nums[] = {2, 3, 5, 7, 8, 9};
    // int nums[] = {5, 3, 1, 2, 11, 4};
    quicksort(nums, 0, (sizeof(nums) / sizeof(nums[0])) - 1);
    printf("After sorting: ");
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
        printf("%d  ", nums[i]);
    printf("\n");
    printf("Opcount: %d\n", opcount);
}