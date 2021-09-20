// inorder preorder postorder traversal of Binary tree.

#include <iostream>
using namespace std;

// constructing binary tree node.
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// preorder traversal of Binary tree.
void preorder(struct Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data <<" ";
    preorder(root->left);
    preorder(root->right);
}

// inorder traversal of Binary tree.
void inorder(struct Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// postorder traversal of Binary tree.
void postorder(struct Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    // create binary tree
    /*          1
            2       3  
          4  5    6   7
    */
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // print preorder of given binary tree
    cout << "\n Preorder : "<< endl;
    preorder(root);
    cout<<endl;

    // print inorder of given binary tree
    cout << "\n Inorder : "<< endl;
    inorder(root);
    cout<<endl;

    // print postorder of given binary tree
    cout << "\n Postorder : "<< endl;
    postorder(root);
    cout<<endl;

    return 0;
}