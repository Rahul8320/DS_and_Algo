#include <iostream>
using namespace std;

void binarySearch(int arr[],int n, int key)
{
    int flag=false;
    int index=0;
    int l=0;
    int h=n-1;
    while(l<=h)
    {
        if(arr[l]==key)
        {
            index=l;
            flag=true;
            break;
        }
        if(arr[h] == key)
        {
            index=h;
            flag=true;
            break;
        }
        int mid = (l+h)/2;
        if(arr[mid] == key)
        {
            index=mid;
            flag=true;
            break;
        }
        if(mid > key)
        {
            h = mid -1;
        }
        else
        {
            l = mid + 1;
        }
    }
    if(flag)
    {
        cout << "Key is present at " << index+1 << " position." << endl;
    }
    else
    {
        cout << "Key not present ." << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int key;
    cin >> key;
    binarySearch(arr,n,key);
}