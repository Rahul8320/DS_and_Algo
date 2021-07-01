#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin,str);
    int n = str.size();
    int arr[100];
    for(int i=0;i<100;i++)
    {
        arr[i] = 0;
    }
    for (int i=0;i<n;i++)
    {
        char s[] = {str[i]} ;
        int k = atoi(s);
        arr[k] += 1; 
    }
    for(int i = 99;i>0;i--)
    {
        if(arr[i] > 0 )
            while(arr[i] != 0)
            {
                arr[i] -= 1;
                cout << i ;
            }
    }
    cout << endl;

    cout << "Sort methods : " << endl;
    // sort function to sort the string decreasing order .
    sort(str.begin(), str.end(), greater<int>());
    cout << str << endl;
    return 0;
}