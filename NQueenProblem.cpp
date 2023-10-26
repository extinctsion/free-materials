#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Check the column on top
    for (int i = 0; i < row; i++) {
        if (board[i][col])
            return false;
    }

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    // Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j])
            return false;
    }

    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int row, int N) {
    if (row == N) {
        // Print the solution
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j])
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    bool res = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;
            res = solveNQueensUtil(board, row + 1, N) || res;
            board[row][col] = 0;
        }
    }

    return res;
}

void solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQueensUtil(board, 0, N)) {
        cout << "No solution exists." << endl;
    }
}

int main() {
    int N;
    cout << "Enter the value of N for N-Queens problem: ";
    cin >> N;
    solveNQueens(N);

    return 0;
}
