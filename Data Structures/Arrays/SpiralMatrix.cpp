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
            if(stCol == endCol){
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
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    vector<int> ans = SpiralMatrix(matrix);

    for(int val: ans){
        cout<<val<<" ";
    }
    return 0;
}