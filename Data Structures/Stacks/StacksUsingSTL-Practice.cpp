#include<iostream>
#include<stack>
using namespace std;

int main(){

    stack<int> st;

    st.push(9);
    st.push(8);
    st.push(7);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

    return 0;
}