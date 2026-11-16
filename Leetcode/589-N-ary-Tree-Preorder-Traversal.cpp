#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <climits>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}
    Node(int _val)
    {
        val = _val;
    }
    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> ans;

        if (root == NULL)
            return ans;

        stack<Node *> st;

        st.push(root);

        while (!st.empty())
        {
            Node *curr = st.top();
            st.pop();

            ans.push_back(curr->val);

            for (int i = curr->children.size() - 1; i >= 0; i--)
            {
                st.push(curr->children[i]);
            }
        }

        return ans;
    }
};

// Build N-ary tree from level-order serialization.
// INT_MIN represents NULL (end of a parent's children group).
Node *buildTree(vector<int> arr)
{
    if (arr.empty() || arr[0] == INT_MIN)
        return NULL;

    Node *root = new Node(arr[0]);
    queue<Node *> q;
    q.push(root);

    int i = 2; // arr[1] is the separator after the root.

    while (!q.empty() && i < arr.size())
    {
        Node *curr = q.front();
        q.pop();

        while (i < arr.size() && arr[i] != INT_MIN)
        {
            Node *child = new Node(arr[i]);
            curr->children.push_back(child);
            q.push(child);
            i++;
        }

        i++; // Skip the separator.
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
    Node *root = buildTree(arr);

    Solution sol;
    vector<int> result = sol.preorder(root);

    cout << "Output:   ";
    printVector(result);

    cout << "\nExpected: ";
    printVector(expected);

    cout << "\n--------------------------\n";
}

int main()
{
    // Test 1: LeetCode example 1
    runTest(
        {1, INT_MIN, 3, 2, 4, INT_MIN, 5, 6},
        {1, 3, 5, 6, 2, 4});

    // Test 2: LeetCode example 2
    runTest(
        {1, INT_MIN, 2, 3, 4, 5, INT_MIN, INT_MIN, 6, 7, INT_MIN, 8, INT_MIN, 9, 10, INT_MIN, INT_MIN, 11, INT_MIN, 12, INT_MIN, 13, INT_MIN, INT_MIN, 14},
        {1, 2, 3, 6, 7, 11, 14, 4, 8, 12, 5, 9, 13, 10});

    // Test 3: Empty tree
    runTest({}, {});

    // Test 4: Single node
    runTest({1}, {1});

    // Test 5: Root with three children
    runTest({1, INT_MIN, 2, 3, 4}, {1, 2, 3, 4});

    // Test 6: Root with one child
    runTest({1, INT_MIN, 2}, {1, 2});

    // Test 7: Chain-like tree
    runTest(
        {1, INT_MIN, 2, INT_MIN, 3, INT_MIN, 4},
        {1, 2, 3, 4});

    // Test 8: Multiple levels
    runTest(
        {1, INT_MIN, 2, 3, INT_MIN, 4, 5, 6},
        {1, 2, 4, 5, 6, 3});

    // Test 9: Negative node values
    runTest(
        {-1, INT_MIN, -2, -3, INT_MIN, -4, -5},
        {-1, -2, -4, -5, -3});

    // Test 10: Root with no children
    runTest({10}, {10});

    return 0;
}