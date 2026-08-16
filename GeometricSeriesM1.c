#include <stdio.h>
#include <math.h>

int main()
{
    int a, r, n;
    float sum;

    printf("Enter the first term: ");
    scanf("%d", &a);

    printf("Enter the common ratio: ");
    scanf("%d", &r);

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    sum = (a * (pow(r, n) - 1)) / (r - 1);

    printf("Sum = %.2f", sum);

    return 0;
}