#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // vector<int> vec(4, 30);

    // for (int val : vec)
    // {
    //     cout << val << " ";
    // }

    vector<int> vec = {4, 2, 3, 2, 3};

    int ans = 0;

    for (int val : vec)
    {
        ans = ans ^ val;
    }

    // int val = 6 ^ 6;

    // cout<<val;
    cout<<ans;

    return 0;
}