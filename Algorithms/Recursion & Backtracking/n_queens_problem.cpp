#include <iostream>
#include <vector>
using namespace std;

#define N 8 // Change this for different board sizes

// Function to check if a queen can be placed at board[row][col]
bool isSafe(vector<vector<int>> &board, int row, int col, int n) {
    // Check this column on upper side
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    // Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j]) return false;

    return true;
}

// Recursive function to solve N-Queens
bool solveNQueens(vector<vector<int>> &board, int row, int n) {
    if (row == n) { // Base case: all queens are placed
        // Print solution
        for (auto &r : board) {
            for (int cell : r)
                cout << (cell ? "Q " : ". ");
            cout << endl;
        }
        cout << "------------------------" << endl;
        return true; // Continue searching for more solutions
    }

    bool foundSolution = false;

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1; // Place the queen
            foundSolution = solveNQueens(board, row + 1, n) || foundSolution;
            board[row][col] = 0; // Backtrack
        }
    }
    return foundSolution;
}

// Driver function
int main() {
    int n;
    cout << "Enter the value of N (size of chessboard): ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (!solveNQueens(board, 0, n))
        cout << "No solution exists." << endl;

    return 0;
}
