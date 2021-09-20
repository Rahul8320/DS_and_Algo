// ''' Basics of Deque ''' 

#include<iostream>
#include<deque>

using namespace std;

int main(){
    deque<int> dq;

    dq.push_back(3);
    dq.push_back(4);
    dq.push_front(2);
    dq.push_front(1);

    for(auto i : dq)
        cout << i <<" ";
    cout<<endl;

    cout << dq.size() <<endl;
    dq.pop_back();
    dq.pop_front();
    cout <<dq.size() <<endl;
    for(auto i : dq)
        cout << i <<" ";
    cout<<endl;

    return 0;
}