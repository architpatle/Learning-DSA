#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> finalPrices(vector<int> &prices)
{
    int n = prices.size();

    vector<int> ans(n, 0);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() > prices[i])
        {
            st.pop();
        }

        ans[i] = st.empty() ? prices[i] : prices[i] - st.top();

        st.push(prices[i]);
    }

    return ans;
}

int main()
{
    vector<int> prices = {8, 4, 6, 2, 3};

    vector<int> ans = finalPrices(prices);

    cout << "Final Discounted Price: ";

    for (int val : ans)
    {
        cout << val << " ";
    }

    return 0;
}