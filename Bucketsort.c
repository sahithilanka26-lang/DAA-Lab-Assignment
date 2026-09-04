#include <stdio.h>

#define BUCKETS 10

void insertionSort(int bucket[], int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = bucket[i];
        j = i - 1;

        while (j >= 0 && bucket[j] > key)
        {
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = key;
    }
}

void bucketSort(int a[], int n)
{
    int bucket[BUCKETS][100];
    int count[BUCKETS] = {0};
    int max = a[0];
    int i, j, k = 0, index;

    /* Find maximum element */
    for (i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }

    /* Put elements into buckets */
    for (i = 0; i < n; i++)
    {
        index = (a[i] * BUCKETS) / (max + 1);

        if (index >= BUCKETS)
            index = BUCKETS - 1;

        bucket[index][count[index]++] = a[i];
    }

    /* Sort each bucket */
    for (i = 0; i < BUCKETS; i++)
        insertionSort(bucket[i], count[i]);

    /* Combine buckets */
    for (i = 0; i < BUCKETS; i++)
    {
        for (j = 0; j < count[i]; j++)
            a[k++] = bucket[i][j];
    }
}

int main()
{
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter non-negative array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    bucketSort(a, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}