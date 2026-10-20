#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int celebrity(vector<vector<int>> matrix)
{
}

int main()
{

    vector<vector<int>> matrix = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};

    int ans = celebrity(matrix);
    cout << "Celebrity is: " << ans;

    return 0;
}