// ''' Linked list implementation of Queue '''

#include<iostream>
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

class Queue{
    node* front;
    node* back;
    
    public:
    Queue(){
        front = NULL;
        back = NULL;
    }

    void push(int x){
        node* n = new node(x);
        if(front == NULL){
            back = n;
            front = n;
            return;
        }
        back ->next=n;
        back = n;
    }

    void pop(){
        if(front == NULL){
            cout <<"Queue underflow"<<endl;
            return;
        }
        node* todelete = front;
        front = front->next;
        
        delete todelete;
    }

    int peek(){
        if(front == NULL){
            cout << "No element in Queue"<<endl;
            return -1;
        }
        return front->data;
    }

    bool empty(){
        if(front ==NULL){
            return true;
        }
        return false;
    }

    void display(){
        if(front == NULL){
            cout << "No element present in Queue" <<endl;
            return;
        }
        node* ptr = front;
        while(ptr != NULL){
            cout << ptr->data << "--> ";
            ptr = ptr->next;
        }
        cout << " NULL"<<endl;
    }
};

int main(){

    Queue q;
    q.push(5);
    q.push(8);
    q.push(10);
    q.push(12);
    q.display();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    q.display();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.empty() << endl;
    q.display();
    return 0;
}