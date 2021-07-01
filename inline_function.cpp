#include <iostream>
using namespace std;

inline int sum(int a=0,int b=0,int c=0)
{
    return (a+b+c);
}

int main()
{
    cout<< "Hello programmer!"<<endl;
    cout<<sum(4,5)<<endl;
    cout<<"Sum is : " <<sum(3,4,5)<<endl;
    cout<<sum(2,9)<<endl;
    return 0;
}