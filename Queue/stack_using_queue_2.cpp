// ''' Implementation of stack using queue where pop operation is costly.'''

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
        q1.push(x);
        N++;
    }

    void pop() {
        if(q1.empty()){
            cout << "No element in Stack."<< endl;
            return;
        }
        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        N--;
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
    }

    int top() {
        if(q1.empty()){
            cout << "No element in Stack."<< endl;
            return -1;
        }
        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q2.push(ans);
        
        queue<int> temp=q1;
        q1= q2;
        q2 = temp;
        
        return ans;
    }

    int size() {
        return N;
    }

    bool empty() {
        if(N <= 0){
            cout <<"Stack is empty."<<endl;
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