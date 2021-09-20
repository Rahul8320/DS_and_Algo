// Build Tree from postorder and inorder traversal of binary tree.

#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left= NULL;
        right= NULL;
    }
};

int search(int inorder[],int start, int end,int key)
{
    for(int i=start; i<=end; i++){
        if(inorder[i] == key){
            return i;
        }
    }
    return -1;
}

Node* buildTree(int postorder[],int inorder[],int start,int end)
{
    static int idx = 4;
    if(start>end){
        return NULL;
    }

    int curr = inorder[idx];
    Node* node = new Node(curr);
    idx--;

    if(start==end) {
        return node;
    }
    int pos = search(inorder,start,end,curr);
    node->right = buildTree(postorder,inorder,pos+1,end);
    node->left = buildTree(postorder,inorder,start,pos-1);

    return node;
}

void printTree(Node* root)
{
    if(root==NULL) return;

    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

int main()
{
    int postorder[]={4,2,5,3,1};
    int inorder[]={4,2,1,5,3};

    // build Tree 
    Node* root = buildTree(postorder,inorder,0,4);
    printTree(root);
    cout<<"\n";
    return 0;
}