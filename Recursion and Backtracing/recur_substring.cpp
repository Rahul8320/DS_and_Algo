#include <iostream>
using namespace std;

void substring(string str, string ans)
{
    if(str.size() == 0)
    {
        cout << ans <<endl;
        return;
    }

    char ch = str[0];
    string ros = str.substr(1);
    substring(ros,ans);
    substring(ros,ans+ch);
}

void subseq(string str,string ans)
{
     if(str.size() == 0)
    {
        cout << ans <<endl;
        return;
    }

    char ch = str[0];
    int code = ch;
    string ros = str.substr(1);
    subseq(ros,ans);
    subseq(ros,ans+ch);
    subseq(ros,ans+to_string(code));
}

int main()
{
    // string str;
    // cin >> str;
    // substring(str,"");
    subseq("AB","");
    return 0;
}