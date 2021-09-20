#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin >> n; // taking array or vector size
    vector<int> arr(n,0);  // initialize vector(size,values) with 0 value for all elements
    int q;
    cin >> q;  // taking number of queries
    while(q--){
        int l,r;
        cin >> l>>r;
        arr[l]++;      // increment starting point
        if(r+1<n){
            arr[r+1]--;  // decrement after the endding point
        }
    }
    for (int i=1;i<n;i++){
        arr[i]+=arr[i-1];   // taking  cumulative sum 
    }
    for (int i=0;i<n;i++){
        cout << arr[i]<<" ";  // printing result vector
    }
    cout << endl;

    return 0;
}

// time complexity :- O(q+n)

// difference vector 
// [0,1,2,0,-1,-2]  ->  2,4  1,4  2,3 
// [0,1,3,3,2,0]