#include <stdio.h>

// #include <stdio.h>
// #include <stdlib.h>

// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
// void quicksort(int arr[], int f, int l)
// {
//     if (f < l)
//     {
//         int i = f + 1;
//         int j = l;

//         while (i < j)
//         {
//             while (i < l && arr[i] < arr[f])
//                 i++;
//             while (arr[j] > arr[f])
//                 j--;
//             if (i < j)
//                 swap(&arr[i], &arr[j]);
//         }
//         swap(&arr[f], &arr[j]);
//         quicksort(arr, f, j - 1);
//         quicksort(arr, j + 1, l);
//     }
// }

// int main()
// {
//     // int nums[] = {6, 7, 8, 2, 3, 4, 6, 7, 2, 1};
//     int nums[] = {5, 3, 1, 2, 11, 4, 6, 8, 9, 10, 0, 12, 7, 0};
//     int n = sizeof(nums) / sizeof(nums[0]);
//     quicksort(nums, 0, n - 1);
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d  ", nums[i]);
//     }
//     printf("\n");
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// void merge(int arr[], int left, int mid, int right)
// {
//     int i, j, k;
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

//     int L[n1], R[n2];

//     // init L and R
//     for (i = 0; i < n1; i++)
//         L[i] = arr[left + i];
//     for (j = 0; j < n2; j++)
//         R[j] = arr[mid + 1 + j];

//     i = 0;
//     j = 0;
//     k = left;

//     while (i < n1 && j < n2)
//     {
//         if (L[i] <= R[j])
//             arr[k++] = L[i++];
//         else
//             arr[k++] = R[j++];
//     }
//     while (i < n1)
//         arr[k++] = L[i++];
//     while (j < n2)
//         arr[k++] = R[j++];
// }

// void mergesort(int arr[], int left, int right)
// {
//     if (left < right)
//     {
//         int mid = left + (right - left) / 2;
//         mergesort(arr, left, mid);
//         mergesort(arr, mid + 1, right);
//         merge(arr, left, mid, right);
//     }
// }

// int main()
// {
//     int nums[] = {6, 7, 8, 2, 3, 4, 6, 7, 2, 1};
//     int n = sizeof(nums) / sizeof(nums[0]);
//     mergesort(nums, 0, n);
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d  ", nums[i]);
//     }
//     printf("\n");
//     return 0;
// }