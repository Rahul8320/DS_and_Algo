// count height of the binary tree
#include <iostream>

using namespace std;

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

// time complexity : O(n) --> n = total nodes in binary tree
int hightOfBinaryTree(Node* root)
{
    if(root == NULL) return 0;
    int lHeight = hightOfBinaryTree(root->left);
    int rHeight = hightOfBinaryTree(root->right);
    return max(lHeight, rHeight)+1;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // count height of this binary tree
    cout << hightOfBinaryTree(root) << endl;
    return 0;
}