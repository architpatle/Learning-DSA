#include <iostream>
using namespace std;

string removeOuterParentheses(string s)
{
    string ans = "";
    int depth = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' && depth == 0)
        {
            depth++;
        }
        else if (s[i] == '(' && depth != 0)
        {
            ans += s[i];
            depth++;
        }
        else if (s[i] == ')' && depth == 1)
        {
            depth--;
        }
        else
        {
            ans += s[i];
            depth--;
        }
    }

    return ans;
}

int main()
{
    string s = "(()())(())";

    cout << "After removal: " << removeOuterParentheses(s);

    return 0;
}