#include<iostream>

using namespace std;

int countSetBit(int n)
{
    int count = 0;
    while(n>0)
    {
        n = (n & (n-1));
        count++;
    }
    return count;
}

int bitToChange(int a,int b)
{
    a = (a ^ b);
    return(countSetBit(a));
}

int main()
{
    int a,b;
    cout<<"Enter two number : ";
    cin>>a>>b;
    cout<<bitToChange(a,b)<<endl;
    return 0;
}