//  ''' Array implementation of Queue '''

#include <iostream>
using namespace std;

#define n 20

class Queue{
    int* arr;
    int front;
    int back;

    public:
    Queue(){
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void display(){
        if(front == -1 || front>back){
            cout <<"No element in Queue"<<endl;
            return;
        }
        int ptr = front;
        while(ptr<=back){
            cout << arr[ptr++]<<"--> ";
        }
        cout <<" Full" << endl;
    }

    void push(int x){
        if(back == n-1){
            cout<<"Queue Overflow"<<endl;
            return;
        }

        back++;
        arr[back] = x;
        
        if(front == -1){
            front++;
        }
    }

    void pop(){
        if(front == -1 || front>back){
            cout<<"No element in Queue"<<endl;
            return;
        }

        front++;
    }

    int peek(){
        if(front == -1 || front>back){
            cout<<"No element in Queue"<<endl;
            return -1;
        }
        return arr[front];
    }

    bool empty(){
        if(front == -1 || front>back){
            return true;
        }
        return false;
    }
};

int main(){
    Queue q;
    for(int i=5;i<10;i++){
        q.push(i);
    }
    q.display();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout<<q.peek()<<endl;
    q.display();
    cout << q.empty()<<endl;
    q.pop();
    q.pop();
    cout<<q.peek()<<endl;
    q.display();
    cout<<q.empty()<<endl;
    return 0;
}