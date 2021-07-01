#include <iostream>
using namespace std;

class student
{
    string name;
    int roll;

    public:
    
    string dept;
    int year;

    void getname()
    {
        cout<< "Name : " << name <<endl;
    }
    void getroll()
    {
        cout <<"Roll : " << roll<<endl;
    }
    void info()
    {
        cout << "Name : " << name << endl;
        cout<<"Roll : " << roll << endl;
        cout<<"Dept : " << dept << endl;
        cout<<"Year : " <<year<<endl;
    }
    student()
    {
        cout<<"Default"<<endl;
    }
    student(string s,int n,string d,int y)
    {
        name=s;
        roll=n;
        dept=d;
        year=y;
    }

};

int main()
{
    student a;
    student b("Rahul",49,"CSE",3);
    b.getname();
    b.getroll();
    student c("Raj",26,"ME",2);
    c.info();
    return 0;
}
 