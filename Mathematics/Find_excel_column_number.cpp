// find column number of excel sheet.
#include <bits/stdc++.h>

using namespace std;

// Returns result when we pass title.
// Time complexity : O(N)
int titleToNumber(string s)
{
    // This process is similar to binary-to-decimal conversion
    int result = 0;
    for (const auto &c : s)
    {
        result *= 26;
        result += c - 'A' + 1;
    }

    return result;
}

// Time complexity : O(N)
int columnNumber(string s)
{
    int result = 0;
    for(int i=0; i<s.length(); i++){
        result = result * 26; 
        result += s[i] - 'A' + 1;
    }
    return result;
}

// Driver function
int main()
{
    cout << titleToNumber("CDA") << endl;
    cout << columnNumber("UM")<<endl;
    return 0;
}