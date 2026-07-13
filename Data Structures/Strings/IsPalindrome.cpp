#include <iostream>
using namespace std;


// isPalindorme Problem

bool isAlphaNumeric(char ch){
    if((ch>= '0' && ch<='9') || (tolower(ch)>= 'a' && tolower(ch)<= 'z')){
        return true; 
    } else{
        return false;
    }
}
bool isPalindrome(string str){
    int start = 0, end= str.length() -1;

    while(start<end){
        if(!isAlphaNumeric(str[start])){
            start++;
            continue;
        }

        if(!isAlphaNumeric(str[end])){
            end--;
            continue;
        }

        if(tolower(str[start]) != tolower(str[end])){
            return false;
        }

        start++;
        end--;

    }
    return true;
}

int main()
{
    string str = "A man, a plan, a canal: Panama";

    cout<< isPalindrome(str);
    return 0;
}
