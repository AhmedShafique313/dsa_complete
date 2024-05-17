#include <iostream>
#include <fstream>

using namespace std;

const int N = 8; // Change N to the desired number of queens

// Structure to represent a position on the chessboard
struct Position {
    int row;
    int col;
};

// Function to initialize the chessboard with all cells as empty
void initializeBoard(char board[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            board[i][j] = '.';
        }
    }
}

// Function to display the chessboard
void displayBoard(char board[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if placing a queen at position (row, col) is safe
bool isSafe(char board[N][N], int row, int col) {
    // Check row
    for (int i = 0; i < col; ++i) {
        if (board[row][i] == 'Q') {
            return false;
        }
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Check lower diagonal on left side
    for (int i = row, j = col; i < N && j >= 0; ++i, --j) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

// Function to solve N-Queen problem recursively
bool solveNQueensUtil(char board[N][N], int col) {
    // Base case: If all queens are placed, return true
    if (col == N) {
        return true;
    }

    // Try placing a queen in each row of the current column
    for (int i = 0; i < N; ++i) {
        // Check if queen can be placed at board[i][col]
        if (isSafe(board, i, col)) {
            // Place the queen
            board[i][col] = 'Q';

            // Recur to place rest of the queens
            if (solveNQueensUtil(board, col + 1)) {
                return true;
            }

            // If placing queen at board[i][col] doesn't lead to a solution,
            // then backtrack and remove the queen from board[i][col]
            board[i][col] = '.';
        }
    }

    // If the queen cannot be placed in any row of the current column, return false
    return false;
}

// Function to solve the N-Queen problem and display the solution
void solveNQueens() {
    char board[N][N];
    initializeBoard(board);

    // Solve N-Queen problem starting from the first column
    if (solveNQueensUtil(board, 0)) {
        cout << "Solution exists:" << endl;
        displayBoard(board);
    } else {
        cout << "Solution does not exist for " << N << "-Queens problem." << endl;
    }
}

int main() {
    solveNQueens();

    return 0;
}
