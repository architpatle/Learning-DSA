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

    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        TreeNode* curr = root;

        while(curr != NULL){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                // Find IP = Inorder Predecessor
                TreeNode* IP = curr->left;
                while(IP->right != NULL && IP->right != curr){
                    IP = IP->right;
                }

                if(IP->right == NULL){
                    IP->right = curr;
                    curr= curr->left;
                } else {
                    IP->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

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

void printVector(vector<int> ans)
{
    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i != ans.size() - 1)
            cout << ", ";
    }
    cout << "]";
}

void runTest(vector<int> arr, vector<int> expected)
{
    TreeNode *root = buildTree(arr);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    cout << "Output:   ";
    printVector(result);

    cout << "\nExpected: ";
    printVector(expected);

    cout << "\n--------------------------\n";
}

int main()
{
    // Test 1
    runTest({1, INT_MIN, 2, 3}, {1, 3, 2});

    // Test 2
    runTest({}, {});

    // Test 3
    runTest({1}, {1});

    // Test 4
    runTest({1, 2, 3}, {2, 1, 3});

    // Test 5
    runTest({1, 2, 3, 4, 5}, {4, 2, 5, 1, 3});

    // Test 6
    runTest({1, INT_MIN, 2, INT_MIN, 3}, {1, 2, 3});

    // Test 7
    runTest({1, 2, INT_MIN, 3, INT_MIN, 4}, {4, 3, 2, 1});

    // Test 8
    runTest({5, 3, 8, 2, 4, 7, 9}, {2, 3, 4, 5, 7, 8, 9});

    // Test 9
    runTest({10, 5, 15, INT_MIN, 7, 12, 20},
            {5, 7, 10, 12, 15, 20});

    // Test 10
    runTest({1, 2, 3, INT_MIN, 4, 5, INT_MIN},
            {2, 4, 1, 5, 3});

    // Test 11
    runTest({1, 2, 3, 4, 5, 6, 7},
            {4, 2, 5, 1, 6, 3, 7});

    // Test 12
    runTest({-10, -20, -5, -30, INT_MIN, INT_MIN, 0},
            {-30, -20, -10, -5, 0});

    return 0;
}