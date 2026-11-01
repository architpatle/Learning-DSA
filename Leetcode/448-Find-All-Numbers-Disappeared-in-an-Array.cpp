#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        unordered_set<int> s;
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            s.insert(nums[i]);
        }

        for(int i = 1; i<=n; i++){
            if(s.find(i) == s.end()){
                ans.push_back(i);
            }
        }

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

void runTest(vector<int> nums)
{
    Solution sol;

    vector<int> result = sol.findDisappearedNumbers(nums);

    cout << "Input: ";
    printVector(nums);

    cout << "\nOutput: ";
    printVector(result);

    cout << "\n";
    cout << "-----------------------------\n";
}

int main()
{

    // Test 1
    runTest({4, 3, 2, 7, 8, 2, 3, 1});
    // Expected: [5, 6]

    // Test 2
    runTest({1, 1});
    // Expected: [2]

    // Test 3
    runTest({1, 2, 3, 4, 5});
    // Expected: []

    // Test 4
    runTest({2, 2, 2, 2});
    // Expected: [1, 3, 4]

    // Test 5
    runTest({1});
    // Expected: []

    // Test 6
    runTest({2, 1});
    // Expected: []

    // Test 7
    runTest({5, 4, 3, 2, 2});
    // Expected: [1]

    // Test 8
    runTest({1, 1, 2, 2, 3, 3});
    // Expected: [4, 5, 6]

    return 0;
}