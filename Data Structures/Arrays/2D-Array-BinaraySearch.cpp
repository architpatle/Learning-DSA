#include <iostream>
#include <vector>
using namespace std;

// For Matrix 1
bool SearchInRow(vector<vector<int>> mat, int target, int rowMid){

    int n = mat[0].size();

    int st = 0, end = n-1;
    
    while(st<=end){
        int mid = st+((end -st)/2);

        if(mat[rowMid][mid] == target){
            return true;
        } else if( mat[rowMid][mid] > target){
            end = mid-1;

        } else {
            st = mid +1;
        }
    }

    return false;
}

bool MatrixBinarySearch(vector<vector<int>> mat, int target)
{
    int m = mat.size(), n = mat[0].size();

    int rowSt = 0, rowEnd = m - 1;

    // Searching the row where target lies
    while (rowSt <= rowEnd)
    {
        int rowMid = rowSt + ((rowEnd - rowSt) / 2);

        if (mat[rowMid][0] <= target && target <= mat[rowMid][n - 1])
        {
            return SearchInRow(mat, target, rowMid);
        }
        else if (mat[rowMid][0] < target)
        {
            rowSt = rowMid + 1;
        }
        else
        {
            rowEnd = rowMid - 1;
        }
    }

    return false;
}


// For Matrix 2
bool MatrixBinarySearchTwo(vector<vector<int>> mat, int target){

    int m = mat.size(), n = mat[0].size();

    int r = 0, c =n -1;

    while(r<m && c>=0){

        if(mat[r][c] == target){
            return true;
        } else if(mat[r][c] > target){
            c--;
        } else {
            r++;
        }
    }

    return false;

}
int main()
{

    // Matrix 1
    // vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    // Matrix 2
    vector<vector<int>> matrix ={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 99;

    // cout<<MatrixBinarySearch(matrix, target);

    cout<<MatrixBinarySearchTwo(matrix, target);


    return 0;
}