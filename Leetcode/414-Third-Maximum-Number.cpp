#include <iostream>
#include <vector>
#include <initializer_list>
#include <set>
using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        set<int> s;

        for (int i = 0; i < nums.size(); i++)
        {
            s.insert(nums[i]);
        }

        if (s.size() >= 3)
        {
            auto it = s.rbegin();
            advance(it, 2);

            return *it;
        }
        else
        {
            return *s.rbegin();
        }
    }
};

// Print vector
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

// Run test case
void runTest(initializer_list<int> values)
{

    vector<int> nums(values);

    Solution sol;

    int result = sol.thirdMax(nums);

    cout << "Input: ";
    printVector(nums);

    cout << "\nOutput: "
         << result
         << endl;

    cout << "-----------------------------" << endl;
}

int main()
{

    // Test Case 1
    // Input: [3,2,1]
    // Expected: 1
    runTest({3, 2, 1});

    // Test Case 2
    // Input: [1,2]
    // Expected: 2
    runTest({1, 2});

    // Test Case 3
    // Input: [2,2,3,1]
    // Distinct values: 3,2,1
    // Expected: 1
    runTest({2, 2, 3, 1});

    // Test Case 4
    // Input: [1,2,2,5,3,5]
    // Distinct values: 5,3,2,1
    // Expected: 2
    runTest({1, 2, 2, 5, 3, 5});

    // Test Case 5
    // Only one distinct value
    // Expected: 5
    runTest({5, 5, 5, 5});

    // Test Case 6
    // Exactly three distinct values with duplicates
    // Expected: 1
    runTest({1, 1, 2, 2, 3, 3});

    // Test Case 7
    // Negative values
    // Distinct values: 3,2,1,-1,-2
    // Expected: 1
    runTest({-2, -1, 1, 2, 3});

    // Test Case 8
    // Three distinct negative values
    // Expected: -3
    runTest({-1, -2, -3});

    // Test Case 9
    // Two distinct negative values
    // Expected: -1
    runTest({-2, -1, -2, -1});

    // Test Case 10
    // Maximum value repeated
    // Distinct values: 10,5,1
    // Expected: 1
    runTest({10, 10, 5, 5, 1, 1});

    return 0;
}