// Build a Binary search tree from preorder.

#include <iostream>
#include <climits>
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

// Time Complexity : O(N)
Node *buildBst(int preorder[], int *preIdx, int key, int min, int max, int n)
{
    if (*preIdx >= n)
    {
        return NULL;
    }
    Node *root = NULL;
    if (key > min && key < max)
    {
        root = new Node(key);
        *preIdx = *preIdx + 1;

        if (*preIdx < n)
        {
            root->left = buildBst(preorder, preIdx, preorder[*preIdx], min, key, n);
        }
        if (*preIdx < n)
        {
            root->right = buildBst(preorder, preIdx, preorder[*preIdx], key, max, n);
        }
    }

    return root;
}

void printPreorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main()
{
    int preorder[] = {10, 2, 1, 13, 11};
    int n = 5;
    int preIdx = 0;
    Node *root = buildBst(preorder, &preIdx, preorder[0], INT_MIN, INT_MAX, n);
    printPreorder(root);
    cout << endl;

    return 0;
}