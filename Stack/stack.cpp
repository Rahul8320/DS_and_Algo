#include <bits/stdc++.h>
using namespace std;

#define n 100

class Stack{
    int* arr;
    int top;

    public:
        Stack(){
            arr = new int[n];
            top = -1;
        }

        void Push(int val){
            if(top==n-1){
                cout<<"Stack Overflow"<<endl;
                return;
            }

            top++;
            arr[top] = val;
        }

        int Pop(){
            if(top==-1){
                cout<<"No element to Pop."<<endl;
                return -1;
            }
            top--;
            return arr[top+1];
        }

        int Top(){
            if(top==-1){
                cout<<"No element at Stack."<<endl;
                return -1;
            }
            return arr[top];
        }

        bool Empty(){
            return (top==-1);
        }

        void Status(){
            if(top==-1){
                cout<<"No element at Stack."<<endl;
                return;
            }
            int k=0;
            while(k<=top){
                cout << arr[k] << " ";
                k++;
            }
            cout<<endl;
        }
};

int main(){
    Stack st;

    while(1)
    {
        getchar();
        if (cin.get() == '\n')
            system("clear");

        cout<<"1. Push \n2. Pop \n3. Top \n4. Empty \n5. Status \n6. Exit"<<endl;
        int key;
        cout << "\t Enter your choice : ";
        cin>>key;
        switch (key)
        {
        case 1:
            int val;
            cout<<"Enter value to push :";
            cin>>val;
            st.Push(val);
            break;

        case 2:
            cout<<"Element Pop : "<<st.Pop() <<endl;
            break;

        case 3:
            cout<<"Top : "<<st.Top()<<endl;
            break;

        case 4:
            cout<<"Empty : "<<st.Empty()<<endl;
            break;

        case 5:
            st.Status();
            break;
        
        case 6:
            exit(0);
            break;
        
        default:
            cout<<" Invalid Choice!!"<<endl;
            break;
        }
    }
    return 0;
}