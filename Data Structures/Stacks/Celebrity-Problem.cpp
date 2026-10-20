#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int celebrity(vector<vector<int>> matrix)
{
    stack<int> st;
    int n =matrix.size();

    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    while(st.size() > 1){
        int i = st.top();
        st.pop();

        int j = st.top();
        st.pop();

        if(matrix[i][j] == 0){
            st.push(i);
        } else {
            st.push(j);
        }
    }

    int celeb = st.top();

    for(int i = 0; i<n; i++){
        if((i!=celeb) && (matrix[i][celeb] == 0 || matrix[celeb][i] == 1)){
            return -1;
        }
    }

    return celeb;
}

int main()
{

    vector<vector<int>> matrix = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};

    int ans = celebrity(matrix);
    cout << "Celebrity is: " << ans;

    return 0;
}