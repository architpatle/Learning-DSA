#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits>
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
    void allPaths(TreeNode *root, vector<string> &ans, string path)
    {
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(path);
            return;
        }

        if(root->left)
            allPaths(root->left, ans, path + "->" + to_string(root->left->val));

        if(root->right)
            allPaths(root->right, ans, path + "->" + to_string(root->right->val));
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        string path = to_string(root->val);

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

void printVector(vector<string> ans)
{
    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "\"" << ans[i] << "\"";
        if (i != ans.size() - 1)
            cout << ", ";
    }
    cout << "]";
}

void runTest(vector<int> arr, vector<string> expected)
{
    TreeNode *root = buildTree(arr);

    Solution sol;
    vector<string> result = sol.binaryTreePaths(root);

    cout << "Output:   ";
    printVector(result);

    cout << "\nExpected: ";
    printVector(expected);

    cout << "\n--------------------------\n";
}

int main()
{
    // Test 1
    runTest(
        {1, 2, 3, INT_MIN, 5},
        {"1->2->5", "1->3"});

    // Test 2: Single node
    runTest(
        {1},
        {"1"});

    // // Test 3: Empty tree
    // runTest(
    //     {},
    //     {});

    // Test 4: Left-skewed tree
    runTest(
        {1, 2, INT_MIN, 3, INT_MIN, 4},
        {"1->2->3->4"});

    // Test 5: Right-skewed tree
    runTest(
        {1, INT_MIN, 2, INT_MIN, 3, INT_MIN, 4},
        {"1->2->3->4"});

    // Test 6: Balanced tree
    runTest(
        {1, 2, 3, 4, 5, 6, 7},
        {"1->2->4", "1->2->5", "1->3->6", "1->3->7"});

    // Test 7: Negative values
    runTest(
        {-10, -5, 8, -20, INT_MIN, INT_MIN, 15},
        {"-10->-5->-20", "-10->8->15"});

    // Test 8: Root with two leaf children
    runTest(
        {5, 3, 8},
        {"5->3", "5->8"});

    // Test 9: Only left child at each level
    runTest(
        {10, 5, INT_MIN, 2},
        {"10->5->2"});

    // Test 10: Multiple paths with different depths
    runTest(
        {1, 2, 3, INT_MIN, 4, 5, INT_MIN, INT_MIN, 6},
        {"1->2->4->6", "1->3->5"});

    // Test 11: Zero and negative values
    runTest(
        {0, -1, 2, INT_MIN, INT_MIN, INT_MIN, 3},
        {"0->-1", "0->2->3"});

    // Test 12: Larger tree
    runTest(
        {1, 2, 3, 4, 5, INT_MIN, 6, 7, INT_MIN, INT_MIN, 8},
        {"1->2->4->7", "1->2->5->8", "1->3->6"});

    return 0;
}