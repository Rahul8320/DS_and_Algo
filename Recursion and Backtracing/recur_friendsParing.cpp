#include <iostream>
using namespace std;

int paring(int n)
{
    if(n==0 || n==1 || n==2)
    {
        return n;
    }

    return (paring(n-1) + (paring(n-2) * (n-1)));
}

int main()
{
    cout << paring(4) << endl;
    return 0;
}