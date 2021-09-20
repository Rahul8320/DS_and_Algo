// find first -ve number in sub array of given size k.

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void firstNegativeNumber(vector<int> arr,int k)
{
    for (int i = 0; i <arr.size()-2; i++){
        int j = 0;
        while(j<k){
            if(arr[i+j]<0){
                cout << arr[i+j] << " ";
                break;
            }
            j++;
        }
    }
    cout << endl;
}

void queue_impl(vector<int> arr,int k)
{
    queue<int> q;
    for (int i = 0,j=0;i<arr.size();i++){
        if(arr[i]<0){
            q.push(i);
        }
        if(i-j+1 == k){
            if(!q.empty()){
                cout << arr[q.front()] << " ";
                if(q.front() == j){
                    q.pop();
                }
            }
            j++;
        }
    }
    cout<< endl;
}

int main()
{
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;

    firstNegativeNumber(arr,k);
    queue_impl(arr, k);

    return 0;
}

// 2 -1 -9 3 -8 5 7 9 -4 -2 8 -1 -7

// Time complexity : O(kn) --> firstNegativeNumber()