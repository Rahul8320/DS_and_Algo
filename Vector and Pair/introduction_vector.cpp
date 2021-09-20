#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // inserting elements at time declaration   
    vector<int> v={1,2,3,4,5,6,7};
    // printing elements through iterators 
    for(auto i=v.begin(); i!=v.end();i++){
        cout<<*i <<" ";
    }
    cout << endl;
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it <<" ";
    }
    cout<<endl;

    // vector declarations
    vector<int> v2;
    // inserting elements
    for (int i = 0; i < 10; i++)
    {
        v2.push_back(i);
    }
    // printing elements through reference
    for (int i = 0; i < v2.size(); i++)
    {
        cout<<v2[i]<<" ";
    }
    cout<< endl;

    vector<int>v3;
    // insert elements through assign function
    v3.assign(10,5);
    // printing elements through auto keyword
    for(auto it:v3){
        cout<<it << " ";
    }
    cout<< endl;
    
    // calculate size of vector
    cout<<"Size of v : "<<v.size()<<endl;
    cout<<"Max Size of v2 : "<<v2.max_size()<<endl;
    cout<<"Capacity of v3 : "<<v3.capacity()<<endl;
    cout <<"IsEmpty v3 : " << v3.empty()<< endl;

    // element access
    cout<< "v.at(3) : " << v.at(3)<<endl;
    cout << "v3.front() : " << v3.front()<<endl;
    cout<<"v2.back() : " << v2.back()<<endl;
    cout<<"v3.data() : " <<v3.data()<<endl;

    return 0;
}