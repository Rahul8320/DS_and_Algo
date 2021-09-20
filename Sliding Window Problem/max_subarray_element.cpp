// print the max of k elements from array , sliding window problem

#include<iostream>
#include<queue>

using namespace std;

int main()
{
    // input 
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // logic
    queue<int> q;
    for(int i=0,j=0;i<n;i++){
        if(q.empty()){
            q.push(i);
        }
        else{
            if(arr[i]>arr[q.back()]){
                q.push(i);
            }
        }
        if(i-j+1 == k){
            cout<< arr[q.front()]<<" ";
            q.pop();
            j++;
        }
    }
    cout << endl;
    return 0;
}