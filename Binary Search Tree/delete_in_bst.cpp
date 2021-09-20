// delete a node from binary search tree.

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

Node *inorderSuccessor(Node *root)
{
    Node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node *deleteInBst(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->data > key)
    {
        root->left = deleteInBst(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = deleteInBst(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = inorderSuccessor(root->right);
        root->data = temp->data;
        root->right = deleteInBst(root->right, temp->data);
    }
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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

    // inorder tree node
    inorder(root);
    cout<<endl;
    // delete nodes
    root = deleteInBst(root,3);
    inorder(root);
    cout<<endl;
    
    return 0;
}