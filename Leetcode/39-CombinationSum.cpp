#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<vector<int>> s;
void helper(vector<int> &arr, int tar, int idx, vector<vector<int>> &ans, vector<int> &oneCombination)
{
    if (idx == arr.size() || tar < 0)
    {
        return;
    }
    if (tar == 0)
    {
        if (s.find(oneCombination) == s.end())
        {
            ans.push_back(oneCombination);
            s.insert(oneCombination);
        }
        return;
    }

    // inclusion
    oneCombination.push_back(arr[idx]);

    // single inclusion
    helper(arr, tar - arr[idx], idx + 1, ans, oneCombination);

    // multiple inclusion
    helper(arr, tar - arr[idx], idx, ans, oneCombination);

    // exclusion
    oneCombination.pop_back();
    helper(arr, tar, idx + 1, ans, oneCombination);
}

vector<vector<int>> CombinationSum(vector<int> &arr, int tar)
{
    vector<vector<int>> ans;
    vector<int> oneCombination;

    helper(arr, tar, 0, ans, oneCombination);

    return ans;
}
int main()
{
    vector<int> candidates = {2, 3,4, 6, 7};
    int target = 8;

    vector<vector<int>> ans = CombinationSum(candidates, target);

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