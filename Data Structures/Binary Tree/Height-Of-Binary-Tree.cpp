#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;

Node *buildTree(vector<int> &preorder)
{
    idx++;

    if (preorder[idx] == -1)
        return NULL;

    Node *root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

// height of BT
int heightOfTree(Node *root)
{
    if (root == NULL)
        return 0;

    int leftH = heightOfTree(root->left);
    int rigtH = heightOfTree(root->right);

    return max(leftH, rigtH) + 1;
}

// count Nodes of BT
int countNode(Node *root)
{
    if (root == NULL)
        return 0;

    int leftCount = countNode(root->left);
    int rightCount = countNode(root->right);

    return leftCount + rightCount + 1;
}

// Sum of all Nodes of BT
int sumOfNode(Node *root)
{
    if (root == NULL)
        return 0;

    int leftSum = sumOfNode(root->left);
    int rightSum = sumOfNode(root->right);

    return leftSum + rightSum + root->data;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(preorder);

    cout << "Height of BT: " << heightOfTree(root) << endl;
    cout << "Total Nodes: " << countNode(root) << endl;
    cout << "Sum of Nodes: " << sumOfNode(root) << endl;

    return 0;
}