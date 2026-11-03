#include <iostream>
using namespace std;

bool checkZeroOnes(string s)
{
    int currZero = 0, maxZero = 0, currOne = 0, maxOne = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            currOne++;
            maxOne = max(maxOne, currOne);
            currZero = 0;
        }
        else
        {
            currZero++;
            maxZero = max(maxZero, currZero);
            currOne = 0;
        }
    }
    return maxOne > maxZero ? true : false;
}

int main()
{
    string s1 = "11000";
    string s2 = "11001111000100";

    cout << checkZeroOnes(s1) << endl;
    cout << checkZeroOnes(s2);

    return 0;
}