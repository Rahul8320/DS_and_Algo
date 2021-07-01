#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;
    char arr[size+1];
    cin >> arr;
    // cout << arr << endl;
    bool check = 1;
    for(int  i=0;i<size;i++)
    {
        if(arr[i] != arr[size-1-i])
        {
            check = 0;
            break;
        }
    }
    if(!check)
    {
        cout << "Given String is not a Palindrome." << endl;
    }
    else
    {
        cout << "Given String is a Palindrome String." << endl;
    }
    
    return 0;
}
