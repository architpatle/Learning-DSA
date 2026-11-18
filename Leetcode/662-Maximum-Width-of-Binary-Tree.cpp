#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        queue<pair<TreeNode *, unsigned long long>> q;
        int maxWidth = 0;

        q.push({root, 0});

        while (!q.empty())
        {
            int currLevelSize = q.size();
            unsigned long long startIdx = q.front().second;
            unsigned long long endIdx = q.back().second;

            maxWidth = max(maxWidth, (int)(endIdx - startIdx + 1));

            for (int i = 0; i < currLevelSize; i++)
            {
                auto curr = q.front();
                q.pop();

                if (curr.first->left)
                    q.push({curr.first->left, 2 * curr.second + 1});

                if (curr.first->right)
                    q.push({curr.first->right, 2 * curr.second + 2});
            }
        }

        return maxWidth;
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
    int result = sol.widthOfBinaryTree(root);

    cout << "Output:   " << result;
    cout << "\nExpected: " << expected;
    cout << "\n--------------------------\n";
}

int main()
{
    // Test 1: LeetCode Example 1
    runTest({1, 3, 2, 5, 3, INT_MIN, 9}, 4);

    // Test 2: LeetCode Example 2
    runTest({1, 3, 2, 5, INT_MIN, INT_MIN, 9, 6, INT_MIN, 7}, 7);

    // Test 3: LeetCode Example 3
    runTest({1, 3, 2, 5}, 2);

    // Test 4: Single node
    runTest({1}, 1);

    // Test 5: Completely left-skewed tree
    runTest({1, 2, INT_MIN, 3, INT_MIN, 4, INT_MIN, 5}, 1);

    // Test 6: Completely right-skewed tree
    runTest({1, INT_MIN, 2, INT_MIN, 3, INT_MIN, 4, INT_MIN, 5}, 1);

    // Test 7: Full binary tree
    runTest({1, 2, 3, 4, 5, 6, 7}, 4);

    // Test 8: Sparse tree with gaps
    runTest({1, 2, 3, 4, INT_MIN, INT_MIN, 7, 8, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 9}, 6);

    // Test 9: Negative node values
    runTest({-1, -2, -3, -4, -5, -6, -7}, 4);

    // Test 10: Wide sparse tree
    runTest({1, 2, 3, 4, INT_MIN, INT_MIN, 7, 8, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 9, 10}, 7);

    // Test 11: Width increases at deeper level
    runTest({1, 2, 3, 4, INT_MIN, INT_MIN, 7, 8, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 9, INT_MIN, 10}, 8);

    // Test 12: Root with only one child
    runTest({1, 2}, 1);

    return 0;
}