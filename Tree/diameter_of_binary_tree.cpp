// count diameter of the binary tree
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

// time complexity : O(N) --> N = total nodes in binary tree
int calculateHight(Node *root)
{
    if (root == NULL)
        return 0;

    return max(calculateHight(root->left), calculateHight(root->right)) + 1;
}

// Time complexity : O(N^2) --> N = total nodes in binary tree
int calculateDiameter(Node *root)
{
    if (root == NULL)
        return 0;
    int lHeight = calculateHight(root->left);
    int rHeight = calculateHight(root->right);
    int currDiameter = lHeight + rHeight + 1;

    int lDiameter = calculateDiameter(root->left);
    int rDiameter = calculateDiameter(root->right);
    return max(currDiameter, max(lDiameter, rDiameter));
}

int calDiameter(Node *root, int *height)
{
    if (root == NULL){
        *height = 0;
        return 0;
    }
    int lh=0,rh=0;
    int lDiameter = calDiameter(root->left, &lh);
    int rDiameter = calDiameter(root->right, &rh);

    int currDiameter = lh + rh + 1;
    *height = max(lh,rh)+1;

    return max(currDiameter,max(lDiameter,rDiameter));
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // count height of this binary tree
    cout << calculateDiameter(root) << endl;
    int height = 0;
    cout<<calDiameter(root,&height) << endl;
    return 0;
}