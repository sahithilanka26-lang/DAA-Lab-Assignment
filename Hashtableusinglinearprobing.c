#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

void insert(int key)
{
    int index = key % SIZE;
    int i = 0;

    while (hashTable[(index + i) % SIZE] != -1 && i < SIZE)
        i++;

    if (i == SIZE)
        printf("Hash table is full\n");
    else
        hashTable[(index + i) % SIZE] = key;
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