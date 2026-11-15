#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return false;

        if (targetSum - root->val == 0 && root->left == NULL && root->right == NULL)
            return true;

        bool leftSum = hasPathSum(root->left, targetSum - root->val);
        bool rightSum = hasPathSum(root->right, targetSum - root->val);

        return leftSum || rightSum;
    }
};

// Build binary tree from level-order input
// -1 represents a NULL node.
TreeNode *createTree(vector<int> values)
{
    if (values.empty() || values[0] == -1)
        return nullptr;

    TreeNode *root = new TreeNode(values[0]);
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < values.size())
    {
        TreeNode *current = q.front();
        q.pop();

        if (values[i] != -1)
        {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;

        if (i < values.size() && values[i] != -1)
        {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

void runTest(vector<int> values, int targetSum)
{
    TreeNode *root = createTree(values);

    Solution sol;
    bool result = sol.hasPathSum(root, targetSum);

    cout << "Tree: [";
    for (int i = 0; i < values.size(); i++)
    {
        cout << values[i];
        if (i != values.size() - 1)
            cout << ", ";
    }

    cout << "]\nTarget Sum: " << targetSum;
    cout << "\nOutput: " << (result ? "true" : "false");
    cout << "\n-----------------------------\n";
}

int main()
{

    // Test 1
    runTest({5, 4, 8, 11, 13, 4, 7, 2, -1, -1, -1, -1, 1}, 22);
    // Expected: true
    // Path: 5 -> 4 -> 11 -> 2

    // Test 2
    runTest({1, 2, 3}, 5);
    // Expected: false

    // Test 3
    runTest({}, 0);
    // Expected: false

    // Test 4
    runTest({1}, 1);
    // Expected: true

    // Test 5
    runTest({1}, 2);
    // Expected: false

    // Test 6
    runTest({1, 2}, 1);
    // Expected: false
    // Reaching node 1 is not enough; it is not a leaf.

    // Test 7
    runTest({1, 2, 3}, 4);
    // Expected: true
    // Path: 1 -> 3

    // Test 8
    runTest({1, 2, 3, 4, 5}, 8);
    // Expected: true
    // Path: 1 -> 2 -> 5

    // Test 9
    runTest({-2, -3, -4}, -5);
    // Expected: true
    // Path: -2 -> -3

    // Test 10
    runTest({1, -2, -3, 1, 3, -2, -1}, -1);
    // Expected: true
    // Path: 1 -> -2 -> 1 -> -1

    // Test 11
    runTest({1, 2, 3, -1, -1, 4, 5}, 8);
    // Expected: true
    // Path: 1 -> 3 -> 4

    // Test 12
    runTest({1, 2, 3, 4, -1, -1, 5}, 7);
    // Expected: false

    return 0;
}