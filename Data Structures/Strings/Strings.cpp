#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalindrome(string str)
{

    int start = 0, end = str.size() - 1;
    while (start < end)
    {
        bool status;
        if (str[start] == str[end])
        {
            status = true;
        }
        else
        {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

int main()
{

    string s = "pall";

    vector<char> str = {'h', 'e', 'l', 'e', 'h'};

    // Reverse a String

    // int start = 0, end = str.size()-1;
    // while(start<=end){
    //     swap(str[start], str[end]);
    //     start++;
    //     end--;
    // }

    // for(char ch: str){
    //     cout<<ch<<" ";
    // }

    // isPalindrome

    cout << isPalindrome(s);

    return 0;
}