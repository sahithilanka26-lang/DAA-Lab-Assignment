#include <stdio.h>

int main()
{
    int a, r, n, i;
    long long sum = 0;

    printf("Enter the first term: ");
    scanf("%d", &a);

    printf("Enter the common ratio: ");
    scanf("%d", &r);

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        sum = sum + a;
        a = a * r;
    }

    printf("Sum = %lld", sum);

    return 0;
}