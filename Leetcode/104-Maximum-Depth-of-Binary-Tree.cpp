#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return max(leftDepth, rightDepth) + 1;
    }
};

// INT_MIN represents NULL.
TreeNode *buildTree(vector<int> arr)
{
    if (arr.empty() || arr[0] == INT_MIN)
        return NULL;

    TreeNode *root = new TreeNode(arr[0]);
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size())
    {
        TreeNode *curr = q.front();
        q.pop();

        if (i < arr.size() && arr[i] != INT_MIN)
        {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i < arr.size() && arr[i] != INT_MIN)
        {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

void runTest(vector<int> arr, int expected)
{
    TreeNode *root = buildTree(arr);

    Solution sol;
    int result = sol.maxDepth(root);

    cout << "Input: ";
    for (int val : arr)
    {
        if (val == INT_MIN)
            cout << "null ";
        else
            cout << val << " ";
    }

    cout << "\nOutput: " << result;
    cout << "\nExpected: " << expected;
    cout << "\n-----------------------------\n";
}

int main()
{
    // Test 1
    runTest({3, 9, 20, INT_MIN, INT_MIN, 15, 7}, 3);

    // Test 2
    runTest({1, INT_MIN, 2}, 2);

    // Test 3
    runTest({}, 0);

    // Test 4
    runTest({1}, 1);

    // Test 5
    runTest({1, 2, 3}, 2);

    // Test 6
    runTest({1, 2, INT_MIN, 3}, 3);

    // Test 7
    runTest({1, INT_MIN, 2, INT_MIN, 3}, 3);

    // Test 8
    runTest({1, 2, 3, 4, 5, 6, 7}, 3);

    // Test 9
    runTest({5, 3, 8, 2, 4, 7, 9}, 3);

    // Test 10
    runTest({-10, -20, -5, -30, INT_MIN, INT_MIN, 0}, 3);

    // Test 11
    runTest({1, 2, 3, INT_MIN, 4, 5, INT_MIN, INT_MIN, 6}, 4);

    // Test 12
    runTest({10, 5, 15, INT_MIN, 7, 12, 20}, 3);

    return 0;
}