#include <iostream>
using namespace std;

int power(int n, int p)
{
    if(p == 0)
        return 1;
    else 
        return (n * power(n,p-1));
}

int main()
{
    int n,p;
    cin >> n >> p;
    cout << n << "^" << p <<" = " << power(n,p) << endl;
    return 0;
}