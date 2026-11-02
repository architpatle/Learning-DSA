#include <iostream>
using namespace std;

int maxPower(string s)
{
    int count = 1, maxCout = 1;

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            count++;
            maxCout = max(maxCout, count);
        }
        else
        {
            count = 1;
        }
    }

    return maxCout;
}

int main()
{
    string s = "leetcode";

    cout << "Max Power: " << maxPower(s);

    return 0;
}