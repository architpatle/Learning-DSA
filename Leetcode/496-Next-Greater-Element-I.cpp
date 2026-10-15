#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        stack<int> st;
        unordered_map<int, int> m;

        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while ((!st.empty()) && (st.top() <= nums2[i]))
            {
                st.pop();
            }

            if (st.empty())
            {
                m[nums2[i]] = -1;
            }
            else
            {
                m[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        for (int val : nums1)
        {
            ans.push_back(m[val]);
        }

        return ans;
    }
};

// Helper function to print vector
void printVector(vector<int> &nums)
{
    cout << "[";

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];

        if (i != nums.size() - 1)
            cout << ", ";
    }

    cout << "]" << endl;
}

int main()
{
    Solution solution;

    // =========================
    // Test Case 1
    // =========================
    vector<int> nums1_1 = {4, 1, 2};
    vector<int> nums2_1 = {1, 3, 4, 2};

    vector<int> ans1 = solution.nextGreaterElement(nums1_1, nums2_1);

    cout << "Test Case 1: ";
    printVector(ans1);

    // Expected: [-1, 3, -1]

    // =========================
    // Test Case 2
    // =========================
    vector<int> nums1_2 = {2, 4};
    vector<int> nums2_2 = {1, 2, 3, 4};

    vector<int> ans2 = solution.nextGreaterElement(nums1_2, nums2_2);

    cout << "Test Case 2: ";
    printVector(ans2);

    // Expected: [3, -1]

    // =========================
    // Test Case 3
    // =========================
    vector<int> nums1_3 = {1, 3, 5, 2};
    vector<int> nums2_3 = {6, 5, 4, 3, 2, 1};

    vector<int> ans3 = solution.nextGreaterElement(nums1_3, nums2_3);

    cout << "Test Case 3: ";
    printVector(ans3);

    // Expected: [-1, -1, -1, -1]

    // =========================
    // Test Case 4
    // =========================
    vector<int> nums1_4 = {2, 4};
    vector<int> nums2_4 = {1, 3, 2, 4};

    vector<int> ans4 = solution.nextGreaterElement(nums1_4, nums2_4);

    cout << "Test Case 4: ";
    printVector(ans4);

    // Expected: [4, -1]

    // =========================
    // Test Case 5
    // =========================
    vector<int> nums1_5 = {1};
    vector<int> nums2_5 = {1, 2};

    vector<int> ans5 = solution.nextGreaterElement(nums1_5, nums2_5);

    cout << "Test Case 5: ";
    printVector(ans5);

    // Expected: [2]

    return 0;
}