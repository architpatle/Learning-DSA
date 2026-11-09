#include <iostream>
#include <stack>
using namespace std;

string clearDigits(string s)
{
    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (isalpha(s[i]))
        {
            s.push_back(s[i]);
        }
        else
        {
            if (!st.empty())
            {
                st.pop();
            }
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
    string str = "cb34";

    cout << clearDigits(str);

    return 0;
}