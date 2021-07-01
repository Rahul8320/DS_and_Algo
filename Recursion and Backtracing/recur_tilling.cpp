#include <iostream>
using namespace std;

int tillingWays(int n)
{
    if(n==0 || n==1)
        return n;
    
    return (tillingWays(n-1) + tillingWays(n-2));
}

int main()
{
    cout << tillingWays(4) << endl;
    return 0;
}