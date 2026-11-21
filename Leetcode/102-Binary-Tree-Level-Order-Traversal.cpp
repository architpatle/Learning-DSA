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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        vector<int> subAns;

        if (root == NULL)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr == NULL)
            {
                if (!q.empty())
                {
                    ans.push_back(subAns);
                    subAns.clear();
                    q.push(NULL);
                    continue;
                }
                else
                {
                    break;
                }
            }

            subAns.push_back(curr->val);

            if (curr->left != NULL)
                q.push(curr->left);

            if (curr->right != NULL)
                q.push(curr->right);
        }

        ans.push_back(subAns);

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

void printResult(vector<vector<int>> result)
{
    cout << "[";
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j < result[i].size() - 1)
                cout << ", ";
        }
        cout << "]";
        if (i < result.size() - 1)
            cout << ", ";
    }
    cout << "]\n";
}

void runTest(vector<int> arr, vector<vector<int>> expected)
{
    TreeNode *root = buildTree(arr);

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    cout << "Input: ";
    for (int val : arr)
    {
        if (val == INT_MIN)
            cout << "null ";
        else
            cout << val << " ";
    }

    cout << "\nOutput:   ";
    printResult(result);

    cout << "Expected: ";
    printResult(expected);

    cout << "-----------------------------\n";
}

int main()
{
    // Test 1
    runTest(
        {3, 9, 20, INT_MIN, INT_MIN, 15, 7},
        {{3}, {9, 20}, {15, 7}});

    // Test 2
    runTest(
        {1},
        {{1}});

    // Test 3
    runTest(
        {},
        {});

    // Test 4
    runTest(
        {1, 2, 3},
        {{1}, {2, 3}});

    // Test 5
    runTest(
        {1, 2, INT_MIN, 3},
        {{1}, {2}, {3}});

    // Test 6
    runTest(
        {1, INT_MIN, 2, INT_MIN, 3},
        {{1}, {2}, {3}});

    // Test 7
    runTest(
        {1, 2, 3, 4, 5, 6, 7},
        {{1}, {2, 3}, {4, 5, 6, 7}});

    // Test 8
    runTest(
        {5, 3, 8, 2, 4, 7, 9},
        {{5}, {3, 8}, {2, 4, 7, 9}});

    // Test 9
    runTest(
        {-10, -20, -5, -30, INT_MIN, INT_MIN, 0},
        {{-10}, {-20, -5}, {-30, 0}});

    // Test 10
    runTest(
        {1, 2, 3, INT_MIN, 4, 5, INT_MIN, INT_MIN, 6},
        {{1}, {2, 3}, {4, 5}, {6}});

    // Test 11
    runTest(
        {10, 5, 15, INT_MIN, 7, 12, 20},
        {{10}, {5, 15}, {7, 12, 20}});

    // Test 12
    runTest(
        {1, INT_MIN, 2, 3, INT_MIN, 4},
        {{1}, {2}, {3}, {4}});

    return 0;
}