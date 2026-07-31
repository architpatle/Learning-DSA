#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void FindAllSubsets(vector<int> &nums, vector<int> &oneSubset, int i, vector<vector<int>> &ans)
{
    if (i == nums.size())
    {
        ans.push_back(oneSubset);
        return;
    }

    // inclusion of ith element
    oneSubset.push_back(nums[i]);
    FindAllSubsets(nums, oneSubset, i + 1, ans);

    oneSubset.pop_back();

    int idx = i + 1;
    while (nums[idx] == nums[idx - 1] && idx < nums.size())
        i++;

    FindAllSubsets(nums, oneSubset, idx, ans);
}

vector<vector<int>> SubsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> oneSubset;

    sort(nums.begin(), nums.end());

    FindAllSubsets(nums, oneSubset, 0, ans);

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = SubsetsWithDup(nums);

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