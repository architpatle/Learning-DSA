#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int l = 0, r = n - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;

        while (l < r)
        {
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);

            if (leftMax < rightMax)
            {
                ans += leftMax - height[l];
                l++;
            }
            else
            {
                ans += rightMax - height[r];
                r--;
            }
        }

        return ans;
    }
};

int main()
{
    Solution solution;

    // ==========================================
    // Test Case 1
    // Standard example
    // ==========================================

    vector<int> height1 = {
        0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    int ans1 = solution.trap(height1);

    cout << "Test Case 1: " << ans1 << endl;
    // Expected: 6

    // ==========================================
    // Test Case 2
    // No water can be trapped
    // ==========================================

    vector<int> height2 = {
        1, 2, 3, 4, 5};

    int ans2 = solution.trap(height2);

    cout << "Test Case 2: " << ans2 << endl;
    // Expected: 0

    // ==========================================
    // Test Case 3
    // Decreasing heights
    // ==========================================

    vector<int> height3 = {
        5, 4, 3, 2, 1};

    int ans3 = solution.trap(height3);

    cout << "Test Case 3: " << ans3 << endl;
    // Expected: 0

    // ==========================================
    // Test Case 4
    // Simple valley
    // ==========================================

    vector<int> height4 = {
        3, 0, 3};

    int ans4 = solution.trap(height4);

    cout << "Test Case 4: " << ans4 << endl;
    // Expected: 3

    // ==========================================
    // Test Case 5
    // Multiple valleys
    // ==========================================

    vector<int> height5 = {
        4, 2, 0, 3, 2, 5};

    int ans5 = solution.trap(height5);

    cout << "Test Case 5: " << ans5 << endl;
    // Expected: 9

    // ==========================================
    // Test Case 6
    // Single bar
    // ==========================================

    vector<int> height6 = {
        5};

    int ans6 = solution.trap(height6);

    cout << "Test Case 6: " << ans6 << endl;
    // Expected: 0

    // ==========================================
    // Test Case 7
    // All bars have same height
    // ==========================================

    vector<int> height7 = {
        3, 3, 3, 3, 3};

    int ans7 = solution.trap(height7);

    cout << "Test Case 7: " << ans7 << endl;
    // Expected: 0

    // ==========================================
    // Test Case 8
    // Complex case
    // ==========================================

    vector<int> height8 = {
        4, 1, 2, 1, 3, 0, 1, 2};

    int ans8 = solution.trap(height8);

    cout << "Test Case 8: " << ans8 << endl;
    // Expected: 7

    return 0;
}