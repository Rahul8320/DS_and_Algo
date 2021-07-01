#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s = "Hello I am Rahul";

    // convert the string into upper case from begin to end.
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    // cout << s << endl;
    
    // convert the string into lower case from begin to end.
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    // cout << s << endl;

    // string str;
    // cin >> str;
    // cout << str << endl;

    // string str1(5, 's');
    // cout << str1 << endl;

    // string str;
    // getline(cin,str);
    // cout << str << endl;

    string s1 = "fam";
    string s2 = "ily";

    cout << s1+s2 << endl; // append two string 

    s1.clear(); // clear the entires string 

    return 0;
}