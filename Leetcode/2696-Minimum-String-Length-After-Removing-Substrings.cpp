#include<iostream>
#include<stack>
using namespace std;

int minLength(string s) {
    stack<char> st;

    for(int i = 0; i<s.size(); i++){
        if(!st.empty() && ((st.top() == 'A' && s[i] == 'B') || (st.top() == 'C' && s[i] == 'D'))){
            st.pop();
        } else {
            st.push(s[i]);
        }
    }

    return st.size();

}

int main(){

    string s = "ABFCACDB";

    cout<<"Min Length: "<<minLength(s);

    return 0;
}