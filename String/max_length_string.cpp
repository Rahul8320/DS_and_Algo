#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    char arr[n+1];
    cin.getline(arr,n+1);
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] ;
    }
    cout << endl;
    
    int i=0;
    int curLen = 0, maxLen = 0;
    int st = 0, skipwd = 0;
    
    while (1)
    {
        if(arr[i] == ' ' || arr[i] == '\0')
        {
            if(curLen > maxLen)
            {
                maxLen = curLen;
                skipwd = st;
            }
            st = i+1;
            curLen = 0;
        }
        else
            curLen++;

        if(arr[i] == '\0')
            break;

        i++;
    }
    cout << maxLen << endl;
    for(int i=0;i<maxLen;i++)
        cout << arr[i+skipwd];
    
    cout << endl;

    return 0;
}
