#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<int> st;
        vector<int> ans(nums.size(), 0);
        int n = nums.size();

        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i % n])
            {
                st.pop();
            }

            ans[i % n] = st.empty() ? -1 : st.top();

            st.push(nums[i % n]);
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

    // ==========================================
    // Test Case 1
    // ==========================================

    vector<int> nums1 = {1, 2, 1};

    vector<int> ans1 = solution.nextGreaterElements(nums1);

    cout << "Test Case 1: ";
    printVector(ans1);

    // Expected: [2, -1, 2]

    // ==========================================
    // Test Case 2
    // ==========================================

    vector<int> nums2 = {1, 2, 3, 4, 3};

    vector<int> ans2 = solution.nextGreaterElements(nums2);

    cout << "Test Case 2: ";
    printVector(ans2);

    // Expected: [2, 3, 4, -1, 4]

    // ==========================================
    // Test Case 3
    // All elements are decreasing
    // ==========================================

    vector<int> nums3 = {5, 4, 3, 2, 1};

    vector<int> ans3 = solution.nextGreaterElements(nums3);

    cout << "Test Case 3: ";
    printVector(ans3);

    // Expected: [-1, 5, 5, 5, 5]

    // ==========================================
    // Test Case 4
    // All elements are equal
    // ==========================================

    vector<int> nums4 = {2, 2, 2, 2};

    vector<int> ans4 = solution.nextGreaterElements(nums4);

    cout << "Test Case 4: ";
    printVector(ans4);

    // Expected: [-1, -1, -1, -1]

    // ==========================================
    // Test Case 5
    // Single element
    // ==========================================

    vector<int> nums5 = {7};

    vector<int> ans5 = solution.nextGreaterElements(nums5);

    cout << "Test Case 5: ";
    printVector(ans5);

    // Expected: [-1]

    // ==========================================
    // Test Case 6
    // Increasing circular array
    // ==========================================

    vector<int> nums6 = {1, 2, 3, 4, 5};

    vector<int> ans6 = solution.nextGreaterElements(nums6);

    cout << "Test Case 6: ";
    printVector(ans6);

    // Expected: [2, 3, 4, 5, -1]

    // ==========================================
    // Test Case 7
    // Greater element exists only after wrapping
    // ==========================================

    vector<int> nums7 = {3, 2, 1};

    vector<int> ans7 = solution.nextGreaterElements(nums7);

    cout << "Test Case 7: ";
    printVector(ans7);

    // Expected: [-1, 3, 3]

    return 0;
}