#include <iostream>
using namespace std;

// Remove All Occurances Of A Substring
string RemoveAllOccurancesOfASubstring(string str, string part)
{

    while (str.length() > 0 && str.find(part) < str.length())
    {
        str.erase(str.find(part), part.length());
    }

    return str;
}

string RemoveAllOccurancesOfASubstringPractice(string str, string part){
    while(str.length()>0 && str.find(part) < str.length()){
        str.erase(str.find(part), part.length());
    }
    return str;
}
int main()
{

    string str = "abcbcaabc";
    string part = "abc";

    cout << RemoveAllOccurancesOfASubstringPractice(str, part);
    return 0;
}