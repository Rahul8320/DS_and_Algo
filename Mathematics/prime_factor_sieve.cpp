#include <iostream>
using namespace std;

void primeFactor(int n)
{
    int spf[n] = {0};
    for(int i=2;i<=n; i++)
    {
        spf[i] = i;
    }

    for(int i=2;i*i<=n;i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i;j<=n;j+=i)
            {
                if (spf[j]==j)
                {
                    spf[j] = i;
                }
            }
        }
    }

    int k = 0;
    while(n!=1)
    {
        if(spf[n] != k)
        {
            k = spf[n];
            cout << spf[n] << " ";
        }
        n = n /spf[n];
    }
    cout << endl;
    return;
}

int main()
{
    int n;
    cin >> n;
    primeFactor(n);
    return 0;
}