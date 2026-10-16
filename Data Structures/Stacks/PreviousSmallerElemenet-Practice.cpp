#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{

    vector<int> arr = {2, 1, 3, 4, 8};

    // solution
    vector<int> ans(arr.size(), 0);
    stack<int> st;

    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }

        st.push(arr[i]);
    }

    for (int val : ans)
    {
        cout << val << " ";
    }

    return 0;
}