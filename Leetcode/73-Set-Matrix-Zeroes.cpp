#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void SetMatrixZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();

    unordered_set<int> rowS;
    unordered_set<int> colS;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                rowS.insert(i);
                colS.insert(j);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (rowS.find(i) != rowS.end())
            {
                matrix[i][j] = 0;
            }
            else if (colS.find(j) != colS.end())
            {
                matrix[i][j] = 0;
            }
        }
    }
}
int main()
{
    vector<vector<int>> matrix = {{2, 1, 2, 0},
                                  {3, 0, 5, 2},
                                  {1, 3, 1, 5}};

    SetMatrixZeroes(matrix);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}