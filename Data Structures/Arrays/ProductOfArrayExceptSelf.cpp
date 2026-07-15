#include <iostream>
#include <vector>
using namespace std;

// 1. Product of Array Numbers Except Self (Brute Force)
vector<int> productOfArrayExceptSelf(vector<int> nums)
{
    vector<int> ans(nums.size(), 1);

    for (int i = 0; i < nums.size(); i++)
    {

        for (int j = 0; j < nums.size(); j++)
        {
            if (i != j)
            {
                ans[i] *= nums[j];
            }
        }
    }

    return ans;
}

// 2. Product of Array Numbers Except Self (Optimal)
vector<int> productOfArrayExceptSelfOM(vector<int> nums)
{

    vector<int> ans(nums.size(), 1);

    // prefix
    for (int i = 1; i < nums.size(); i++)
    {
        ans[i] = ans[i - 1] * nums[i - 1];
    }

    int suffix = 1;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        suffix *= nums[i + 1];
        ans[i] *= suffix;
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 4, 6, 10};

    // 1.
    //  vector<int> ans = productOfArrayExceptSelf(nums);

    // 2.
    vector<int> ans = productOfArrayExceptSelfOM(nums);

    for (int val : ans)
    {
        cout << val << " ";
    }

    return 0;
}