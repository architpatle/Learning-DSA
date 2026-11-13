#include <iostream>
#include <vector>
using namespace std;

int longestMonotonicSubarray(vector<int> &nums)
{
    int incCount = 1, maxIncCount = 1;
    int decCount = 1, maxDecCount = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[i - 1])
        {
            incCount++;
            decCount = 1;
            maxIncCount = max(maxIncCount, incCount);
        }
        else if (nums[i] < nums[i - 1])
        {
            decCount++;
            incCount = 1;
            maxDecCount = max(maxDecCount, decCount);
        }
        else
        {
            decCount = 1;
            incCount = 1;
        }
    }

    return max(maxIncCount, maxDecCount);
}

int main()
{
    vector<int> nums = {1, 4, 3, 3, 2};

    cout << "Longest Strictly Increasing or Strictly Decreasing Subarray: " << longestMonotonicSubarray(nums);
    return 0;
}