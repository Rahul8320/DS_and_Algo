#include <iostream>
using namespace std;

int First(int arr[],int n,int i,int key)
{
    if(i==n)
        return -1;
        
    if (arr[i] == key)
        return i;

    return First(arr,n,i+1,key);
}

int Last(int arr[],int n,int i,int key)
{
    if(i==n)
        return -1;

    int index = Last(arr,n,i+1,key);

    if (index != -1)
        return index;
    
    if(arr[i] == key)
        return i;
    
    return -1;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<"First Occurrence : ";
    cout << First(arr,n,0,key)+1 << endl;
    cout << "Last Occurrence : ";
    cout << Last(arr,n,0,key)+1 << endl;
}