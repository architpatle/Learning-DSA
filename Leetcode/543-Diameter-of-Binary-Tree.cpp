#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
    int ans = 0;

    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int leftHt = height(root->left);
        int rightHt = height(root->right);

        ans = max(ans, leftHt + rightHt);

        return max(leftHt, rightHt) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        height(root);

        return ans;
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

void runTest(vector<int> values)
{
    TreeNode *root = createTree(values);

    Solution sol;
    int result = sol.diameterOfBinaryTree(root);

    cout << "Tree: [";

    for (int i = 0; i < values.size(); i++)
    {
        cout << values[i];

        if (i != values.size() - 1)
            cout << ", ";
    }

    cout << "]\nDiameter: " << result;
    cout << "\n-----------------------------\n";
}

int main()
{

    // Test 1
    runTest({1, 2, 3, 4, 5});
    // Expected: 3

    // Test 2
    runTest({1, 2});
    // Expected: 1

    // Test 3
    runTest({1});
    // Expected: 0

    // Test 4
    runTest({});
    // Expected: 0

    // Test 5
    runTest({1, 2, 3, 4, -1, -1, 5});
    // Expected: 4

    // Test 6
    runTest({1, 2, -1, 3, -1, 4});
    // Expected: 3

    // Test 7
    runTest({1, -1, 2, -1, 3, -1, 4});
    // Expected: 3

    // Test 8
    runTest({1, 2, 3, 4, 5, 6, 7});
    // Expected: 4

    // Test 9
    runTest({1, 2, 3, -1, 4, -1, -1, 5});
    // Expected: 4

    // Test 10
    runTest({10, 5, 15, 3, 7, 12, 20});
    // Expected: 4

    // Test 11
    runTest({1, 2, -1, 3, -1, 4, -1, 5});
    // Expected: 4

    // Test 12
    runTest({1, 2, 3, 4, 5, -1, -1, 6, 7});
    // Expected: 4

    return 0;
}