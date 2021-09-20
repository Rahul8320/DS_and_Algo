// find the maximum sum path from a binary tree.

#include <iostream>
#include <climits>
using namespace std;

// constructing binary tree node.
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int maxSumPath(Node *root, int &maxSum)
{
    if (root == NULL)
        return 0;

    int lSum = maxSumPath(root->left, maxSum);
    int rSum = maxSumPath(root->right, maxSum);

    int nodemax = max(max(root->data, root->data + lSum + rSum), max(root->data + lSum, root->data + rSum));
    maxSum = max(maxSum, nodemax);
    int singlePath = max(root->data, max(root->data + lSum, root->data + rSum));

    return singlePath;
}

int main()
{
    // create binary tree
    /*          1
            -12      3  
          4   5       -7
        -6       8  
    */
    struct Node *root = new Node(1);
    root->left = new Node(-12);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(-7);
    root->left->left->left = new Node(-6);
    root->left->right->right = new Node(8);

    // find maxSum Path from binary tree.
    int maxSum = INT_MIN;
    int temp = maxSumPath(root, maxSum);
    cout << "maxSum : " << maxSum << endl;
    cout << temp << endl;

    return 0;
}