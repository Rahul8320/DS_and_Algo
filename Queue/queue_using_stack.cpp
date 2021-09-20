// ''' Implementation of queue using two stack.'''

#include <bits/stdc++.h>
using namespace std;

class Queue{
    stack<int> st1;
    stack<int> st2;
    public:
    void push(int x){
        st1.push(x);
    }

    int pop(){
        if(st1.empty() and st2.empty()){
            cout << "No element in Queue"<<endl;
            return -1;
        }
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int topValue = st2.top();
        st2.pop();
        return topValue;
    }

    bool empty(){
        if(st1.empty() and st2.empty()){
            return true;
        }
        return false;
    }
};

int main(){
    cout <<"Implementation of Queue using 2 Stack." << endl;
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