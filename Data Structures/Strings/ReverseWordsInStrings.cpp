#include <iostream>
#include <algorithm>
using namespace std;

// Reverse Words In Strings
string ReverseWordsInStrings(string str)
{
    string ans = "";

    reverse(str.begin(), str.end());

    for (int i = 0; i < str.length(); i++)
    {

        string word = "";
        while (i < str.length() && str[i] != ' ')
        {
            word += str[i];
            i++;
        }
        reverse(word.begin(), word.end());

        if (word.length() > 0)
        {
            ans += " " + word;
        }
    }

    return ans.substr(1);
}

int main()
{
    string str = "Hello   d45g 453     world        ";

    cout << ReverseWordsInStrings(str);
    cout<<endl;

   
    string s = "abc";
    int k =4;
    for(int i =0; i<s.length(); i=i+(k*2)){
        if(s.length() - i <k){
            reverse(s.begin() + i, s.end());
        }else{
        reverse(s.begin() + i, s.begin() +i+ k);

        }
    }

    cout<<s;
    return 0;
}