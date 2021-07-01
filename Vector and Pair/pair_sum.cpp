#include <bits/stdc++.h>
using namespace std;

// void solution(int arr[],int n,int k)
// {
//     for (int i = 0; i < n-1; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
//             if (arr[i] + arr[j] == k)
//             {
//                 cout << i << " " << j << endl;
//                 return;
//             }
//         }
//     }
//     cout << "-1" << endl;
//     return ;
// }

void solution(int arr[],int n,int k)
{
    int low = 0;
    int high = n-1;
    while (low < high)
    {
        if(arr[low] + arr[high] == k)
        {
            cout << low << " " << high << endl;
            return;
        }
        if(arr[low] + arr[high] > k)
        {
            high--;
        }
        else
        {
            low++;
        }
    }
    cout << "-1" << endl;
    return ;
}

int main()
{
    int size;
    cin >> size;
    int k;
    cin >> k;
    int arr[size];
    for(int i=0;i<size;i++)
	{
        cin >> arr[i];
    }
    solution(arr,size,k);
    return 0;
}
