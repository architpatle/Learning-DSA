#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> Intersection(vector<int> nums1, vector<int> nums2)
{
    vector<int> ans;
    unordered_map<int, int> m;

    for (int i = 0; i < nums1.size(); i++)
    {
        m[nums1[i]]++;
    }

    for (int j = 0; j < nums2.size(); j++)
    {
        if (m.find(nums2[j]) != m.end() && m[nums2[j]] > 0)
        {
            ans.push_back(nums2[j]);
            m[nums2[j]]--;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums1 = {1, 3, 2, 4, 5, 2, 4};
    vector<int> nums2 = {2, 2, 0, 9, 4};

    vector<int> ans = Intersection(nums1, nums2);

    for (int val : ans)
    {
        cout << val << " ";
    }

    return 0;
}