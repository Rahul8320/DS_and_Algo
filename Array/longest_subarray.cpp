#include<bits/stdc++.h>
using namespace std;

void solution(){
    int size;
    cin >> size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin >> arr[i];
    }

    int ans = 0;
    for(int i=0;i<size;i++){
        int count = 0;
        while(arr[i] >= 0 & i < size){
            count ++;
            i++;
        }
        if(count > ans)
            ans = count;
    }
    cout << ans << endl;
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