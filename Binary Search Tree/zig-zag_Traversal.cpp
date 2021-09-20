// print zig zag traversal of a binary tree.
#include <iostream>
#include <stack>
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

void zigZagTraversal(node *root, vector<int> &vc)
{
    vector<int> result;
    if (root == NULL)
    {
        return;
    }
    stack<node *> currentLevel;
    stack<node *> nextLevel;
    currentLevel.push(root);
    bool leftToRight = true;
    while (!currentLevel.empty())
    {
        node *current = currentLevel.top();
        currentLevel.pop();
        vc.push_back(current->data);
        if (leftToRight)
        {
            if (current->left)
                nextLevel.push(current->left);
            if (current->right)
                nextLevel.push(current->right);
        }
        else
        {
            if (current->right)
                nextLevel.push(current->right);
            if (current->left)
                nextLevel.push(current->left);
        }
        if (currentLevel.empty() && !nextLevel.empty())
        {
            stack<node *> temp = currentLevel;
            currentLevel = nextLevel;
            nextLevel = temp;
            leftToRight = !leftToRight;
        }
    }
}

int main()
{
    /*          
           10
        4       13
     2    8       20 
         5  9   17
    */
    node *root = new node(10);
    root->left = new node(4);
    root->right = new node(13);
    root->left->left = new node(2);
    root->left->right = new node(8);
    root->left->right->left = new node(5);
    root->left->right->right = new node(9);
    root->right->right = new node(20);
    root->right->right->left = new node(17);

    // zigZagTraversal
    vector<int> v;
    zigZagTraversal(root, v);
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}