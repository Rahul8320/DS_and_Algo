// Fixed size Sliding window problem. calculate max or min sum of given size sub_array
 
#include<bits/stdc++.h>

using namespace std;

int maxSumSubarray(vector<int> arr,int k)
{
    int sum = 0;
    int maxsum = INT_MIN;
    for(int i = 0; i < k;i++){
        sum += arr[i];
    }
    maxsum = sum;
    for (int i = k;i<arr.size();i++){
        sum += arr[i];
        sum -= arr[i-k];
        maxsum = max(maxsum, sum);
    }
    return maxsum;
}

int minSumSubarray(vector<int> arr,int k)
{
    int sum = 0;
    int minSum = INT_MAX;
    for (int j = 0,i=0;j<arr.size();j++){
        sum += arr[j];
        if(j-i+1 == k){
            minSum = min(minSum, sum);
            sum -= arr[i];
            i++;
        }
    }
    return minSum;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(auto &i : arr)
        cin>>i;

    cout <<"Max Sum : "<< maxSumSubarray(arr, k) << endl;
    cout <<"Min Sum : "<< minSumSubarray(arr,k) << endl;

    return 0;
}

// 2 3 7 4 6 1 9 5 8 2    o/p --> max:22,min:11

// Time complexity : O(n) 