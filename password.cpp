#include<bits/stdc++.h>
using namespace std;

void solution(){
    bool check = false;
    string arr[] ={1234567890@#%&?QWERTYUIOPLKJHGFDSAZXCVBNM};
    int len = arr.length();
    string s;
    cin >> s;
    int n = s.length();
    if(s.length() >= 10)
    {
        for(int i=0;i<len;i++)
        {
            if(s[0] == arr[i] | s[n-1] == arr[i]);
            {
                check = true;
                break;
            }
        }
        
    }
    else
        check = true;

    if(check)
        cout << "NO" << endl;
    return;
}

int main()
{
	int t;
	cin >> t;
	while(t >0){
        t--;
		solution();
	}
	return 0;
}
