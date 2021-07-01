#include <bits/stdc++.h>
using namespace std;

void solution(int arr[],int n){
    int brr[1000000];
    for(int i=0;i<1000000;i++){
        brr[i] = 0;
    }

    for(int i=0;i<n;i++){
       brr[arr[i]] = brr[arr[i]] + 1;
   }

   for(int i=0;i<n;i++){
       if(brr[arr[i]] > 1){
           cout << (i+1) << endl;
           return;
       }
   }
}

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
