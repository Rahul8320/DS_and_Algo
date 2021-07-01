#include <bits/stdc++.h>
using namespace std;

void solution(int arr[],int n)
{
    const int N = 1e6+2;
    int array[N];
    for (int i = 0; i < N; i++)
    {
        array[i] = 0;
    }
    int upper = -1;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > 0)
        {
            array[arr[i]] = 1;
            upper = arr[i];
        }
    }
    int ans = -1;
    for (int i = 1; i <= upper; i++)
    {
        if(array[i] == 0 )
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return;
}

// void solution(int arr[],int n)
// {
//     const int N = 1e6+2;
//     bool array[N];
//     for (int i = 0; i < N; i++)
//     {
//         array[i] = 0;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if(arr[i] > 0)
//         {
//             array[arr[i]] = 1;
//         }
//     }
//     int ans = -1;
//     for (int i = 1; i < N; i++)
//     {
//         if(array[i] == 0 )
//         {
//             ans = i;
//             break;
//         }
//     }
//     cout << ans << endl;
//     return;
// }

int main()
{
    int size;
    cin >> size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin >> arr[i];
    }
    solution(arr,size);
    return 0;
}
