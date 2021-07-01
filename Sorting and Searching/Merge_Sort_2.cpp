#include<bits/stdc++.h>
using namespace std;

void Merge(int arr[],int p,int q,int r)
{
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1+1];
    int R[n2+1];

    for (int i = 0; i < n1; i++)
    {
        L[i]=arr[p+i];
    }
    L[n1]=INT_MAX;
    for (int i = 0; i < n2; i++)
    {
        R[i]=arr[q+i+1];
    }
    R[n2]=INT_MAX;
    
    int i=0;
    int j=0;
    for (int k = p; k <= r; k++)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }
}

void Merge_Sort(int arr[],int p,int r)
{
    if(p<r)
    {
        int q = (p+r)/2;
        Merge_Sort(arr,p,q);
        Merge_Sort(arr,q+1,r);
        Merge(arr,p,q,r);
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    Merge_Sort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
    return 0;
}