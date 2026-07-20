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


/* ----- PRACTICE ----- */
pair<int,int> linearSearchInMatrixPractice(vector<vector<int>> mat, int key){

    int m = mat.size(), n = mat[0].size();

    for( int i =0; i<m; i++){
        for(int j =0; j<n; j++){
            if(mat[i][j] == key){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

int MaxRowSumPractice(vector<vector<int>> mat){
    int maxSum = INT32_MIN;
    int m = mat.size(), n = mat[0].size();

    for(int i =0; i<m; i++){
        int currentSum = 0;
        for(int j =0; j<n; j++){
            currentSum+=mat[i][j];
        }
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int MaxColSumPractice(vector<vector<int>> mat){
    int maxSum = INT32_MIN;
    int m = mat.size(), n = mat[0].size();

    for(int j = 0; j<n; j++){
        int currentSum = 0;

        for(int i =0; i<m; i++){
            currentSum+= mat[i][j];
        }

        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int DiagonalSumPractice(vector<vector<int>> mat){
    int n = mat.size();
    int diagonalSum=0;

    for(int i =0; i<n; i++){
        diagonalSum+= mat[i][i];

        if(i!= n-1-i){
            diagonalSum+= mat[i][n-1-i];
        }
    }

    return diagonalSum;
}

int main()
{
    int row = 3, col = 3, n=3;
    vector<vector<int>> matrix = {{1, 12, 13}, {4, 25, 16}, {7, 8, 119}};
    int key = 82;

    // pair<int,int> ans = linearSearchInMatrixPractice(matrix, key);
    // cout<<ans.first<<" ";
    // cout<<ans.second<<" ";

    // cout << MaxRowSumPractice(matrix) <<endl;
    // cout << MaxColSumPractice(matrix) <<endl;

    cout<<DiagonalSumPractice(matrix);


    return 0;
}