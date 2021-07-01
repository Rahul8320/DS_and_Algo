#include<bits/stdc++.h>
using namespace std;
#define SIZE 100

int st[SIZE];
int TOP = -1;

void Push(int Item)
{
    if(TOP >= SIZE)
    {
        cout<<"Stack is full."<<endl;
    }
    else
    {
        TOP++;
        st[TOP] = Item;
    }
}

int Pop()
{
    if(TOP==-1)
    {
        cout<<"Stack is empty."<<endl;
        return -1;
    }
    else{
        int Item = st[TOP];
        TOP--;
        return Item;
    }
}

void Status()
{
    if(TOP==-1)
    {
        cout<<"Stack is empty."<<endl;
    }
    else{
        if(TOP >= SIZE)
            cout<<"Stack is full."<<endl;
        else{
            cout<<"The Top element is : "<<st[TOP]<<endl;
            int free = (SIZE - TOP-1);
            cout<<"Stack is Free : "<<free<<" % \n";
        }
    }
}

void Display()
{
    int t = TOP;
    while(t != -1)
    {
        cout<<st[t]<<endl;
        t--;
    }
}

int main()
{
    Push(5);
    Push(10);
    Display();
    Status();
    Push(15);
    Push(20);
    Display();
    Status();
    cout<<"Pop : "<<Pop()<<endl;
    cout<<"Pop : "<<Pop()<<endl;
    cout<<"Pop : "<<Pop()<<endl;
    Display();
    Status();
    return 0;
}