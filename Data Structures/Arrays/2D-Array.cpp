#include <iostream>
#include <vector>
using namespace std;

// Linear Search in 2D Matrix
pair<int, int> linearSearchInMatrix(int matrix[4][3], int row, int col, int key)
{
    pair<int, int> ans;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == key)
            {
                ans = {i, j};
            }
        }
    }
    return ans;
}

// Return Max Row-sum
int MaxRowSum(int matrix[][3], int row, int col)
{
    int maxSum = INT32_MIN;

    for(int i =0; i<row; i++){

        int currentSum = 0;

        for(int j =0; j<col; j++){
            currentSum += matrix[i][j];
        }

        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

// Return Max Column-sum
int MaxColSum(int matrix[][3], int row, int col)
{
    int maxSum = INT32_MIN;

    for(int i =0; i<col; i++){

        int currentSum = 0;

        for(int j =0; j<row; j++){
            currentSum += matrix[j][i];
        }

        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

// Diagonal Sum
int DiagonalSum(int matrix[][3], int n){
    int sum =0;

    for(int i = 0; i<n; i++){

        sum+=matrix[i][i];

        if(i != n-1-i ){
            sum+= matrix[i][n-1-i];
        }

        
    }
    return sum;
}

int main()
{
    int row = 3, col = 3, n=3;
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int key = 5;

    // pair<int,int> ans = linearSearchInMatrix(matrix, row, col, key);
    // cout<<ans.first<<" ";
    // cout<<ans.second<<" ";

    // cout << MaxRowSum(matrix, row, col) <<endl;
    // cout << MaxColSum(matrix, row, col) <<endl;

    cout<<DiagonalSum(matrix, n);


    return 0;
}