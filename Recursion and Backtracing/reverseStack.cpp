#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int> &st,int ele){

    if(st.empty()){
        st.push(ele);
        return;
    }
    int topele = st.top();
    st.pop();
    insertAtBottom(st,ele);

    st.push(topele);
}

void reverse(stack<int> &st){

    if(st.empty()){
        return;
    }

    int ele = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,ele);

}

void display(stack<int> st){

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){
    
    stack<int> st;
    int size;
    cout<<"Enter stack size : ";
    cin>>size;
    cout<<"Enter element to stack: ";
    for(int i=0;i<size;i++){
        int key;
        cin>>key;
        st.push(key);
    }
    display(st);
    reverse(st);
    display(st);

    return 0;
}