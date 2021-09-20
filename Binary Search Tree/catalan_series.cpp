// print the catalan series.

#include <iostream>
#include <vector>
using namespace std;

long long int catalan(int n)
{
    if (n <= 1)
        return 1;
    long long int res = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        res += catalan(i) * catalan(n - i - 1);
    }
    return res;
}

vector<long double> catalanSeries(int n)
{
    vector<long double> res;
    res.push_back(1);
    if (n == 0)
    {
        return res;
    }
    res.push_back(1);
    if (n == 1)
    {
        return res;
    }

    for (int i = 2; i <= n; i++)
    {
        long double temp = 0;
        for (int k = 0; k < i; k++)
        {
            temp += res[k] * res[i - k - 1];
        }
        res.push_back(temp);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    // for(int i=1; i<=n; i++){
    //     cout<<catalan(i) <<" ";
    // }
    // cout<<endl;

    vector<long double> v;
    v = catalanSeries(n);
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}