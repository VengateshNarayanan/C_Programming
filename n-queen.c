#include <stdio.h> 
#include <stdbool.h>

#define MAX 20


int board[MAX][MAX]; int n;

bool isSafe(int row, int col)
{
int i, j;


for (i = 0; i < row; i++)
 
if (board[i][col]) return false;

for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) if (board[i][j])
return false;


for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) if (board[i][j])
return false;


return true;
}
bool solveNQueen(int row)
{
if (row == n) return true;

for (int col = 0; col < n; col++)
{
if (isSafe(row, col))
 
{
board[row][col] = 1;


if (solveNQueen(row + 1)) return true;
board[row][col] = 0;
}
}


return false;
}
void printBoard()
{
for (int i = 0; i < n; i++)
{
for (int j = 0; j < n; j++)
{
if (board[i][j])
printf("Q "); else
printf(". ");
 
}
printf("\n");
}
}


int main()
{
printf("Enter the value of N: "); scanf("%d", &n);

if (n < 1 || n > MAX)
{
printf("Invalid value of N.\n"); return 0;
}


if (solveNQueen(0))
{
printf("\nSolution:\n"); printBoard();
}
 
else
{
printf("\nNo solution exists.\n");
}


return 0;
}
