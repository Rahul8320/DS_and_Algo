#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

node* head = NULL;
node* Top = NULL;

void Push(int item)
{
    node* n = new node(item);
    n->next = Top;
    Top=n;
    head=Top;
}

void Pop()
{
    if(Top==NULL)
    {
        cout<<"Stack is empty.\n";
    }
    else{
        node* ptr;
        ptr = Top;
        Top=Top->next;
        head=Top;
        delete(ptr);
    }
}

void Status()
{
    if(Top==NULL)
    {
        cout<<"Stack is Empty.\n";
    }
    else{
        node* ptr=Top;
        cout<<"TOP";
        while(ptr!=NULL)
        {
            cout<<"<--"<<ptr->data;
            ptr=ptr->next;
        }
        cout<<endl;
    }
}

int main()
{
    Push(5);
    Push(10);
    Push(15);
    Status();
    Pop();
    Status();
    Push(20);
    Push(25);
    Status();
    Pop();
    Pop();
    Status();
    return 0;
}
