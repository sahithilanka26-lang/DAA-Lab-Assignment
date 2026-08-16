#include <stdio.h>

int linearSearch(int A[], int n, int key)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (A[i] == key)
        {
            return i;   // Element found
        }
    }

    return -1;   // Element not found
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    int n = 5;
    int key = 30;

    int result = linearSearch(A, n, key);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}