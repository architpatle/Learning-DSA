#include <iostream>
using namespace std;

int maxDepth(string s)
{
    int maxDepthVal = 0;
    int currDepth = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            currDepth++;
            maxDepthVal = max(maxDepthVal, currDepth);
        }
        else if (s[i] == ')')
        {
            currDepth--;
        }
        else
        {
            continue;
        }
    }

    maxDepthVal;
}

int main()
{
    string s = "(1+(2*3)+((8)/4))+1";

    cout << "Max Depth: " << maxDepth(s);

    return 0;
}