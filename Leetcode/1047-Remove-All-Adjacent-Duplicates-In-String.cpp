#include <iostream>
#include <stack>
using namespace std;

string removeDuplicates(string s)
{
    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (st.empty())
        {
            st.push(s[i]);
            continue;
        }

        if (st.top() == s[i])
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    int start = 0, end = ans.size() - 1;

    while (start < end)
    {
        swap(ans[start], ans[end]);
        start++;
        end--;
    }

    return ans;
}

int main()
{
    string s = "abbaca";

    cout << "After removing duplicates: " << removeDuplicates(s);

    return 0;
}