#include <iostream>
using namespace std;

string digitSum(string s, int k)
{
    string ans = "";

    while (s.size() > k)
    {
        for (int i = 0; i < s.size(); i += k)
        {
            int num = 0;

            for (int j = i; j < s.size() && j < k + i; j++)
            {
                num += s[j] - '0';
            }

            ans += to_string(num);
        }
        s = ans;
        ans = "";
    }

    return s;
}

int main()
{
    string s = "11111222223";
    int k = 3;

    cout << "Digit Sum: " << digitSum(s, k);

    return 0;
}