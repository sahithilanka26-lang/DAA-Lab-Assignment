
#include <stdio.h>
#include <limits.h>

int main()
{
    int n, i, j, k, l;
    int p[100], m[100][100];

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter dimensions of matrices:\n");
    for (i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    // Initialize diagonal elements
    for (i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    // Chain length
    for (l = 2; l <= n; l++)
    {
        for (i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = INT_MAX;

            for (k = i; k < j; k++)
            {
                int cost = m[i][k] + m[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                }
            }
        }
    }

    printf("Minimum number of scalar multiplications: %d\n",
           m[1][n]);

    return 0;
}
