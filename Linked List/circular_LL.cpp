#include <iostream>
using namespace std;
#define ll "  Empty Linked List "

class node 
{
    public:
    int data;
    node* next;

    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void insertAtHead(node* &head,int val)
{
    node* n = new node(val);
    if(head==NULL)
    {
        n->next=n;
        head=n;
        return;
    }
    else 
    {
       node* temp=head;
       while(temp->next!=head)
       {
           temp=temp->next;
       }
       temp->next=n;
       n->next=head;
       head=n;
       return;
    }
}

void insertAtTail(node* &head,int val)
{
    if(head==NULL)
    {
        insertAtHead(head,val);
        return;
    }
    node* n = new node(val);
    node* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    return;
}

void deleteAtHead(node* &head)
{
    if(head==NULL)
    {
        cout << ll << endl;
        return;
    }
    node* temp=head;
    if(temp->next==head)
    {
        head=NULL;
        delete(temp);
        return;
    }
    node* del=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=del->next;
    head=del->next;
    delete(del);
    return;
}

void deleteAtTail(node* &head)
{
    if(head==NULL)
    {
        cout<< ll << endl;
        return;
    }
    node* temp=head;
    if(temp->next==head)
    {
        head=NULL;
        delete(temp);
        return;
    }
    while(temp->next->next!=head)
    {
        temp=temp->next;
    }
    node* del= temp->next;
    temp->next=head;
    delete(del);
    return;
}

int searchAkey(node* &head,int key)
{
    if(head==NULL)
    {
        cout << ll << endl;
        return 0;
    }
    node* temp = head;
    do 
    {
        if(temp->data==key)
        {
            return 1;
        }
        temp=temp->next;
    }while(temp!=head);
    return 0;
}

void display(node* &head)
{
    if(head==NULL)
    {
        cout<< ll <<endl;
        return;
    }
    node* temp=head;
    do 
    {
        cout << temp->data << "--> ";
        temp=temp->next;
    }while(temp!=head);
    cout << "HEAD(" << head->data << ") \n";
    return;
}

int main ()
{
    node* head = NULL;
    for(int i=1;i<=5;i++)
    {
        insertAtTail(head, i);
    }
    display(head);
    cout << searchAkey(head, 8) <<endl;
    return 0;
}