#include <iostream>
#include <vector>
using namespace std;

int minMoves(vector<int> &nums)
{
    int maxNum = INT32_MIN, totalMoves = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        maxNum = max(maxNum, nums[i]);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != maxNum)
        {
            totalMoves += maxNum - nums[i];
        }
    }

    return totalMoves;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    cout << "Minimum moves: " << minMoves(nums);

    return 0;
}