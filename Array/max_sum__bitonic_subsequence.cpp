#include<bits/stdc++.h>
using namespace std;

void solution()
{
    int size;
    cin >> size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    int en = 0;
    int sum = 0;
    int ans = 0;

    if(arr[1] > arr[0])
    {
        sum += arr[0];
    }
    else
    {
        ans = arr[0];
    }
    
    for (int i = 0; i < size-1; i++)
    {
        if(arr[i+1] > arr[i])
        {
            sum += arr[i+1];
            en = i+1;
        }
    }
    for (int i = en; i < size-1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            sum += arr[i+1];
        }
    }
   
    for (int i = 0; i < size-1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            ans += arr[i+1];
        }
    }
    if (sum > ans)
        cout << sum << endl;
    else
        cout << ans << endl;
    
    return;
}

int main()
{
	int t;
	cin >> t;
	while(t >0)
    {
        t--;
		solution();
	}
	return 0;
}
