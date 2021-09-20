// print all permutation with space for a given string.

#include <iostream>
using namespace std;

void printPermutations(string ip, string ans)
{
    if (ip.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    string ch = ip.substr(0,1);
    string substr = ip.substr(1);
    printPermutations(substr, ans+ch);
    printPermutations(substr, ans + "-" + ch);
}

int main()
{
    string str = "ABC";
    cin>>str;
    printPermutations(str.substr(1), str.substr(0,1));

    return 0;
}