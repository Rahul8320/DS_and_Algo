#include <bits/stdc++.h>
using namespace std;

void solution(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << arr[k] <<" ";
            }
            cout << endl;
        }
    }
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
