#include<iostream>
using namespace std;

void non_repeat_ele(int arr[],int n)
{
    int res=0;int x=0,y=0;
    for(int i=0;i<n;i++)
    {
        res ^= arr[i];
    }
    int set_bit_no = (res & ~(res-1));
    for(int i=0;i<n;i++)
    {
        if(arr[i] & set_bit_no)
            x = (x ^ arr[i]);
        else 
            y = (y ^ arr[i]);
    }
    cout << x <<" " << y<<endl;
}

int main()
{
    int n;
    cout<<"Enter array size : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    non_repeat_ele(arr,n);
    return 0;
}