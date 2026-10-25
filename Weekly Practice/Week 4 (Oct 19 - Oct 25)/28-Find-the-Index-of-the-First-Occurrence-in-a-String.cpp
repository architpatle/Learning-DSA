#include <iostream>
using namespace std;

int strStr(string str1, string str2)
{
    int count = 0;

    for (int i = 0; i < str1.size(); i++)
    {
        for (int j = 0; j < str2.size(); j++)
        {
            if (i + j >= str1.size())
            {
                break;
            }

            if (str2[j] != str1[i + j])
            {
                count = 0;
                break;
            }
            count++;
        }

        if (count == str2.size())
            return i;
    }

    return -1;
}

int main()
{
    string str1 = "sadbutsad", str2 = "tsa";

    cout << "Index: " << strStr(str1, str2);

    return 0;
}