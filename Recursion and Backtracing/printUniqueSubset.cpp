// print unique subset of a string.

#include <iostream>
#include <set>
using namespace std;

void printUniqueSubset(string ip, string ans, set<string> &st)
{
    if (ip.length() == 0)
    {
        st.insert(ans);
        return;
    }
    char ch = ip[0];
    printUniqueSubset(ip.substr(1), ans, st);
    printUniqueSubset(ip.substr(1), ans + ch, st);
}

int main()
{
    string str;
    cin >> str;
    set<string> st;
    printUniqueSubset(str, " ", st);
    for (auto it : st)
    {
        cout << it << endl;
    }

    return 0;
}