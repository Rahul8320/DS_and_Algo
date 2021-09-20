// print all subset from a given string.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printSubset(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    string substr = s.substr(1);
    char ch = s[0];
    printSubset(substr, ans);
    printSubset(substr, ans + ch);
}

// print subset in lexicographical order.
void printSubsetLexico(string s, string ans, vector<string> &vc)
{
    if (s.length() == 0)
    {
        vc.push_back(ans);
        return;
    }
    string substr = s.substr(1);
    char ch = s[0];
    printSubsetLexico(substr, ans, vc);
    printSubsetLexico(substr, ans + ch, vc);
}

int main()
{
    string str;
    cin >> str;
    cout << "Subset are : " << endl;
    // printSubset(str," ");

    // print subset in lexicographical order.
    vector<string> vc;
    printSubsetLexico(str, " ", vc);
    sort(vc.begin(), vc.end());
    for (auto it : vc)
    {
        cout << it << endl;
    }

    return 0;
}
