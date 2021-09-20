#include <iostream>
#include<vector>
using namespace std;

void insert(vector<int> &v, int temp) 
{
    // base condition 
    if(v.size()==0 || v[v.size()-1]<temp){
        v.push_back(temp);
        return;
    }

    // hypothesis
    int val = v[v.size()-1];
    v.pop_back();
    insert(v, temp);

    // induction
    v.push_back(val);
    return;
}

void sort_array(vector<int> &vc)
{
    // base condition
    if (vc.size() == 1)
        return;

    // hypothesis
    int temp = vc[vc.size()-1];
    vc.pop_back();
    sort_array(vc);

    // induction
    insert(vc,temp); 
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort_array(arr);
    for (auto it:arr)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}