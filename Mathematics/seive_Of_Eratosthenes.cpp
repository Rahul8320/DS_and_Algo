#include <bits/stdc++.h>
using namespace std;

void seiveOfEratosthemes(bool arr[], int n)
{
    arr[0]=false;
    arr[1]=false;
    for(int i=2;i*i<=n;i++)
    {
        for(int j=i*2;j<=n;j+=i)
        {
            arr[j]=false;
        }
    }
}

int main()
{
    int n=20;
    bool arr[n+1];
    memset(arr, true, sizeof(arr));
    seiveOfEratosthemes(arr,n);
    cout << "Prime numbers are : " << endl;
    for(int i=0;i<=20;i++)
    {
        if(arr[i])
            cout << i << " ";
    }
    cout<<endl;
    return 0;
}