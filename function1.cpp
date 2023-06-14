#include"function1.h"
const int MAXN = 100;
int board[MAXN][MAXN];

bool isSafe(int row, int col, int N) {
    // Check if there is a queen in the same row on the left side
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }
    // Check if there is a queen in the upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    // Check if there is a queen in the lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}

bool solveNQueens(int col, int N) {
    // Base case: If all queens are placed, return true
    if (col == N) {
        return true;
    }
    // Try placing queen in each row of the current column
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col, N)) {
            board[i][col] = 1;
            // Recursively place queens in the remaining columns
            if (solveNQueens(col + 1, N)) {
                return true;
            }
            board[i][col] = 0; // Backtrack
        }
    }
    return false;
}
