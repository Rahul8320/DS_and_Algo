// sort a stack using recurssion.

#include <iostream>
#include <stack>
using namespace std;

void insert(stack<int> &s, int key)
{
    if (s.empty() || key > s.top())
    {
        s.push(key);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s, key);

    s.push(val);
    return;
}

void sortStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int temp = st.top();
    st.pop();
    sortStack(st);

    insert(st, temp);
    return;
}

int main()
{
    int n;
    cin >> n;
    stack<int> ST;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        ST.push(k);
    }
    stack<int> ST2 = ST;
    while (!ST2.empty())
    {
        cout << ST2.top() << " ";
        ST2.pop();
    }
    cout << endl;

    sortStack(ST);
    while (!ST.empty())
    {
        cout << ST.top() << " ";
        ST.pop();
    }
    cout << endl;
    return 0;
}