#include <iostream>
using namespace std;

void moveX(string str)
{
    if (str.length() == 0)
        return;

    char ch = str[0];
    if(ch != 'x')
    {
        cout << ch;
        moveX(str.substr(1));
    }
    else
    {
        moveX(str.substr(1));
        cout << ch;
    } 
}

string moveAllX(string str)
{
    if(str.length() == 0)
        return "";

    char ch=str[0];
    string ans = moveAllX(str.substr(1));
    if(ch == 'x')
        return (ans+ch);
    else 
        return (ch+ans);
}

int main()
{
    string str;
    cin>>str;
    moveX(str);
    cout << endl;
    cout << moveAllX(str) << endl;
    return 0;
}