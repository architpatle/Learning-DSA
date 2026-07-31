#include <iostream>
#include <vector>
using namespace std;

void getAllStrings(string &str, int idx)
{
    if (idx == str.size())
    {
        for (int i = 0; i < str.size(); i++)
        {
            cout << str[i];
        }
        cout << endl;
    }

    for (int i = idx; i < str.size(); i++)
    {
        swap(str[idx], str[i]);

        getAllStrings(str, idx+1);

        swap(str[idx], str[i]);
    }
}

int main()
{

    string str = "abc";
    // vector<string> ans;

    getAllStrings(str, 0);
    return 0;
}