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

int heightOfTree(Node *root)
{
    if (root == NULL)
        return 0;

    int leftH = heightOfTree(root->left);
    int rightH = heightOfTree(root->right);

    return max(leftH, rightH) + 1;
}

int totalNodes(Node *root)
{
    if (root == NULL)
        return 0;

    int leftNodes = totalNodes(root->left);
    int rightNodes = totalNodes(root->right);

    return leftNodes + rightNodes + 1;
}

int sumOfNodes(Node *root){
    if(root == NULL)
        return 0;

    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);

    return leftSum + rightSum + root->data;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(preorder);

    cout << "Height: " << heightOfTree(root) << endl;
    cout << "Total Nodes: " << totalNodes(root) << endl;
    cout << "Sum of Nodes: " << sumOfNodes(root) << endl;

    return 0;
}