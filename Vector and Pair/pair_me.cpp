#include <bits/stdc++.h>
using namespace std;

void solution()
{
    int x,y,z;
    cin >> x >> y >> z;
    bool check = 0;
    if(x+y == z)
        check = 1;
    else if(x+z == y)
            check = 1;
        else if(y+z == x)
                check = 1;

    if(check)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
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
