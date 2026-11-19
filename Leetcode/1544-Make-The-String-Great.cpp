#include <iostream>
#include <stack>
using namespace std;

string makeGood(string s)
{
    stack<char> st;
    string ans = "";
    st.push(s[s.size() - 1]);

    for (int i = s.size() - 2; i >= 0; i--)
    {
        if (!st.empty() && abs(st.top() - s[i]) == 32)
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }

    return ans;
}

int main()
{
    string s = "abBAcC";

    cout << "Great String: " << makeGood(s);

    return 0;
}