// Find Lowsest Common Ancestor of two nodes in a tree.

#include <iostream>
#include <vector>
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

bool getPath(Node *root, int key, vector<int> &path)
{
    if (root == NULL)
        return false;

    path.push_back(root->data);
    if (root->data == key)
        return true;

    if (getPath(root->left, key, path) || getPath(root->right, key, path))
        return true;

    path.pop_back();
    return false;
}

// time complexity : O(N)
int LCA(Node *root, int n1, int n2)
{
    vector<int> path1, path2;

    if (!getPath(root, n1, path1) || !getPath(root, n2, path2))
    {
        return -1;
    }

    int pc = 0;
    for (; pc < path1.size() && path2.size(); pc++)
    {
        if (path1[pc] != path2[pc])
        {
            break;
        }
    }

    return path1[pc - 1];
}

// time complexity is O(N)
Node *LCA2(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    Node *leftLca = LCA2(root->left, n1, n2);
    Node *rightLca = LCA2(root->right, n1, n2);

    if (leftLca && rightLca)
        return root;

    if (leftLca != NULL)
        return leftLca;

    return rightLca;
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

    // find LCA between 8,6
    int ans = LCA(root, 8, 6);
    if (ans == -1)
        cout << "LCA NOT FOUND !!" << endl;
    else
        cout << "LCA : " << ans << endl;

    // find LCA between 8,6
    Node *ans2 = LCA2(root, 8, 6);
    if (ans2 == NULL)
        cout << "LCA NOT FOUND !!" << endl;
    else
        cout << "LCA : " << ans2->data << endl;

    return 0;
}