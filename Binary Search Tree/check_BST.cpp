// Check a given binary tree is a BST or Not ?
#include <iostream>
#include <vector>
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

bool isBST(Node *root, Node *min=NULL, Node *max=NULL)
{
    if (root == NULL)
        return true;

    if (min != NULL && root->data <= min->data)
        return false;
    if (max != NULL && root->data >= max->data)
        return false;

    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right, root, max);

    return leftValid && rightValid;
}

void inorder(Node *root, vector<int> &vc)
{
    if (root == NULL)
        return;
    inorder(root->left, vc);
    vc.push_back(root->data);
    inorder(root->right, vc);
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(7);
    root->left->right = new Node(3);
    root->left->right->right = new Node(4);
    root->left->right->left = new Node(2);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    vector<int> v;
    inorder(root, v);
    bool flag = true;
    for (auto i = 1; i < v.size(); i++)
    {
        if (v[i] < v[i - 1])
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "Tree is a BST!" << endl;
    else
        cout << "NOT a BST!" << endl;

    if (isBST(root))
        cout << "Valid BST." << endl;
    else
        cout << "invalid BST!!" << endl;
    return 0;
}