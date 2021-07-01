#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findUnique(unsigned int arr[],int n,int k)
{
    int INT_SIZE = 8 * sizeof(unsigned int);
    int count[INT_SIZE];
    memset(count,0,sizeof(count));
    for(int i=0;i<INT_SIZE;i++)
    {
        for(int j=0;j<n;j++)
            if((arr[j] & (1<<i)) != 0)
                count[i] += 1;
    }
    unsigned int res = 0;
    for(int i=0;i<INT_SIZE;i++)
    {
        res += ((count[i] % k) *(1 << i));
    }
    return res;
}

int main()
{
    unsigned int a[] = {6,2,5,2,2,6,6};
    int n = (sizeof(a) / sizeof(a[0]));
    int k = 3;
    cout<< findUnique(a,n,k)<<endl;
    return 0;
}