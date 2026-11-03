#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        deque<int> dq;

        // 1st window
        for (int i = 0; i < k; i++)
        {
            // remvoing smaller elements than current element from deque's back
            while (dq.size() > 0 && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for (int i = k; i < nums.size(); i++)
        {
            ans.push_back(nums[dq.front()]);

            // removing elements from previous window from dq
            while (dq.size() > 0 && dq.front() <= i - k)
            {
                dq.pop_front();
            }

            // remvoing smaller elements than current element from deque's back
            while (dq.size() > 0 && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        ans.push_back(nums[dq.front()]);

        return ans;
    }
};

void printVector(const vector<int> &nums)
{
    cout << "[";

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];

        if (i != nums.size() - 1)
            cout << ", ";
    }

    cout << "]";
}

void runTest(vector<int> nums, int k)
{
    Solution sol;

    vector<int> result = sol.maxSlidingWindow(nums, k);

    cout << "Input: ";
    printVector(nums);

    cout << "\nk = " << k;

    cout << "\nOutput: ";
    printVector(result);

    cout << "\n-----------------------------\n";
}

int main()
{

    // Test 1
    runTest({1, 3, -1, -3, 5, 3, 6, 7}, 3);
    // Expected: [3, 3, 5, 5, 6, 7]

    // Test 2
    runTest({1}, 1);
    // Expected: [1]

    // Test 3
    runTest({1, -1}, 1);
    // Expected: [1, -1]

    // Test 4
    runTest({1, -1}, 2);
    // Expected: [1]

    // Test 5
    runTest({9, 11}, 2);
    // Expected: [11]

    // Test 6
    runTest({4, 3, 2, 1}, 2);
    // Expected: [4, 3, 2]

    // Test 7
    runTest({1, 2, 3, 4, 5}, 3);
    // Expected: [3, 4, 5]

    // Test 8
    runTest({5, 4, 3, 2, 1}, 3);
    // Expected: [5, 4, 3]

    // Test 9
    runTest({7, 7, 7, 7}, 2);
    // Expected: [7, 7, 7]

    // Test 10
    runTest({1, 3, 1, 2, 0, 5}, 3);
    // Expected: [3, 3, 2, 5]

    // Test 11
    runTest({-1, -3, -5, -2, -1, -4}, 3);
    // Expected: [-1, -2, -1, -1]

    // Test 12
    runTest({10, 5, 2, 7, 8, 7}, 4);
    // Expected: [10, 8, 8]

    return 0;
}