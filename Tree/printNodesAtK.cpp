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

// case 1 for subtree.
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

// case 2 for ansisters
int printNodesAtK(Node *root, Node *target, int k)
{
    if (root == NULL)
        return -1;

    if (root == target)
    {
        printSubtreeNodesAtK(root, k);
        return 0;
    }
    int ld = printNodesAtK(root->left, target, k);
    if (ld != -1)
    {
        if (ld + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printSubtreeNodesAtK(root->right, k - ld - 2);
        }
        return 1 + ld;
    }

    int rd = printNodesAtK(root->right, target, k);
    if (rd != -1)
    {
        if (rd + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printSubtreeNodesAtK(root->left, k - rd - 2);
        }
        return 1 + rd;
    }

    return -1; 
}

int main()
{
    // create binary tree
    /*          1
            2       3  
          4   5       7
        6       8  
    */
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    root->left->left->left = new Node(6);
    root->left->right->right = new Node(8);

    // print nodes at distance 2 from root->left
    int ans = printNodesAtK(root,root->left,1);
    cout << endl;
    cout<<ans<<endl;
    
    return 0;
}