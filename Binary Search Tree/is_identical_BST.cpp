// check two BST for identical or not.
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool isIdenticalBst(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 != NULL && root2 != NULL)
    {
        if (root1->data != root2->data)
        {
            return false;
        }
        if (isIdenticalBst(root1->left, root2->left) == false)
        {
            return false;
        }
        if (isIdenticalBst(root1->right, root2->right) == false)
        {
            return false;
        }
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    node *root1 = new node(1);
    root1->right = new node(3);
    root1->right->left = new node(2);
    root1->right->right = new node(5);

    node *root2 = new node(1);
    root1->left = new node(3);
    root1->left->left = new node(2);
    root1->left->right = new node(5);

    // check for identical BST.
    if (isIdenticalBst(root1, root2))
    {
        cout << "Identical BST." << endl;
    }
    else
    {
        cout << "Not identical BST." << endl;
    }

    return 0;
}