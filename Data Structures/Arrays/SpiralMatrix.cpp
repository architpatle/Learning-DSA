#include <iostream>
#include <vector>
using namespace std;

vector<int> SpiralMatrix(vector<vector<int>> mat)
{
    vector<int> ans;
    int m = mat.size(), n = mat[0].size();
    int stRow = 0, stCol = 0, endRow = m - 1, endCol = n - 1;

    while (stRow <= endRow && stCol <= endCol)
    {

        // top print
        for (int i = stCol; i <= endCol; i++)
        {
            ans.push_back(mat[stRow][i]);
        }

        // right print
        for (int j = stRow + 1; j <= endRow; j++)
        {
            ans.push_back(mat[j][endCol]);
        }

        // bottom print
        for (int i = endCol - 1; i >= stCol; i--)
        {
            if (stRow == endRow)
            {
                break;
            }
            ans.push_back(mat[endRow][i]);
        }

        // left print
        for (int j = endRow - 1; j >= stRow + 1; j--)
        {
            if (stCol == endCol)
            {
                break;
            }
            ans.push_back(mat[j][stCol]);
        }
        stRow++;
        stCol++;
        endRow--;
        endCol--;
    }
    return ans;
}

vector<int> SpiralMatrixPractice(vector<vector<int>> mat)
{
    int m = mat.size(), n = mat[0].size();
    vector<int> ans;

    int rStart = 0, cStart = 0, rEnd = m - 1, cEnd = n - 1;

    while (rStart <= rEnd && cStart <= cEnd)
    {

        for (int i = cStart; i <= cEnd; i++)
        {
            ans.push_back(mat[rStart][i]);
        }

        for (int j = rStart + 1; j <= rEnd; j++)
        {
            ans.push_back(mat[j][cEnd]);
        }

        for (int i = cEnd - 1; i >= cStart; i--)
        {
            if (rStart == rEnd)
            {
                break;
            }
            ans.push_back(mat[rEnd][i]);
        }

        for (int j = rEnd - 1; j >= rStart+1; j--)
        {
            if (cStart == cEnd)
            {
                break;
            }

            ans.push_back(mat[j][cStart]);
        }

        rStart++;
        rEnd--;
        cStart++;
        cEnd--;
    }

    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    vector<int> ans = SpiralMatrixPractice(matrix);

    for (int val : ans)
    {
        cout << val << " ";
    }
    return 0;
}