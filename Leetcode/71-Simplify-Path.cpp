#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

string simplifyPath(string path)
{
    stack<string> st;
    int i = 0;

    while (i < path.size())
    {
        string currPath = "";

        if (i < path.size() && path[i] == '/')
        {
            i++;
            continue;
        }

        while (i < path.size() && path[i] != '/')
        {
            currPath += path[i];
            i++;
        }

        if (currPath == ".")
        {
            continue;
        }
        else if (currPath == "..")
        {
            if (!st.empty())
                st.pop();
        }
        else
        {
            st.push(currPath);
        }
    }

    vector<string> temp;

    while(!st.empty()){
        temp.push_back("/" + st.top());
        st.pop();
    }

    reverse(temp.begin(), temp.end());

    string ans = "";

    for(string str: temp){
        ans+= str;
    }

    return ans.size() == 0 ? "/" : ans;

}

int main()
{
    string path = "/home/user/Documents/../Pictures";

    cout << "Simplified Path: " << simplifyPath(path);

    return 0;
}