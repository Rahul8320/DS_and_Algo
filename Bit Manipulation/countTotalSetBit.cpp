#include<iostream>
using namespace std;

unsigned int countSetBitsUtils(unsigned int x)
{
    if(x <= 0)
        return 0;
    else
        return ((x&1)==0?0:1)+countSetBitsUtils(x/2);
}

unsigned int countSetBits(unsigned int n)
{
    int count=0;
    for(int i=1;i<=n;i++)
        count += countSetBitsUtils(i);
    return count;
}

int main()
{
    int n;
    cin>>n;
    cout<<countSetBits(n)<<endl;
    return 0;
}