/* Given N strings and Q queries.In each query you are given a string print frequency of that string.*/

#include<bits/stdc++.h>
#define sp "  :  "
using namespace std;

void print(unordered_map<string,int> &mp)
{
    cout << "Size : " << mp.size() << endl;
    for(auto &it : mp){
        cout<<it.first << sp <<it.second << endl;
    }
}

int main()
{
    unordered_map<string, int> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n;i++) {
        string s;
        cin >> s;
        mp[s]++;
    }

    print(mp);
    int q;
    cin>>q;
    while(q--){
        string s;
        cin >> s;
        cout << s << sp << mp[s] << endl;
    }
    return 0;
}