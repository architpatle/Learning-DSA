#include <iostream>
#include <vector>
using namespace std;

void FindSubset(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &AllSubsets)
{
    if (i == nums.size())
    {
        AllSubsets.push_back({ans});
        return;
    }

    ans.push_back(nums[i]);
    FindSubset(nums, ans, i + 1, AllSubsets);

    ans.pop_back();
    FindSubset(nums, ans, i + 1, AllSubsets);
}

vector<vector<int>> Subsets(vector<int> &nums)
{
    vector<vector<int>> AllSubsets;
    vector<int> ans;

    FindSubset(nums, ans, 0, AllSubsets);

    return AllSubsets;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = Subsets(nums);

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