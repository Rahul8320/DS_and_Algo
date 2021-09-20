#include <bits/stdc++.h>
using namespace std;


void solution()
{
    int n;
    cin>>n;
    string arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    int array[26];
    for(int i=0;i<26;i++)
    {
        array[i] = 0;
    }

    for(int j=0;j<n;j++)
    {
        char ch = arr[j][0]; 
        array[ch - 97]++;
    }

    int count = 0;
    for(int i=0;i<26;i++)
    {
        if (array[i] == 1)
        {
            count++;
        }
    }

    cout << count << endl;

    return;
}

int main()
{
	int n;
    cin >> n;
    while(n){
        n = n-1;
        solution();
    }
	return 0;
}
