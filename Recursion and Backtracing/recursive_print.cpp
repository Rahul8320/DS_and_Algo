#include <iostream>
using namespace std;

void decreasing(int n)
{
    if(n==0)
        return;
    else
    {
        cout << n << " ";
        decreasing(n-1);
    }
}

void increasing(int n)
{
    if(n==0)
        return;
    else
    {
        increasing(n-1);
        cout << n << " ";
    }
}

void inc_dec(int n)
{
    if(n==0)
    {
        cout << endl;
        return;
    }
    else
    {
        cout << n << " ";
        inc_dec(n-1);
        cout << n << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    decreasing(n);
    cout << endl;
    increasing(n);
    cout << endl;
    inc_dec(n);
    cout << endl;
    return 0;
}
