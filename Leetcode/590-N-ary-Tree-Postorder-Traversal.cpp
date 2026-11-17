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
    vector<int> postorder(Node *root)
    {
        vector<int> ans;

        if (root == NULL)
            return ans;

        stack<Node *> st1;
        stack<Node *> st2;

        st1.push(root);

        while (!st1.empty())
        {
            Node *curr = st1.top();

            st1.pop();
            st2.push(curr);

            for (int i = 0; i < curr->children.size(); i++)
            {
                st1.push(curr->children[i]);
            }
        }

        while (!st2.empty())
        {
            ans.push_back(st2.top()->val);
            st2.pop();
        }

        return ans;
    }
};

// Build N-ary tree from level-order serialization.
// INT_MIN represents NULL (end of a parent's children group).
Node *buildTree(vector<int> arr)
{
    if (arr.empty())
        return NULL;

    Node *root = new Node(arr[0]);
    queue<Node *> q;
    q.push(root);

    int i = 2; // Skip the separator after root.

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
    vector<int> result = sol.postorder(root);

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
        {5, 6, 3, 2, 4, 1});

    // Test 2: LeetCode example 2
    runTest(
        {1, INT_MIN, 2, 3, 4, 5, INT_MIN, INT_MIN, 6, 7, INT_MIN, 8, INT_MIN, 9, 10, INT_MIN, INT_MIN, 11, INT_MIN, 12, INT_MIN, 13, INT_MIN, INT_MIN, 14},
        {2, 6, 14, 7, 11, 3, 12, 8, 4, 13, 9, 10, 5, 1});

    // Test 3: Empty tree
    runTest({}, {});

    // Test 4: Single node
    runTest({1}, {1});

    // Test 5: Root with three children
    runTest(
        {1, INT_MIN, 2, 3, 4},
        {2, 3, 4, 1});

    // Test 6: Root with one child
    runTest(
        {1, INT_MIN, 2},
        {2, 1});

    // Test 7: Chain-like tree
    runTest(
        {1, INT_MIN, 2, INT_MIN, 3, INT_MIN, 4},
        {4, 3, 2, 1});

    // Test 8: Multiple levels
    runTest(
        {1, INT_MIN, 2, 3, INT_MIN, 4, 5, 6},
        {4, 5, 6, 2, 3, 1});

    // Test 9: Root with multiple child subtrees
    runTest(
        {1, INT_MIN, 2, 3, 4, INT_MIN, 5, 6, INT_MIN, 7},
        {5, 6, 2, 7, 3, 4, 1});

    // Test 10: Larger tree
    runTest(
        {10, INT_MIN, 20, 30, 40, INT_MIN, 50, 60, INT_MIN, 70, 80},
        {50, 60, 20, 70, 80, 30, 40, 10});

    return 0;
}