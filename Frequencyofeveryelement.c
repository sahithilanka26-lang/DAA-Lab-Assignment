#include <stdio.h>

#define SIZE 100

int hashTable[SIZE];
int frequency[SIZE];

int hash(int key)
{
    if (key < 0)
        key = -key;

    return key % SIZE;
}

void insert(int key)
{
    int index = hash(key);
    int i;

    for (i = 0; i < SIZE; i++)
    {
        int pos = (index + i) % SIZE;

        if (hashTable[pos] == key)
        {
            frequency[pos]++;
            return;
        }

        if (hashTable[pos] == -1)
        {
            hashTable[pos] = key;
            frequency[pos] = 1;
            return;
        }
    }
}

int main()
{
    int arr[] = {10, 20, 10, 30, 20, 10, 40};
    int n = 7;

    int i;

    for (i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
        frequency[i] = 0;
    }

    for (i = 0; i < n; i++)
        insert(arr[i]);

    printf("Frequency of elements:\n");

    for (i = 0; i < SIZE; i++)
    {
        if (hashTable[i] != -1)
            printf("%d -> %d\n", hashTable[i], frequency[i]);
    }

    return 0;
}