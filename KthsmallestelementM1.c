#include <stdio.h>

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = 6;
    int k = 3;

    for (int i = 0; i < k; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    printf("The %dth smallest element is %d\n", k, arr[k - 1]);

    return 0;
}