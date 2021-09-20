// preorder traversal of binary tree iterative approach

#include<iostream>
#include<stack>

using namespace std;

struct Node 
{
    int data;
    struct Node *left,*right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node *root)
{
    if(root == NULL)
        return;
    stack<Node *> q;
    q.push(root);
    while (!q.empty()){
        Node *node = q.top();
        q.pop();

        cout << node->data<<" ";
        if(node->right)
            q.push(node->right);
        if(node->left)
            q.push(node->left);
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

    cout<<"Preorder : ";
    preorder(root);
    cout<<endl;
    return 0;
}