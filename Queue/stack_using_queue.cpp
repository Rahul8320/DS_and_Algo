// ''' Implementation of stack using queue where push operation is costly.'''

#include<bits/stdc++.h>
using namespace std;

class Stack{
    int N;
    queue<int> q1;
    queue<int> q2;

    public:
    Stack(){
        N=0;
    }

    void push(int x){
        q2.push(x);
        N++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp=q1;
        q1 = q2;
        q2 = temp;
    }

    void pop() {
        if(N <= 0){
            cout << "No elements in Stack."<<endl;
            return;
        }
        q1.pop();
        N--;
    }

    int top() {
        return q1.front();
    }

    int size() {
        return N;
    }

    bool empty() {
        if(N <= 0){
            cout<<"Stack is empty."<<endl;
            return true;
        }
        return false;
    }
};

int main(){
    Stack st;
    st.push(5);
    st.push(7);
    st.push(9);
    cout << st.top() << endl;
    st.pop();
    cout << st.empty()<< endl;
    cout << st.top() << endl;
    cout << st.size()<< endl;
    st.pop();
    st.push(11);
    st.push(15);
    cout << st.top() << endl;
    st.pop();
    cout << st.top()<< endl;
    cout << st.size()<< endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.size()<< endl;
    st.pop();
    cout << st.empty()<< endl;
    return 0;
}