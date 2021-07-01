#include <iostream>
#include <vector>      // header file required
using namespace std;

int main()
{
    vector<int> v; // decleration
    v.push_back(1);
    v.push_back(2);
    v.push_back(3); // add value

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;   // print all element
    }

    v.push_back(4);
    v.push_back(5);

    vector<int> :: iterator it;
    for(it=v.begin();it!=v.end();it++)
    {
        cout << *it <<" ";    // print all element
    }
    cout << endl;

    v.push_back(6);
    v.push_back(7);
    for(auto e:v)
    {
        cout << e << endl;     // print all element
    }

    v.pop_back(); // remove last element

    vector<int> v2(5,1);  // create v2 --> v2[1,1,1,1,1] all 5 element is 1

    swap(v,v2); // swap two vector 

    for(auto el:v)
    {
        cout << el << " ";
    }
    cout << endl;
    for(auto ele:v2)
    {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}