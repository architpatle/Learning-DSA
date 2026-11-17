#include <iostream>
#include <vector>
#include <queue>
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
    int search(vector<int> &inorder, int left, int right, int val)
    {
        for (int i = left; i <= right; i++)
        {
            if (inorder[i] == val)
            {
                return i;
            }
        }
        return -1;
    }

    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int &preIdx, int left, int right)
    {
        if (left > right)
            return NULL;

        TreeNode *root = new TreeNode(preorder[preIdx]);

        int inIdx = search(inorder, left, right, preorder[preIdx]);

        preIdx++;

        root->left = helper(preorder, inorder, preIdx, left, inIdx - 1);
        root->right = helper(preorder, inorder, preIdx, inIdx + 1, right);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int preIdx = 0;

        return helper(preorder, inorder, preIdx, 0, inorder.size() - 1);
    }
};

void printInorder(TreeNode *root)
{
    if (root == NULL)
        return;

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

void printPreorder(TreeNode *root)
{
    if (root == NULL)
        return;

    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void runTest(vector<int> preorder, vector<int> inorder,
             vector<int> expectedPreorder, vector<int> expectedInorder)
{

    Solution sol;
    TreeNode *root = sol.buildTree(preorder, inorder);

    cout << "Constructed Preorder: ";
    printPreorder(root);

    cout << "\nExpected Preorder:    ";
    for (int val : expectedPreorder)
        cout << val << " ";

    cout << "\nConstructed Inorder:  ";
    printInorder(root);

    cout << "\nExpected Inorder:     ";
    for (int val : expectedInorder)
        cout << val << " ";

    cout << "\n--------------------------\n";
}

int main()
{
    // Test 1
    runTest(
        {3, 9, 20, 15, 7},
        {9, 3, 15, 20, 7},
        {3, 9, 20, 15, 7},
        {9, 3, 15, 20, 7});

    // Test 2
    runTest(
        {-1},
        {-1},
        {-1},
        {-1});

    // Test 3: Empty tree
    runTest(
        {},
        {},
        {},
        {});

    // Test 4: Left-skewed tree
    runTest(
        {1, 2, 3, 4},
        {4, 3, 2, 1},
        {1, 2, 3, 4},
        {4, 3, 2, 1});

    // Test 5: Right-skewed tree
    runTest(
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4});

    // Test 6: Balanced tree
    runTest(
        {1, 2, 4, 5, 3, 6, 7},
        {4, 2, 5, 1, 6, 3, 7},
        {1, 2, 4, 5, 3, 6, 7},
        {4, 2, 5, 1, 6, 3, 7});

    // Test 7: Root with only left subtree
    runTest(
        {10, 5, 2, 7},
        {2, 5, 7, 10},
        {10, 5, 2, 7},
        {2, 5, 7, 10});

    // Test 8: Root with only right subtree
    runTest(
        {10, 15, 20, 25},
        {10, 15, 20, 25},
        {10, 15, 20, 25},
        {10, 15, 20, 25});

    // Test 9: Negative and positive values
    runTest(
        {0, -3, -5, 2, 4},
        {-5, -3, 0, 2, 4},
        {0, -3, -5, 2, 4},
        {-5, -3, 0, 2, 4});

    // Test 10: Larger tree
    runTest(
        {8, 4, 2, 6, 12, 10, 14},
        {2, 4, 6, 8, 10, 12, 14},
        {8, 4, 2, 6, 12, 10, 14},
        {2, 4, 6, 8, 10, 12, 14});

    return 0;
}