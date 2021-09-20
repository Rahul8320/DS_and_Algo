// print all nodes at distace k from the subtree of given node.

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

void printSubtreeNodesAtK(Node *root, int k)
{
    if (root == NULL || k < 0)
        return;

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    printSubtreeNodesAtK(root->left, k - 1);
    printSubtreeNodesAtK(root->right, k - 1);
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

    // print nodes at distance 1 from root->left subtree.
    printSubtreeNodesAtK(root->left, 1);
    cout << endl;

    return 0;
}