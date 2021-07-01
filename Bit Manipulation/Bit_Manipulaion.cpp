#include<iostream>
using namespace std;

void check_OE(int num)
{
    if(num & 1)
        cout<<num<<" is Odd !!\n";
    else 
        cout<<num<<" is Even !!\n";
}

void swap_num(int a,int b)
{
    a = a^b;
    b = a^b;
    a = a^b;

    cout<<a<<"  "<<b<<endl;
}

int main()
{
    cout<<(5<<1)<<endl;  // 5*2
    cout<<(6>>1)<<endl;  // 6/2
    check_OE(4);
    check_OE(5);
    int a=5,b=7;
    cout<<a<<"  "<<b<<endl;
    swap_num(a,b);
    return 0;
}