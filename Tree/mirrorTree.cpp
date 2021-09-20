// mirror the tree and give inorder traversal of binary tree 

#include <iostream>
#include <stack>

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

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void mirror(Node *root)
{
    // code here
    if (root == NULL)
        return;

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Previous Inorder : ";
    inorder(root);
    cout << endl;
    // mirror the tree.
    mirror(root);
    cout<<"Current Inorder after mirror : ";
    inorder(root);
    cout<< endl;
    return 0;
}
