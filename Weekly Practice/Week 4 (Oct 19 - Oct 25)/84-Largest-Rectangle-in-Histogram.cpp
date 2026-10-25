#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();

        stack<int> st;

        vector<int> left(heights.size(), 0);
        vector<int> right(heights.size(), 0);

        int ans = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            right[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        while (!st.empty())
        {
            st.pop();
        }

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            left[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        for (int i = 0; i < n; i++)
        {

            int width = right[i] - left[i] - 1;

            int area = heights[i] * width;

            ans = max(area, ans);
        }

        return ans;
    }
};

int main()
{
    Solution solution;

    // ==========================================
    // Test Case 1
    // ==========================================

    vector<int> heights1 = {2, 1, 5, 6, 2, 3};

    int ans1 = solution.largestRectangleArea(heights1);

    cout << "Test Case 1: " << ans1 << endl;
    // Expected: 10

    // ==========================================
    // Test Case 2
    // ==========================================

    vector<int> heights2 = {2, 4};

    int ans2 = solution.largestRectangleArea(heights2);

    cout << "Test Case 2: " << ans2 << endl;
    // Expected: 4

    // ==========================================
    // Test Case 3
    // All bars have same height
    // ==========================================

    vector<int> heights3 = {5, 5, 5, 5};

    int ans3 = solution.largestRectangleArea(heights3);

    cout << "Test Case 3: " << ans3 << endl;
    // Expected: 20

    // ==========================================
    // Test Case 4
    // Increasing heights
    // ==========================================

    vector<int> heights4 = {1, 2, 3, 4, 5};

    int ans4 = solution.largestRectangleArea(heights4);

    cout << "Test Case 4: " << ans4 << endl;
    // Expected: 9

    // ==========================================
    // Test Case 5
    // Decreasing heights
    // ==========================================

    vector<int> heights5 = {5, 4, 3, 2, 1};

    int ans5 = solution.largestRectangleArea(heights5);

    cout << "Test Case 5: " << ans5 << endl;
    // Expected: 9

    // ==========================================
    // Test Case 6
    // Single bar
    // ==========================================

    vector<int> heights6 = {7};

    int ans6 = solution.largestRectangleArea(heights6);

    cout << "Test Case 6: " << ans6 << endl;
    // Expected: 7

    // ==========================================
    // Test Case 7
    // Contains zero
    // ==========================================

    vector<int> heights7 = {2, 0, 2};

    int ans7 = solution.largestRectangleArea(heights7);

    cout << "Test Case 7: " << ans7 << endl;
    // Expected: 2

    // ==========================================
    // Test Case 8
    // Larger central rectangle
    // ==========================================

    vector<int> heights8 = {6, 2, 5, 4, 5, 1, 6};

    int ans8 = solution.largestRectangleArea(heights8);

    cout << "Test Case 8: " << ans8 << endl;
    // Expected: 12

    return 0;
}