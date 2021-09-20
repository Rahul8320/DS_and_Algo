#include <bits/stdc++.h>
using namespace std;

int max_area_rectangle(vector<int> a)
{
    a.push_back(0);
    int n=a.size(),ans=0,i=0;
    stack<int> st;

    while(i<n){
        while(!st.empty() and a[st.top()]>a[i]){
            int h = a[st.top()];
            st.pop();
            if(st.empty()){
                ans = max(ans, h * i);
            }
            else{
                int len = i - st.top() - 1;
                ans = max(ans,h*len);
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}

int main()
{
    vector<int> a{6,2,5,4,5,1,6};
    cout <<max_area_rectangle(a)<<endl;
    
    return 0;
}

// Time complexity : O(n) 