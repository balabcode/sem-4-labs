#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int i)
{
    while (i > 0)
    {
        int parent = (i - 1) / 2;
        if (heap[i] > heap[parent])
        {
            swap(&heap[i], &heap[parent]);
            i = parent;
        }
        else
            break;
    }
}

void insertHeap(int heap[], int *hsize, int val)
{
    if (*hsize < MAX)
    {
        heap[*hsize] = val;
        (*hsize)++;
        heapifyUp(heap, *hsize - 1);
    }
    else
        printf("Heap is full. Cannot insert element.\n");
}

int main()
{
    int heap[MAX];
    int hsize = 0;

    int nums[] = {12, 7, 10, 5, 15, 6};

    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
        insertHeap(heap, &hsize, nums[i]);

    printf("Heap: ");
    for (int i = 0; i < hsize; i++)
        printf("%d ", heap[i]);
    printf("\n");
    return 0;
}
