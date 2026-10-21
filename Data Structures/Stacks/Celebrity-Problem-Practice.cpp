#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// celebrity => matrix[i][j] == 1 AND matrix[j][i] == 0 Then j is celebrity (Everyone know celebrity but celebrity doesnt know anyone else)

int celebrity(vector<vector<int>> matrix)
{
    stack<int> st;
    int n = matrix.size();

    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    while (st.size() > 1)
    {
        int i = st.top();
        st.pop();

        int j = st.top();
        st.pop();

        if (matrix[i][j] == 1)
        {
            st.push(j);
        }
        else
        {
            st.push(i);
        }
    }

    int celeb = st.top();

    for (int i = 0; i < n; i++)
    {

        if ((celeb != i) && (matrix[celeb][i] == 1 || matrix[i][celeb] == 0))
        {
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