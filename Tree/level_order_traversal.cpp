// print the level order traversal of a binary tree.

#include <iostream>
#include<queue>

    using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printLevelOrderTraversal(Node* root){
    if(root==NULL){     // check root is null or not if null return from loop.
        return; 
    }
    queue<Node*>q;       // empty queue 
    q.push(root);        // insert root to queue.
    q.push(NULL);        // insert a NULL for end of level 0.
    while(!q.empty()) {
        Node *node = q.front();    // creating a node for front element of queue.
        q.pop();                    // pop front element of queue.
        if(node != NULL){           // if this node not NULL then print it and add left and right child if present.
            cout <<node->data<<" ";  // print data
            if(node->left) q.push(node->left); // check for left child and insert into queue if present.
            if(node->right) q.push(node->right); // check for right child and insert into queue if present.
        }
        else if(!q.empty()) q.push(NULL); // if the node is NULL and queue is not empty insert NULL into queue for end of Level.
    }
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);  

    // print the level order traversal of the binary tree.
    printLevelOrderTraversal(root);
    cout<<endl;
    
    return 0; 
}