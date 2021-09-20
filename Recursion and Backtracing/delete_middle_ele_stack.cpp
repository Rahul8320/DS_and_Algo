// delete the middle element of the stack.

#include <iostream>
#include <stack>
using namespace std;

void deleteMiddle(stack<int> &st, int key)
{
    // if (st.size() == key)
    // {
    //     st.pop();
    //     return;
    // }
    if (key == 1)
    {
        st.pop();
        return;
    }
    int temp = st.top();
    st.pop();
    deleteMiddle(st, --key);
    st.push(temp);
}

int main()
{
    stack<int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        s.push(k);
    }
    int key = n / 2 + 1;
    cout << "size : " << s.size() << endl;
    deleteMiddle(s, key);
    while (!s.empty())
    {
        cout << " " << s.top();
        s.pop();
    }
    cout << endl;
    return 0;
}