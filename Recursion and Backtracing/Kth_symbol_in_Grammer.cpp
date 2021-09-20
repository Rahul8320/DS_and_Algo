// find kth symbol in grammar

#include <iostream>
#include <vector>
using namespace std;

vector<int> kth_symbols(int n)
{
    vector<int> v;
    if (n == 0)
    {
        v.push_back(0);
        return v;
    }
    v = kth_symbols(n - 1);
    vector<int> temp;
    for (auto it : v)
    {
        if (it == 0)
        {
            temp.push_back(0);
            temp.push_back(1);
        }
        if (it == 1)
        {
            temp.push_back(1);
            temp.push_back(0);
        }
    }
    return temp;
}

vector<int> kth_symbol(int n)
{
    vector<int> v;
    if (n == 1)
    {
        v.push_back(0);
        v.push_back(1);
        return v;
    }
    v = kth_symbol(n - 1);
    int size = v.size();
    for (int i = n - 1; i < size; i++)
    {
        int it = v[i];
        if (it == 0)
        {
            v.push_back(0);
            v.push_back(1);
        }
        else if (it == 1)
        {
            v.push_back(1);
            v.push_back(0);
        }
    }

    return v;
}

int kthSymbol(int n, int k, vector<int> &res)
{
    if (n == 1)
    {
        res.push_back(0);
        return 0;
    }
    if (k < n)
        return kthSymbol(n - 1, k, res);
    int temp = kthSymbol(n - 1, k, res);
    for (auto it : res)
    {
        res.push_back(!it);
    }
    if (res.size() > k)
        return res[k];
    else
        return -1;
}
int main()
{
    int n, k;
    cin >> n >> k;
    // res
    vector<int> res;
    cout << "KthSymbol : " << kthSymbol(n, k, res) << endl;

    // kth_symbol
    vector<int> vc;
    vc = kth_symbol(n - 1);
    for (auto it : vc)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << "Kth Symbol : ";
    cout << vc[k - 1] << endl;

    // kth_symbols
    vector<int> vc2;
    vc2 = kth_symbols(n - 1);
    for (auto it : vc2)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << "Kth Symbol : ";
    cout << vc2[k - 1] << endl;

    return 0;
}