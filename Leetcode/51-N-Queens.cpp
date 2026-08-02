#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n)
{
    // vertical
    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    // horizontal
    for (int j = 0; j < n; j++)
    {
        if (board[row][j] == 'Q')
            return false;
    }

    // left-up diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // right-up diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

void getRowQueen(vector<string> &board, vector<vector<string>> &ans, int row, int n)
{

    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, row, j, n))
        {
            board[row][j] = 'Q';

            getRowQueen(board, ans, row + 1, n);
            board[row][j] = '.';
        }
    }
}

vector<vector<string>> nQueens(int n)
{
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;

    getRowQueen(board, ans, 0, n);

    return ans;
}
int main()
{

    vector<vector<string>> ans = nQueens(4);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}