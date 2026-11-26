#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int leftLeafSum = 0;
        int rightLeafSum = 0;

        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
            leftLeafSum += root->left->val;

        if (root->left != NULL && (root->left->left != NULL || root->left->right != NULL))
            leftLeafSum = sumOfLeftLeaves(root->left);

        if (root->right != NULL && (root->right->left != NULL || root->right->right != NULL))
            rightLeafSum = sumOfLeftLeaves(root->right);

        return leftLeafSum + rightLeafSum;
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
    int result = sol.sumOfLeftLeaves(root);

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
    // Test 1: LeetCode Example 1
    runTest({3, 9, 20, INT_MIN, INT_MIN, 15, 7}, 24);

    // Test 2: LeetCode Example 2
    runTest({1}, 0);

    // Test 3: Only left leaf
    runTest({1, 2}, 2);

    // Test 4: Only right leaf
    runTest({1, INT_MIN, 2}, 0);

    // Test 5: Both children are leaves
    runTest({1, 2, 3}, 2);

    // Test 6: Multiple left leaves
    runTest({1, 2, 3, 4, 5, 6, 7}, 10);

    // Test 7: Left-skewed tree
    runTest({1, 2, INT_MIN, 3, INT_MIN, 4}, 4);

    // Test 8: Right-skewed tree
    runTest({1, INT_MIN, 2, INT_MIN, 3}, 0);

    // Test 9: Negative node values
    runTest({-1, -2, -3, -4, INT_MIN, INT_MIN, -5}, -4);

    // Test 10: Left leaf and right subtree
    runTest({1, 2, 3, INT_MIN, INT_MIN, 4, 5}, 2);

    // Test 11: Left subtree with multiple levels
    runTest({10, 5, 15, 3, 7, 12, 20}, 15);

    // Test 12: Only one left leaf deep in the tree
    runTest({1, 2, 3, 4, INT_MIN, INT_MIN, INT_MIN}, 4);

    return 0;
}