#include <bits/stdc++.h>
using namespace std;

void Solution(string s)
{
    // only for lower case character
    int arr[26];
    for(int i=0;i<26;i++)
    {
        arr[i] = 0;
    }
    for(int i=0;i<s.size();i++)
    {
        arr[s[i] - 'a']++; // for upper case 'A'
    }
    char ans ='a'; // for upper case 'A'
    int count = 0;
    for(int i=0;i<26;i++)
    {
        if(arr[i]>count)
        {
            count = arr[i];
            ans = i + 'a';  // for upper case 'A'
        }
    }
    cout << ans << " --> " << count << endl;
}

int main()
{
    string str;
    getline(cin, str);
    Solution(str);

    // for lower and upper case.
    int arr[200];
    for(int i=0;i<200;i++)
    {
        arr[i] = 0;
    }
    for(int i=0;i<str.size();i++)
    {
        arr[str[i]] += 1;
    }
    int count = 0,ind=0;
    for(int i=0;i<200;i++)
    {
       if(arr[i] > count)
       {
           count = arr[i];
           ind = i;
       }
    }
    char ch = ind;
    cout << count << " <-- " << ch << endl;
    return 0;
}
