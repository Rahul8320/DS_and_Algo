#include<iostream>
using namespace std;

int findBit(int n,int i)
{
    int mask = 1 << i;
    if(n & mask)
        return 1;
    else 
        return 0;
}

int setBit(int n,int i)
{
    int mask = 1 << i;
    n = (n | mask);
    return n;
}

int clearBit(int n,int i)
{
    int mask = ~(1 << i);
    return(n & mask);
}

int main()
{
    cout<<findBit(4,1)<<endl;
    cout<<setBit(4,1)<<endl;
    cout<<clearBit(4,2)<<endl;
    return 0;
}