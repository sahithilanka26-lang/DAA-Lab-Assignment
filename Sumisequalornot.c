#include <stdio.h>

#define SIZE 100

int hashTable[SIZE];

int hash(int key)
{
    if (key < 0)
        key = -key;

    return key % SIZE;
}

int search(int key)
{
    int index = hash(key);
    int i;

    for (i = 0; i < SIZE; i++)
    {
        int pos = (index + i) % SIZE;

        if (hashTable[pos] == -1)
            return 0;

        if (hashTable[pos] == key)
            return 1;
    }

    return 0;
}

void insert(int key)
{
    int index = hash(key);
    int i;

    for (i = 0; i < SIZE; i++)
    {
        int pos = (index + i) % SIZE;

        if (hashTable[pos] == -1)
        {
            hashTable[pos] = key;
            return;
        }
    }
}

int main()
{
    int arr[] = {2, 7, 11, 15};
    int n = 4;
    int target = 9;

    int i, complement;

    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    for (i = 0; i < n; i++)
    {
        complement = target - arr[i];

        if (search(complement))
        {
            printf("Two elements found: %d and %d\n",
                   complement, arr[i]);
            return 0;
        }

        insert(arr[i]);
    }

    printf("No two elements found\n");

    return 0;
}