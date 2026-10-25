#include <iostream>
using namespace std;

int lengthOfLastWord(string s)
{
    int i = s.size() - 1;
    int length = 0;

    while (i >= 0 && s[i] == ' ')
    {
        i--;
    }

    while (i >= 0 && s[i] != ' ')
    {
        i--;
        length++;
    }

    return length;
}

int main()
{
    string str = "      Hello there I'm someone       ";

    cout << "Length of Last Word: " << lengthOfLastWord(str);

    return 0;
}