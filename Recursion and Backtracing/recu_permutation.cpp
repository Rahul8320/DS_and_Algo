#include <iostream>
using namespace std;

void permutation(string str,string ans="")
{
    if(str.size()==0)
    {
        cout<<ans<<endl;
        return;
    }

    for(int i=0;i<str.length();i++)
    {
        char ch = str[i];
        string ros = str.substr(0,i) + str.substr(i+1);
        permutation(ros,ans+ch);
    }
}

int main()
{
    string s;
    cin>>s;
    permutation(s);
    return 0;
}