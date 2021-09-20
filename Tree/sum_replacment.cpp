// replace all node with their child node + root node sum
#include<iostream>

using namespace std;

struct Node 
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Time complexity :- O(N)
void sumReplacment(Node *root)
{
    if (root == NULL) return;
    sumReplacment(root->left);
    sumReplacment(root->right);
    if(root->left != NULL)
        root->data += root->left->data;
    if(root->right != NULL)
        root->data += root->right->data;
}

void preorder(Node *root)
{
    if(root == NULL) return;
    cout <<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    //sum replacement 
    sumReplacment(root);
    preorder(root);
    cout<<endl;
    return 0;
}