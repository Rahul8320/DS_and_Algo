// Flat a binary tree to a linked list and print inorder of this flat binary tree

#include <iostream>
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

void flatBinaryTree(Node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    if(root->left != NULL){
        flatBinaryTree(root->left);

        Node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node *t = root->right;
        while(t->right != NULL){
            t = t->right;
        }

        t->right = temp;
    }
    flatBinaryTree(root->right);
}

void printInorderTree(Node *root){
    if(root==NULL)  return;

    printInorderTree(root->left);
    cout<<root->data<<" ";
    printInorderTree(root->right);
}

int main()
{
    // create binary tree
    /*          1
            2       3  
          4  5    6   7
    */
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // flat the binary tree.
    flatBinaryTree(root);
    // print inorder 
    printInorderTree(root);
    cout << endl;

    // create a binary tree
    /*   4
        / \
       9   5
      / \   \
     1   3   6
    */

    struct Node *root1 = new Node(4);
    root1->left = new Node(9);
    root1->right = new Node(5);
    root1->left->left = new Node(1);
    root1->left->right = new Node(3);
    root1->right->right = new Node(6);

    // flat the binary tree.
    flatBinaryTree(root1);
    // print inorder
    printInorderTree(root1);
    cout << endl;

    return 0;
}