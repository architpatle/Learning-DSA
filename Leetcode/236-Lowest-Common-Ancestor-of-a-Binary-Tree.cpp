#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return root;

        if (root->val == p->val || root->val == q->val)
            return root;

        TreeNode *leftTree = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightTree = lowestCommonAncestor(root->right, p, q);

        if (leftTree && rightTree)
        {
            return root;
        }
        else if (leftTree != NULL)
        {
            return leftTree;
        }
        else
        {
            rightTree;
        }
    }
};

// Build binary tree from level-order input.
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

TreeNode *findNode(TreeNode *root, int val)
{
    if (root == NULL)
        return NULL;

    if (root->val == val)
        return root;

    TreeNode *left = findNode(root->left, val);
    if (left != NULL)
        return left;

    return findNode(root->right, val);
}

void runTest(vector<int> arr, int pVal, int qVal, int expected)
{
    TreeNode *root = buildTree(arr);

    TreeNode *p = findNode(root, pVal);
    TreeNode *q = findNode(root, qVal);

    Solution sol;
    TreeNode *result = sol.lowestCommonAncestor(root, p, q);

    cout << "Tree: ";
    for (int val : arr)
    {
        if (val == INT_MIN)
            cout << "NULL ";
        else
            cout << val << " ";
    }

    cout << "\np = " << pVal
         << ", q = " << qVal
         << "\nOutput: " << (result ? result->val : -1)
         << "\nExpected: " << expected
         << "\n--------------------------\n";
}

int main()
{
    // Test 1
    runTest({3, 5, 1, 6, 2, 0, 8, INT_MIN, INT_MIN, 7, 4}, 5, 1, 3);

    // Test 2
    runTest({3, 5, 1, 6, 2, 0, 8, INT_MIN, INT_MIN, 7, 4}, 5, 4, 5);

    // Test 3
    runTest({1, 2}, 1, 2, 1);

    // Test 4
    runTest({1, 2, 3}, 2, 3, 1);

    // Test 5
    runTest({1, 2, 3, 4, 5}, 4, 5, 2);

    // Test 6
    runTest({1, 2, 3, 4, 5}, 4, 3, 1);

    // Test 7
    runTest({1, 2, 3, 4, 5}, 2, 4, 2);

    // Test 8
    runTest({1, 2, 3, INT_MIN, 4, INT_MIN, 5}, 4, 5, 1);

    // Test 9
    runTest({10, 5, 15, 3, 7, 12, 20}, 3, 7, 5);

    // Test 10
    runTest({10, 5, 15, 3, 7, 12, 20}, 3, 20, 10);

    // Test 11
    runTest({1}, 1, 1, 1);

    // Test 12
    runTest({1, 2, 3, 4, 5, 6, 7}, 6, 7, 3);

    return 0;
}