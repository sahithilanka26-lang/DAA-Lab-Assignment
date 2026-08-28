#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

void insert(int key)
{
    int hash = key % SIZE;
    int index;
    int i;

    for (i = 0; i < SIZE; i++)
    {
        index = (hash + i * i) % SIZE;

        if (hashTable[index] == -1)
        {
            hashTable[index] = key;
            return;
        }
    }

    printf("Hash table is full\n");
}

void display()
{
    int i;

    printf("Hash Table:\n");
    for (i = 0; i < SIZE; i++)
        printf("%d : %d\n", i, hashTable[i]);
}

int main()
{
    int i, n, key;

    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(key);
    }

    display();

    return 0;
}