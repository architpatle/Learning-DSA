#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <cmath>
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
    bool ans = true;
    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if (abs(leftHeight - rightHeight) > 1)
        {
            ans = false;
            return 0;
        }

        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode *root)
    {
        height(root);
        return ans;
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

void runTest(vector<int> arr, bool expected)
{
    TreeNode *root = buildTree(arr);

    Solution sol;
    bool result = sol.isBalanced(root);

    cout << "Input: ";
    for (int val : arr)
    {
        if (val == INT_MIN)
            cout << "null ";
        else
            cout << val << " ";
    }

    cout << "\nOutput:   " << (result ? "true" : "false");
    cout << "\nExpected: " << (expected ? "true" : "false");
    cout << "\n-----------------------------\n";
}

int main()
{
    // Test 1: LeetCode Example 1
    runTest({3, 9, 20, INT_MIN, INT_MIN, 15, 7}, true);

    // Test 2: LeetCode Example 2
    runTest({1, 2, 2, 3, 3, INT_MIN, INT_MIN, 4, 4}, false);

    // Test 3: Empty tree
    runTest({}, true);

    // Test 4: Single node
    runTest({1}, true);

    // Test 5: Two nodes
    runTest({1, 2}, true);

    // Test 6: Balanced complete binary tree
    runTest({1, 2, 3, 4, 5, 6, 7}, true);

    // Test 7: Left-skewed tree
    runTest({1, 2, INT_MIN, 3, INT_MIN, 4}, false);

    // Test 8: Right-skewed tree
    runTest({1, INT_MIN, 2, INT_MIN, 3, INT_MIN, 4}, false);

    // Test 9: Unbalanced left subtree
    runTest({1, 2, 3, 4, INT_MIN, INT_MIN, INT_MIN, 5}, false);

    // Test 10: Balanced but not complete
    runTest({1, 2, 3, 4, INT_MIN, INT_MIN, 5}, true);

    // Test 11: Negative node values
    runTest({-10, -20, -5, -30, INT_MIN, INT_MIN, 0}, true);

    // Test 12: Height difference exactly 1 at each node
    runTest({1, 2, 3, 4, 5, INT_MIN, INT_MIN}, true);

    return 0;
}