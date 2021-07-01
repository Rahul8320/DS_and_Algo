#include <iostream>
using namespace std;

int gcd(int a,int b)
{
    int m = max(a,b);
    int n = min(a,b);
    
    while(n != 0)
    {
        int rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}

int main()
{
    int a,b;
    cin >> a >> b;
    cout << gcd(a,b) << endl;
    return 0;
}