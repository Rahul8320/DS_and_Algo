#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n); // create vector 
    for (auto &i : arr)
        cin>>i;

    multiset<int, greater<int>> st; // create multiset which top element always greater
    vector<int> ans;

    for (int i = 0;i<k;i++)
        st.insert(arr[i]);

    ans.push_back(*st.begin());
    for (int i = k ; i < n; i++)
    {
        st.erase(st.lower_bound(arr[i - k]));
        st.insert(arr[i]);
        ans.push_back(*st.begin());
    }

    for (auto i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}

// Time complexity : O(n*Log(n))