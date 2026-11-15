#include <iostream>
#include <vector>
using namespace std;

int minimumSumSubarray(vector<int> &nums, int l, int r)
{
    int minSum = INT32_MAX;

    for (int i = 0; i < nums.size(); i++)
    {
        int currSum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            currSum += nums[j];

            if (j - i + 1 >= l && j - i + 1 <= r && currSum > 0)
            {
                minSum = min(minSum, currSum);
            }
        }
    }

    return minSum == INT32_MAX ? -1 : minSum;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    int l = 2;
    int r = 4;

    cout << "Min SubArray Sum: " << minimumSumSubarray(nums, l, r);

    return 0;
}