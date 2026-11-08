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
    bool isIdentical(TreeNode *p, TreeNode *q)
    {
        if (p == NULL || q == NULL)
            return p == q;

        return p->val == q->val && isIdentical(p->left, q->left) && isIdentical(p->right, q->right);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == NULL || subRoot == NULL)
            return root == subRoot;

        if (root->val == subRoot->val && isIdentical(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
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

void runTest(vector<int> rootValues, vector<int> subValues)
{
    TreeNode *root = createTree(rootValues);
    TreeNode *subRoot = createTree(subValues);

    Solution sol;
    bool result = sol.isSubtree(root, subRoot);

    cout << "Root: [";
    for (int i = 0; i < rootValues.size(); i++)
    {
        cout << rootValues[i];
        if (i != rootValues.size() - 1)
            cout << ", ";
    }

    cout << "]\nSubRoot: [";
    for (int i = 0; i < subValues.size(); i++)
    {
        cout << subValues[i];
        if (i != subValues.size() - 1)
            cout << ", ";
    }

    cout << "]\nOutput: " << (result ? "true" : "false");
    cout << "\n-----------------------------\n";
}

int main()
{

    // Test 1
    runTest(
        {3, 4, 5, 1, 2},
        {4, 1, 2});
    // Expected: true

    // Test 2
    runTest(
        {3, 4, 5, 1, 2, -1, -1, -1, -1, 0},
        {4, 1, 2});
    // Expected: false

    // Test 3
    runTest(
        {1, 2, 3, 4, 5},
        {2, 4, 5});
    // Expected: true

    // Test 4
    runTest(
        {1, 2, 3, 4, 5},
        {2, 4});
    // Expected: false

    // Test 5
    runTest(
        {1},
        {1});
    // Expected: true

    // Test 6
    runTest(
        {1, 2, 3},
        {4});
    // Expected: false

    // Test 7
    runTest(
        {},
        {1});
    // Expected: false

    // Test 8
    runTest(
        {1, 2, 3},
        {});
    // Expected: false

    // Test 9
    runTest(
        {1, 1, 1, 1, 1},
        {1, 1});
    // Expected: false

    // Test 10
    runTest(
        {1, 2, 3, -1, 4},
        {2, -1, 4});
    // Expected: true

    // Test 11
    runTest(
        {5, 4, 6, 3, -1, -1, 7},
        {4, 3});
    // Expected: true

    // Test 12
    runTest(
        {-1},
        {-1});
    // Expected: true

    return 0;
}