#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    int n = strs.size();
    int minLength = strs[0].size();
    string ans = "";
    char ch;

    for (int i = 1; i < n; i++)
    {
        int length = strs[i].size();
        minLength = min(minLength, length);
    }

    for (int i = 0; i < minLength; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ch = strs[j][i];
            if (ch != strs[0][i])
            {
                return ans;
            }
        }
        ans.push_back(ch);
    }

    return ans;
    
}

int main()
{

    vector<string> strs = {"flower", "flow", "flowers"};

    string ans = longestCommonPrefix(strs);

    cout << "Longest Common Prefix: " << ans << endl;

    return 0;
}