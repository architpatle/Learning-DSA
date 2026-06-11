#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1. Majority Element in an array using Brute Force Algorithm
int majorityElementBF(vector<int> nums)
{
    int size = nums.size();

    for (int i = 0; i < size; i++)
    {
        int counter = 0;
        for (int j = 0; j < size; j++)
        {
            if (nums[i] == nums[j])
            {
                counter++;
            }
        }
        if (counter > (size / 2))
        {
            return nums[i];
        }
    }
}

// 2. Majority element in an array using Sort-An-Array Method
int majorityElementSAA(vector<int> nums)
{
    int size = nums.size();

    // sort
    sort(nums.begin(), nums.end());

    int frequency = 1;
    int ans = nums[0];

    for (int i = 1; i < size; i++)
    {

        if (nums[i] == nums[i - 1])
        {
            frequency++;
        }
        else
        {
            frequency = 1;
            ans = nums[i];
        }

        if (frequency > (size / 2))
        {
            return ans;
        }
    }

    return ans;
}

// 3. Majority Element in an Array using Moore's Voting Algorithm
int majorityElemenetMV(vector<int> nums)
{
    int size = nums.size();
    int freq = 0;
    int ans = 0;

    for (int i = 0; i < size; i++)
    {
        if (freq == 0)
        {
            ans = nums[i];
        }

        if (ans == nums[i])
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 2, 1, 2, 2, 1, 2, 1, 1, 1, 1};

    // 1.
    // cout << "Majority Element: " << majorityElementBF(nums);

    // 2.
    // cout << "Majority Element: " << majorityElementSAA(nums);

    // 3.
    cout << "Majority Element: " << majorityElemenetMV(nums);
    return 0;
}