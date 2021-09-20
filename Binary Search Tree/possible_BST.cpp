// find possible BST from number of nodes.

#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int data;
    struct node *left, *right;

    node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

vector<node *> buildTree(int start, int end)
{
    vector<node *> trees;
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }
    for (int i = start; i <= end; i++)
    {
        vector<node *> leftTree = buildTree(start, i - 1);
        vector<node *> rightTree = buildTree(i + 1, end);

        for (int j = 0; j < leftTree.size(); j++)
        {
            node *leftNode = leftTree[j];
            for (int k = 0; k < rightTree.size(); k++)
            {
                node *rightNode = rightTree[k];
                node *Node = new node(i);
                Node->left = leftNode;
                Node->right = rightNode;
                trees.push_back(Node);
            }
        }
    }
    return trees;
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    vector<node *> totalTrees = buildTree(1, 3);
    for (int i = 0; i < totalTrees.size(); i++)
    {
        cout << i + 1 << " : ";
        preorder(totalTrees[i]);
        cout << endl;
    }
    return 0;
}