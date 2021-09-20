// reverse a stack with recurssion.

#include <iostream>
#include <stack>
using namespace std;

void insert(stack<int>& stack, int temp)
{
    if(stack.empty()){
        stack.push(temp);
        return;
    }
    int value = stack.top();
    stack.pop();
    insert(stack,temp);

    stack.push(value);
}

void reverseStack(stack<int>& st)
{
    if(st.empty())
        return;
    int temp = st.top();
    st.pop();
    reverseStack(st);

    insert(st,temp);
}

void printStack(stack<int> stack)
{
    cout<<"Current stack: ";
    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}

int main()
{
    int n=5;
    stack<int> s;
    for(int i=0; i<n; i++)
    {
        s.push(i+1);
    }
    printStack(s);
    reverseStack(s);
    printStack(s);
    return 0;
}