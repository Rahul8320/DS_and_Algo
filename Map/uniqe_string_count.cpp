/* Given N strings, print unique strings in lexicographical order with their frequency */

#include<bits/stdc++.h>
#define sp " "

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, int> mp;
    for (int i = 0; i < n;i++) {
        string s;
        cin>>s;
        mp[s]++;
    }
    for(auto &it : mp) {
        cout << it.first<<sp<< it.second<< endl;
    }
    return 0;
}