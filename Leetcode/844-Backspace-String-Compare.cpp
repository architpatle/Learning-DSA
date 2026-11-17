#include <iostream>
#include <stack>
using namespace std;

bool backspaceCompare(string s, string t)
{
    stack<char> st1;
    stack<char> st2;

    for (int i = 0; i < s.size(); i++)
    {
        if (st1.empty() && s[i] == '#')
        {
            continue;
        }
        else if (!st1.empty() && s[i] == '#')
        {
            st1.pop();
        }
        else
        {
            st1.push(s[i]);
        }
    }

    for (int i = 0; i < t.size(); i++)
    {
        if (st2.empty() && t[i] == '#')
        {
            continue;
        }
        else if (!st2.empty() && t[i] == '#')
        {
            st2.pop();
        }
        else
        {
            st2.push(t[i]);
        }
    }

    while (!st1.empty() && !st2.empty())
    {
        if (st1.top() != st2.top())
        {
            return false;
        }
        st1.pop();
        st2.pop();
    }

    return st1.empty() && st2.empty() ? true : false;
}

int main()
{
    string s = "ab#c";
    string t = "ad#c";

    cout << backspaceCompare(s, t);

    return 0;
}