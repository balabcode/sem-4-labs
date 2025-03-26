#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyDown(int heap[], int hsize, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < hsize && heap[left] > heap[largest])
        largest = left;

    if (right < hsize && heap[right] > heap[largest])
        largest = right;

    if (largest != i)
    {
        swap(&heap[i], &heap[largest]);
        heapifyDown(heap, hsize, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyDown(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapifyDown(arr, i, 0);
    }
}

int main()
{
    int arr[] = {12, 7, 10, 5, 15, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
