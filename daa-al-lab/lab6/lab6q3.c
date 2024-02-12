#include <stdio.h>
#include <stdlib.h>
int opcount = 0;
// Merge Sort

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        opcount++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        opcount++;
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        opcount++;
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int left, int right)
{
    if (left < right)
    {
        opcount++;
        int mid = left + (right - left) / 2;

        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int nums[] = {5, 3, 1, 2, 11, 4, 6, 8, 9, 10, 12, 7};
    mergesort(nums, 0, sizeof(nums) / sizeof(nums[0]));
    printf("After sorting: ");
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
        printf("%d  ", nums[i]);
    printf("\n");
    printf("Opcount: %d\n", opcount);
    return 0;
}