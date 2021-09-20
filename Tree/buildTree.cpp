// Build Tree from inorder and preorder traversal of the tree.

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

int search(int inorder[], int start, int end, int key)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == key)
        {
            return i;
        }
    }
    return -1;
}

Node *BuildTree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if (start > end)
    {
        return NULL;
    }

    int curr = preorder[idx];
    idx++;
    Node *node = new Node(curr);
    if (start == end)
    {
        return node;
    }

    int pos = search(inorder, start, end, curr);
    node->left = BuildTree(preorder, inorder, start, pos - 1);
    node->right = BuildTree(preorder, inorder, pos + 1, end);

    return node;
}

void inorderPrint(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderPrint(root->left);
    cout << root->data << "  ";
    inorderPrint(root->right);
}

int main()
{
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};

    Node *root = BuildTree(preorder, inorder, 0, 6);
    cout << "Inorder : " << endl;
    inorderPrint(root);
    cout << endl;

    return 0;
}