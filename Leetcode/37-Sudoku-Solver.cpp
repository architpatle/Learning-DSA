#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int col, char dig)
{

    // vertically
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == dig)
            return false;
    }

    // horizontally
    for (int j = 0; j < 9; j++)
    {
        if (board[row][j] == dig)
            return false;
    }

    // in grid
    int sRow = (row / 3) * 3;
    int sCol = (col / 3) * 3;

    for (int i = sRow; i <= sRow + 2; i++)
    {
        for (int j = sCol; j <= sCol + 2; j++)
        {
            if (board[i][j] == dig)
                return false;
        }
    }

    return true;
}

bool helper(vector<vector<char>> &board, int row, int col)
{

    // base condition
    if (row == 9)
    {
        return true;
    }

    // Calculate sudoku traversing variables
    int nextRow = row, nextCol = col + 1;
    if (nextCol == 9)
    {
        nextRow = row + 1;
        nextCol = 0;
    }

    // checking if the current board[row][col] is not '.'
    if (board[row][col] != '.')
    {
        return helper(board, nextRow, nextCol);
    }

    // If board[row][col] is equal to '.', then we check 1 to 9, which one is safe to place here.
    for (char dig = '1'; dig <= '9'; dig++)
    {

        // if isSafe function returns true then we place the dig value at current [row][col]
        if (isSafe(board, row, col, dig))
        {
            board[row][col] = dig;

            // We again call helper function to put safe digit at next empty space('.');
            if (helper(board, nextRow, nextCol))
            {
                // true is returned if, next element is successfully placed
                return true;
            }

            // if false is returned for next element, then we back track to current element revert it back to '.'.
            // Then checks again for other digits

            board[row][col] = '.';
        }
    }

    return false;
}
void SudokuSolver(vector<vector<char>> &board)
{
    helper(board, 0, 0);
}

int main()
{
    vector<vector<char>> board = {
        {'6', '2', '5', '.', '8', '1', '3', '4', '.'},
        {'8', '9', '3', '2', '4', '.', '1', '6', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '2', '.'},
        {'.', '.', '6', '.', '.', '.', '7', '5', '2'},
        {'.', '7', '.', '.', '2', '.', '9', '.', '3'},
        {'.', '3', '.', '5', '7', '.', '.', '.', '.'},
        {'.', '.', '9', '.', '.', '.', '.', '7', '5'},
        {'2', '1', '.', '9', '5', '.', '.', '.', '4'},
        {'.', '.', '.', '.', '.', '6', '.', '.', '1'}};

    SudokuSolver(board);

    for (int i = 0; i < board.size(); i++)
{
    for (int j = 0; j < board[i].size(); j++)
    {
        cout << board[i][j] << " ";
    }
    cout << endl;
}

    return 0;
}