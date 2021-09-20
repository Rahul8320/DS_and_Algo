// search an element in the BST.
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool searchBST(Node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    if (key < root->data)
    {
        return searchBST(root->left, key);
    }
    return searchBST(root->right, key);
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

    // search nodes
    if (searchBST(root, 5))
    {
        cout << "Node is present in the tree." << endl;
    }
    else
    {
        cout << "Node is NOT present in the tree." << endl;
    }
    return 0;
}