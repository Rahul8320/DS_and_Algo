// find the largest BST from a binary tree.

#include <iostream>
#include <vector>

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

void inorder(node *root, vector<int> &vc)
{
    if (root == NULL)
        return;
    inorder(root->left, vc);
    vc.push_back(root->data);
    inorder(root->right, vc);
}

int main()
{
    vector<int> vc;
    node *root = new node(15);
    root->left = new node(20);
    root->right = new node(30);
    // root->left->right = new node(4);
    root->left->left = new node(5);

    inorder(root, vc);
    for(auto it:vc){
        cout << it<<" ";
    }
    cout<<endl;
    int maxLength = 0;
    int temp = 1;
    for (int i = 1; i < vc.size(); i++)
    {
        if (vc[i] > vc[i - 1])
        {
            temp++;
        }
        else
        {
            maxLength = max(maxLength, temp);
            temp = 1;
        }
    }
    maxLength = max(maxLength, temp);
    cout << maxLength << endl;
    return 0;
}