#include <stdio.h>

void moveDisk(int disk, char from, char to)
{
    printf("Move disk %d from %c to %c\n", disk, from, to);
}

int main()
{
    int n;
    int totalMoves;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    totalMoves = (1 << n) - 1;

    char source = 'A';
    char auxiliary = 'B';
    char destination = 'C';

    /* For even number of disks, swap auxiliary and destination */
    if (n % 2 == 0)
    {
        char temp = auxiliary;
        auxiliary = destination;
        destination = temp;
    }

    for (int move = 1; move <= totalMoves; move++)
    {
        if (move % 3 == 1)
        {
            printf("Move between %c and %c\n", source, destination);
        }
        else if (move % 3 == 2)
        {
            printf("Move between %c and %c\n", source, auxiliary);
        }
        else
        {
            printf("Move between %c and %c\n", auxiliary, destination);
        }
    }

    return 0;
}