#include <iostream>
using namespace std;

int powerof2(int n)
{
    return (n && !(n & n-1));
}

int main()
{
    int n;
    cin >> n;
    cout << powerof2(n) << endl;
    return 0; 
}
