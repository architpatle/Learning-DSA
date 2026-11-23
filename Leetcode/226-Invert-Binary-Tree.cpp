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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
            return root;

        swap(root->left, root->right);

        invertTree(root->left);
        invertTree(root->right);

        return root;
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

// Convert tree to level-order representation.
vector<int> getLevelOrder(TreeNode *root)
{
    vector<int> result;

    if (root == NULL)
        return result;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();

        result.push_back(curr->val);

        if (curr->left)
        {
            q.push(curr->left);
        }
        else
        {
            result.push_back(INT_MIN);
        }

        if (curr->right)
        {
            q.push(curr->right);
        }
        else
        {
            result.push_back(INT_MIN);
        }
    }

    // Remove trailing NULL markers.
    while (!result.empty() && result.back() == INT_MIN)
        result.pop_back();

    return result;
}

void printTree(vector<int> arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == INT_MIN)
            cout << "null";
        else
            cout << arr[i];

        if (i < arr.size() - 1)
            cout << ", ";
    }
    cout << "]";
}

void runTest(vector<int> arr, vector<int> expected)
{
    TreeNode *root = buildTree(arr);

    Solution sol;
    TreeNode *result = sol.invertTree(root);

    vector<int> output = getLevelOrder(result);

    cout << "Input:    ";
    printTree(arr);

    cout << "\nOutput:   ";
    printTree(output);

    cout << "\nExpected: ";
    printTree(expected);

    cout << "\n-----------------------------\n";
}

int main()
{
    // Test 1
    runTest(
        {4, 2, 7, 1, 3, 6, 9},
        {4, 7, 2, 9, 6, 3, 1});

    // Test 2
    runTest(
        {2, 1, 3},
        {2, 3, 1});

    // Test 3: Empty tree
    runTest(
        {},
        {});

    // Test 4: Single node
    runTest(
        {1},
        {1});

    // Test 5: Left-skewed tree
    runTest(
        {1, 2, INT_MIN, 3},
        {1, INT_MIN, 2, INT_MIN, 3});

    // Test 6: Right-skewed tree
    runTest(
        {1, INT_MIN, 2, INT_MIN, 3},
        {1, 2, INT_MIN, 3});

    // Test 7: Complete binary tree
    runTest(
        {1, 2, 3, 4, 5, 6, 7},
        {1, 3, 2, 7, 6, 5, 4});

    // Test 8: Unbalanced tree
    runTest(
        {1, 2, 3, 4, INT_MIN, INT_MIN, 5},
        {1, 3, 2, 5, INT_MIN, INT_MIN, 4});

    // Test 9: Negative values
    runTest(
        {-1, -2, -3, -4, INT_MIN, INT_MIN, -5},
        {-1, -3, -2, -5, INT_MIN, INT_MIN, -4});

    // Test 10: Mixed structure
    runTest(
        {10, 5, 15, INT_MIN, 7, 12, 20},
        {10, 15, 5, 20, 12, 7});

    return 0;
}