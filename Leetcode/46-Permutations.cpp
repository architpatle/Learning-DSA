#include <iostream>
#include <vector>
using namespace std;

void getPer(vector<int> &nums, vector<vector<int>> &ans, int idx)
{

    if (idx == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[i], nums[idx]);

        getPer(nums, ans, idx + 1);
        swap(nums[i], nums[idx]);
    }
}

vector<vector<int>> Permutation(vector<int> &nums)
{
    vector<vector<int>> ans;

    getPer(nums, ans, 0);

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = Permutation(nums);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}