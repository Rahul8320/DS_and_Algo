#include <bits/stdc++.h>
using namespace std;

void solution(int arr[],int n)
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
    cout << ans << endl;
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
