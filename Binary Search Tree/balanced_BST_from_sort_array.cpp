// make a Hight Balanced Binary Search Tree from a sorted array.

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

node *buildBst(int sortedArray[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    node *root = new node(sortedArray[mid]);
    root->left = buildBst(sortedArray, start, mid - 1);
    root->right = buildBst(sortedArray, mid + 1, end);

    return root;
}

void printPreorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(node *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    int sortedArray[] = {10,20,30,40,50};
    node *root = buildBst(sortedArray, 0, 4);
    printPreorder(root);
    cout << endl;
    printInorder(root);
    cout<<endl;

    return 0;
}