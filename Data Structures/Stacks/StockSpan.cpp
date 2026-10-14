#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    // stock prices
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    // solution
    vector<int> ans(price.size(), 0);
    stack<int> st;

    for (int i = 0; i < price.size(); i++)
    {
        // removing values from stack top which are <= today's value
        while ((st.size() > 0) && (price[st.top()] <= price[i]))
        {
            st.pop();
        }

        if (st.size() == 0)
            {
                ans[i] = i + 1;
            }
            else
            {
                ans[i] = i - st.top();
            }

            st.push(i);
    }

    // print ans array
    for(int val:ans){
        cout<<val<<" ";
    }

    return 0;
}