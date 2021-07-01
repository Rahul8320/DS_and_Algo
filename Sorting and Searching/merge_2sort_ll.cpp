#include <iostream>
using namespace std;

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

void insertAtTail(node* &head,int val)
{
    node* n = new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* ptr=head;
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=n;
}

node* merge(node* head1,node* head2)
{
    node* dummyNode = new node(-1);
    node* ptr3=dummyNode;
    node* ptr1=head1;
    node* ptr2=head2;

    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->data<ptr2->data)
        {
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }
        else
        {
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }

    while(ptr1!=NULL)
    {
        ptr3->next=ptr1;
        ptr1=ptr1->next;
        ptr3=ptr3->next;
    }

    while(ptr2!=NULL)
    {
        ptr3->next=ptr2;
        ptr2=ptr2->next;
        ptr3=ptr3->next;
    }

    return dummyNode->next;
}

node* mergeRecursive(node* &head1,node* &head2)
{
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }

    node* result;
    if(head1->data<head2->data)
    {
        result=head1;
        result->next=mergeRecursive(head1->next, head2);
    }
    else
    {
        result=head2;
        result->next=mergeRecursive(head1, head2->next);
    }

    return result;
}

void display(node* &head)
{
    node* ptr=head;
    while(ptr!=NULL)
    {
        cout << ptr->data <<"--> ";
        ptr=ptr->next;
    }
    cout << "NULL \n";
}

int main()
{
    node* head1=NULL;
    node* head2=NULL;
    int arr[]={2,4,6,8};
    for(int i=0;i<4;i++)
    {
        insertAtTail(head1, arr[i]);
    }
    int arr2[]={3,5,7};
    for(int i=0;i<3;i++)
    {
        insertAtTail(head2, arr2[i]);
    }
    display(head1);
    display(head2);
    
    node* newHead = mergeRecursive(head1, head2);
    display(newHead);
    return 0;
}