// ''' Implementation of queue using one stack.'''

#include <bits/stdc++.h>
using namespace std;

class Queue{
    stack<int> st1;
    public:
    void push(int x){
        st1.push(x);
    }

    int pop(){
        if(st1.empty()){
            cout << "No element in Queue"<<endl;
            return -1;
        }
        int x = st1.top();
        st1.pop();
        if(st1.empty()){
            return x;
        }
        int item = pop();
        st1.push(x);
        return item;
    }

    bool empty(){
        if(st1.empty()){
            return true;
        }
        return false;
    }
};

int main(){
    cout <<"Implementation of Queue using 1 Stack." << endl;
    Queue q;
    q.push(5);
    q.push(10);
    q.push(12);
    cout <<q.pop()<< endl;
    cout <<q.pop()<< endl;
    cout << q.empty()<< endl;
    q.push(15);
    q.push(20);
    cout <<q.pop()<< endl;
    cout <<q.pop()<< endl;
    cout << q.pop()<< endl;
    cout << q.empty()<< endl;

    return 0;
}