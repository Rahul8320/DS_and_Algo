#include<bits/stdc++.h>
using namespace std;

void solution(){
    bool check = false;
    string arr[41] ={"1","2","3","4","5","6","7","8","9","0","@","#","%","&","?","Q","W","E","R","T","Y","U","I","O","P","L","K","J","H","G","F","D","S","A","Z","X","C","V","B","N","M"};
    int len = 41;
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
