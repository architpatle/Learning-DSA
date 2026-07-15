#include <iostream>
#include <vector>
using namespace std;

// 1. Pair Sum (Brute Force Approach)
vector<int> pairSumBF(vector<int> nums, int target)
{
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }

    return ans;
}

// 2. Pair Sum (Two Pointer Approach)
vector<int> pairSumTP(vector<int> nums, int target)
{
    int size = nums.size();
    int start = 0;
    int end = size - 1;

    vector<int> ans;

    while (nums[start] < nums[end])
    {
        int pairSum = nums[start] + nums[end];

        if (pairSum > target)
        {
            end--;
        }
        else if (pairSum < target)
        {
            start++;
        }
        else
        {
            ans.push_back(start);
            ans.push_back(end);
            return ans;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {0, 2, 7, 11, 15};
    int target = 22;

    // 1.
    //  vector<int> ans = pairSumBF(nums, target);

    // cout << ans[0] << ", " << ans[1];

    // 2.
    vector<int> ans = pairSumTP(nums, target);

    cout << ans[0] << ", " << ans[1];

    return 0;
}