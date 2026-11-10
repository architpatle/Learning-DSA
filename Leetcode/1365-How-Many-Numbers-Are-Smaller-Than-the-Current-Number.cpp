#include <iostream>
#include <vector>
using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (i != j && nums[j] < nums[i])
            {
                count++;
            }
        }
        ans.push_back(count);
        count = 0;
    }

    return ans;
}

int main()
{
    vector<int> nums = {6, 5, 4, 8};

    vector<int> ans = smallerNumbersThanCurrent(nums);

    for (int val : ans)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}