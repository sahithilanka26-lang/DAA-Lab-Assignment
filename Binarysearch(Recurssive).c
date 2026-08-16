#include <stdio.h>

int binarySearch(int A[], int beg, int end, int key)
{
    if (beg <= end)
    {
        int mid = (beg + end) / 2;

        if (A[mid] == key)
            return mid;

        else if (key < A[mid])
            return binarySearch(A, beg, mid - 1, key);

        else
            return binarySearch(A, mid + 1, end, key);
    }

    return -1;   // Element not found
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    int n = 5;
    int key = 20;

    int result = binarySearch(A, 0, n - 1, key);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}