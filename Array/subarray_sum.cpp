#include <bits/stdc++.h>
using namespace std;

void solution(int arr[],int n,int s)
{
    int i=0,j=0,st=-1,en=-1;
    int sum = 0;
    while (j<n & sum+arr[j] <= s)
    {
        sum += arr[j];
        j++;
    }
    if(sum == s)
    {
        cout << i+1 << " " << j << endl;
        return;
    }
    while (j<n)
    {
        sum += arr[j];
        while (sum > s)
        {
            sum -= arr[i];
            i++;
        }
        if(sum == s)
        {
            st = i+1;
            en = j+1;
            break;
        }
        j++;
    }
    cout << st << " " << en << endl;
    return;
}

int main()
{
    int size;
    cin >> size;
    int s;
    cin >> s;
    int arr[size];
    for(int i=0;i<size;i++){
        cin >> arr[i];
    }
    solution(arr,size,s);
    return 0;
}
