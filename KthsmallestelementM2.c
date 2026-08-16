#include <stdio.h>

void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = 6;
    int k = 2;

    sort(arr, n);

    printf("The %dth smallest element is %d\n", k, arr[k - 1]);

    return 0;
}