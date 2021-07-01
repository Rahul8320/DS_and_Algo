#include <bits/stdc++.h>
using namespace std;

int kadane(int arr[],int n)
{
    int current = 0;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        current += arr[i];
        if (current < 0)
        {
            current = 0;
        }
        ans = max(ans,current);
    }
    return ans;
}

void solution(int arr[],int n)
{
    int wrapsum,nonwrapsum;
    nonwrapsum = kadane(arr,n);
    int totalsum = 0;
    for (int i = 0; i < n; i++)
    {
        totalsum += arr[i];
        arr[i] = -arr[i];
    }
    wrapsum = totalsum + kadane(arr,n);
    cout << max(wrapsum,nonwrapsum);
    return;
}

int main()
{
    int size;
    cin >> size;
    int arr[size];
    for(int i=0;i<size;i++)
	{
        cin >> arr[i];
    }
    solution(arr,size);
    return 0;
}
