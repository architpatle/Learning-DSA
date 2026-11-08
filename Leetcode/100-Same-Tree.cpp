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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL || q == NULL)
            return p == q;

        bool isLeftSame = isSameTree(p->left, q->left);
        bool isRightSame = isSameTree(p->right, q->right);

        return isLeftSame && isRightSame && p->val == q->val;

    }
};

// Build a tree from level-order input
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

void runTest(vector<int> pValues, vector<int> qValues)
{
    TreeNode *p = createTree(pValues);
    TreeNode *q = createTree(qValues);

    Solution sol;
    bool result = sol.isSameTree(p, q);

    cout << "Tree P: [";
    for (int i = 0; i < pValues.size(); i++)
    {
        cout << (pValues[i] == -1 ? -1 : pValues[i]);
        if (i != pValues.size() - 1)
            cout << ", ";
    }

    cout << "]\nTree Q: [";
    for (int i = 0; i < qValues.size(); i++)
    {
        cout << qValues[i];
        if (i != qValues.size() - 1)
            cout << ", ";
    }

    cout << "]\nOutput: " << (result ? "true" : "false");
    cout << "\n-----------------------------\n";
}

int main()
{

    // Test 1
    runTest({1, 2, 3}, {1, 2, 3});
    // Expected: true

    // Test 2
    runTest({1, 2}, {1, -1, 2});
    // Expected: false

    // Test 3
    runTest({1, 2, 1}, {1, 1, 2});
    // Expected: false

    // Test 4
    runTest({}, {});
    // Expected: true

    // Test 5
    runTest({1}, {1});
    // Expected: true

    // Test 6
    runTest({1}, {2});
    // Expected: false

    // Test 7
    runTest({1, 2, 3, 4, 5}, {1, 2, 3, 4, 5});
    // Expected: true

    // Test 8
    runTest({1, 2, 3, -1, 4}, {1, 2, 3, 4});
    // Expected: false

    // Test 9
    runTest({5, 4, -1, 3}, {5, 4, -1, 3});
    // Expected: true

    // Test 10
    runTest({1, 2, 3}, {1, 2, 4});
    // Expected: false

    return 0;
}