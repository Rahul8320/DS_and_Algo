// preorder traversal of binary tree iterative approach

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
        return;
    stack<Node *> q;
    Node *curr = root; 
    while(curr != NULL || q.empty() == false) {
        while(curr != NULL) {
            q.push(curr);
            curr = curr->left;
        }
        curr = q.top();
        q.pop();
        cout<< curr->data << " ";
        curr= curr->right;
    }
    return;
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

    cout << "Inorder : ";
    inorder(root);
    cout << endl;
    return 0;
}