#include<iostream>
using namespace std;

bool checkString(string s) {
    bool ans = true;

    for(int i = 1;i<s.size(); i++){
        if(s[i] == 'a' && s[i-1] == 'b'){
            ans = false;
            break;
        }
    }

    return ans;

}

int main(){
    string s = "aaabbb";

    cout<<checkString(s);

    return 0;
}