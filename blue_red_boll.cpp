#include<iostream> 
using namespace std;

int main()
{
    int n;
    cout << "Enter how many boll are their : ";
    cin >> n;
    char arr[2*n+1];
    for(int i=0;i<n;i++){
        arr[i] = 'B';
    }
    arr[n] = '_';
    for(int i=n+1;i<=2*n;i++){
        arr[i] = 'R';
    }
    for(auto i:arr){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
