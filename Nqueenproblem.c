
#include <stdio.h>
#include <stdlib.h>

int board[20];
int n;

// Function to check whether a queen can be placed safely
int isSafe(int row, int col)
{
    for (int i = 1; i < row; i++)
    {
        // Check same column
        if (board[i] == col)
        {
            return 0;
        }

        // Check diagonal
        if (abs(board[i] - col) == abs(i - row))
        {
            return 0;
        }
    }

    return 1;
}

// Function to print the chessboard
void printBoard()
{
    printf("\nSolution:\n");

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (board[i] == j)
            {
                printf(" Q ");
            }
            else
            {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

// Function to solve N-Queen using Backtracking
int solveNQueen(int row)
{
    // All queens are successfully placed
    if (row > n)
    {
        printBoard();
        return 1;
    }

    int found = 0;

    // Try placing queen in each column
    for (int col = 1; col <= n; col++)
    {
        if (isSafe(row, col))
        {
            // Place queen
            board[row] = col;

            // Move to the next row
            found += solveNQueen(row + 1);

            // Backtrack: remove the queen
            board[row] = 0;
        }
    }

    return found;
}

// Main function
int main()
{
    printf("Enter the number of queens: ");

    if (scanf("%d", &n) != 1)
    {
        printf("Invalid input! Please enter an integer.\n");
        return 1;
    }

    if (n < 1 || n > 19)
    {
        printf("Enter N between 1 and 19.\n");
        return 1;
    }

    int solutions = solveNQueen(1);

    if (solutions == 0)
    {
        printf("\nNo solution exists for N = %d.\n", n);
    }
    else
    {
        printf("\nTotal number of solutions: %d\n", solutions);
    }

    return 0;
}
