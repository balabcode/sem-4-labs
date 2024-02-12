#include <stdio.h>
#include <stdlib.h>

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
            while (arr[i] <= arr[pivot] && i < last)
            {
                i++;
            }
            while (arr[j] >= arr[pivot] && j > first)
            {
                j--;
            }
            if (i < j)
            {
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[j], &arr[pivot]);
        quicksort(arr, first, j - 1);
        quicksort(arr, j + 1, last);
    }
}

int main()
{
    int nums[] = {5, 3, 1, 2, 11, 4, 6, 8, 9, 10, 12, 7};
    quicksort(nums, 0, sizeof(nums) / sizeof(nums[0]));
    printf("After sorting: ");
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
        printf("%d  ", nums[i]);
    printf("\n");
}