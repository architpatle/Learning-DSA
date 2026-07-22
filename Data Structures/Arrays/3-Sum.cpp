#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// 3-Sum Problem

// 1. Brute Force Approach
vector<vector<int>> threeSumBFA(vector<int> arr) // TC: O(n^3 * log(uniqueTriplets)) | SC: O(uniqueTriplets)
{
    vector<vector<int>> ans;
    int n = arr.size();
    set<vector<int>> s;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> uniqueTriplet = {arr[i], arr[j], arr[k]};

                    sort(uniqueTriplet.begin(), uniqueTriplet.end());

                    if (s.find(uniqueTriplet) == s.end())
                    {
                        s.insert(uniqueTriplet);
                        ans.push_back(uniqueTriplet);
                    }
                }
            }
        }
    }

    return ans;
}

// 2. Hashing Based Approach
vector<vector<int>> threeSumHBA(vector<int> arr)
{ // TC: O(n^2 * log(uniqueTriplets)) | SC: O(uniqueTriplets+n)
    int n = arr.size();

    set<vector<int>> uniqueTriplet;

    for (int i = 0; i < n; i++)
    {
        int target = -arr[i];

        set<int> s;
        for (int j = i + 1; j < n; j++)
        {
            int third = target - arr[j];

            if (s.find(third) != s.end())
            {
                vector<int> triplets = {arr[i], arr[j], third};

                sort(triplets.begin(), triplets.end());

                uniqueTriplet.insert(triplets);
            }

            s.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(uniqueTriplet.begin(), uniqueTriplet.end());

    return ans;
}

// 3. Two Pointer Approach
vector<vector<int>> threeSumTPA(vector<int> arr) // TC: O(n^2 + nlog(n) | SC: O(uniqueTriplets)
{
    int n = arr.size();
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {

        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int j = i + 1, k = n - 1;

        while (j < k)
        {

            int sum = arr[i] + arr[j] + arr[k];

            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                ans.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;

                while (j < k && arr[j] == arr[j - 1])
                    j++;
            }
        }
    }

    return ans;
}

// ----- PRACTICE -----
vector<vector<int>> threeSumTPAPractice(vector<int> arr)
{
    vector<vector<int>> ans;
    int n = arr.size();

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int target = -arr[i];

        int j = i + 1, k = n - 1;

        while (j < k)       
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                ans.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;

                while (j < k && arr[j] == arr[j - 1])
                {
                    j++;
                }
            }
        }
    }

    return ans;
}

int main()
{

    vector<int> nums = {-1, 0, 1, 2, -1};

    vector<vector<int>> ans = threeSumTPA(nums);

    int m = ans.size(), n = ans[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}