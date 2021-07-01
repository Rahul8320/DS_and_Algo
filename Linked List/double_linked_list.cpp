#include <iostream>
#include <string>

using namespace std;

class node
{
    public:
    node* prv;
    int data;
    node* nxt;

    node(int val)
    {
        data=val;
        prv=NULL;
        nxt=NULL;
    }
};

node* head = NULL;
node* temp = NULL;
string lastChange = "NULL";
string ll = " Empty Linked List ";

void insertAtHead(int val)
{
    node* n=new node(val);
    n->nxt=head;
    if(head!=NULL)
        head->prv=n;
    
    head=n;
}

void insertAtTail(int val)
{
    if(head==NULL)
    {
        insertAtHead(val);
        return;
    }
    node* n=new node(val);
    temp=head;
    while(temp->nxt!=NULL)
    {
        temp=temp->nxt;
    }
    temp->nxt=n;
    n->prv=temp;
}

bool searchKey(int key)
{
    if(head==NULL)
    {
        cout << ll << endl;
        return 0;
    }

    temp=head;
    while(temp!=NULL)
    {
        if(temp->data == key)
        {
            return 1;
        }
        temp=temp->nxt;
    }
    return 0;
}

void insertAtAny(int val)
{
    int key;
    cout<<" Enter the key to be searched : ";
    cin>>key;
    if(!searchKey(key))
    {
        cout << " Key Not Present \n";
        return;
    }
    cout << " 1. Insert Before the Key \n";
    cout << " 2. Insert After the Key \n";
    cin >> key;
    if(key == 1)
    {
        if(head==temp)
        {
            insertAtHead(val);
            return;
        }
        else {
            node* n = new node(val);
            n->nxt=temp;
            temp->prv->nxt=n;
            n->prv=temp->prv;
            temp->prv=n;
        }
    }else {
        node* n = new node(val);
        if(temp->nxt==NULL)
        {
            temp->nxt=n;
            n->prv=temp;
        }
        else {
            n->nxt=temp->nxt;
            temp->nxt->prv=n;
            n->prv=temp;
            temp->nxt=n;
        }
    } 
}

void deleteAtHead()
{
    if(head==NULL)
    {
        cout<<ll<<endl;
        return;
    }
    temp=head;
    if(temp->nxt==NULL)
    {
        head=NULL;
        delete(temp);
        return;
    }
    head=temp->nxt;
    temp->nxt->prv=NULL;
    temp->nxt=NULL;
    delete(temp);
}

void deleteAtTail()
{
    if(head==NULL)
    {
        cout << ll<<endl;
        return;
    }
    temp=head;
    if(temp->nxt==NULL)
    {
        head=NULL;
        delete(temp);
        return;
    }
    while(temp->nxt->nxt!=NULL)
    {
        temp=temp->nxt;
    }
    node* del = temp->nxt;
    temp->nxt=NULL;
    del->prv=NULL;
    delete(del);
}

void deleteAKey(int key)
{
   if(head==NULL)
    {
        cout << ll << endl;
        return;
    }

    temp=head;
    if(temp->data==key && temp->nxt==NULL)
    {
        head=NULL;
        delete(temp);
        return;
    }
    if(temp->data==key)
    {
        head=temp->nxt;
        temp->nxt->prv=NULL;
        temp->nxt=NULL;
        delete(temp);
        return;
    }
    while(temp!=NULL)
    {
        if(temp->data == key)
        {
            if(temp->nxt==NULL)
            {
                temp->prv->nxt=NULL;
                temp->prv=NULL;
                delete(temp);
                return;
            }
            else {
                temp->prv->nxt=temp->nxt;
                temp->nxt->prv=temp->prv;
                temp->prv=NULL;
                temp->nxt=NULL;
                delete(temp);
            }
        }
        temp=temp->nxt;
    }
    return;
}

void deleteAll()
{
    if(head==NULL)
    {
        cout << ll <<endl;
        return;
    }
    temp=head;
    while(temp!=NULL)
    {
        node* del = temp;
        temp=temp->nxt;
        head=temp;
        delete(del);
    }
    cout << " Full Linked List Deleted.\n";
}

int length()
{
    int l=0;
    temp=head;
    while(temp!=NULL)
    {
        l++;
        temp=temp->nxt;
    }
    return l;
}

void kNodeReverse(int pos)
{
    int l=length();
    pos=pos%l;
    node* newHead=NULL;
    node* newTail=NULL;
    node* tail=head;
    int count=1;

    while(tail->nxt!=NULL)
    {
        if(count==pos)
        {
            newTail=tail;
        }
        if(count==pos+1)
        {
            newHead=tail;
        }
        tail=tail->nxt;
        count++;
    }
    newTail->nxt=NULL;
    tail->nxt=head;

    head=newHead;
}

void kAppend(int k)
{
    int l=length();
    k=k%l;
    node* newHead=NULL;
    node* newTail=NULL;
    node* tail=head;
    int count=1;

    while(tail->nxt!=NULL)
    {
        if(count==l-k)
        {
            newTail=tail;
        }
        if(count==l-k+1)
        {
            newHead=tail;
        }
        tail=tail->nxt;
        count++;
    }
    newTail->nxt=NULL;
    tail->nxt=head;

    head=newHead;
}

void display()
{
    if(head==NULL)
    {
        cout << ll << endl;
        return;
    }
    temp=head;
    while(temp!=NULL)
    {
        cout << temp->data << "<--> ";
        temp=temp->nxt;
    }
    cout << "NULL \n";
}

void clrscr() 
{
  cout << "\n   Press Enter to proced. ";
  getchar();
  if (cin.get() == '\n')
    system("clear");

  // cout<< "\033[2J\033[1;1H";  // Clear screen output .
}

void menu() 
{
  while (1) {
    cout << "\n";
    cout << "0. Insert a Linked List." << endl;
    cout << "1. Insert at Head." << endl;
    cout << "2. Insert at Tail." << endl;
    cout << "3. Insert at Any Position." << endl;
    cout << "4. Search a Key." << endl;
    cout << "5. Display Linked List." << endl;
    cout << "6. Delete First Node." << endl;
    cout << "7. Delete Last Node." << endl;
    cout << "8. Delete a Key Node." << endl;
    cout << "9. Delete Full Linked List." << endl;
    cout << "10. Reverse Linked List after a given position." << endl;
    cout << "11. Length of Linked List." << endl;
    cout << "12. Append last k node at first(atleast 2 node)." << endl;
    cout << "13. Exit." << endl;

    cout << "\n  Linked List Status : ";
    display();
    cout << "  Last Change : "+ lastChange << endl;

    cout << endl;
    int choice;
    cout << "\t Enter your choice : ";
    cin >> choice;
    cout << endl;

    switch (choice) {
    case 0:
      int num;
      cout<<" How many node want to insert : ";
      cin>>num;
      for (int i=0; i<num; i++) {
        cout << " Enter the value : ";
        int k;
        cin>>k;
        insertAtTail(k);
      }
      lastChange = "0. Insert " + to_string(num) + " node into Linked List.";
      break;
    case 1:
      int val;
      cout << " Enter the value to be insert in linked-list : ";
      cin >> val;
      insertAtHead(val);
      lastChange = "1. Insert " + to_string(val);
      break;
    case 2:
      cout << " Enter the value to be insert in linked-list : ";
      cin >> val;
      insertAtTail(val);
      lastChange = "2. Insert " + to_string(val);
      break;
    case 3:
      cout << " Enter the value to be insert in linked-list : ";
      cin >> val;
      insertAtAny(val);
      lastChange = "3. Insert " + to_string(val);
      break;
    case 4: 
      cout << " Enter the key to be searched in linked-list : ";
      cin >> val;
      if (searchKey(val))
        cout << "\t Key is Present." << endl;
      else
        cout << "\t Key is NOT Present." << endl;
      break;
    case 5:
      display();
      break;
    case 6:
        deleteAtHead();
        lastChange = "6. Delete Head Node.";
        break;
    case 7:
        deleteAtTail();
        lastChange = "7. Delete Tail Node.";
        break;
    case 8:
        int key;
        cout<<" Enter the key to delete from list : ";
        cin>>key;
        if(searchKey(key))
        {
            deleteAKey(key);
            lastChange = "8. Delete " + to_string(key) +" Node.";
        }
        else {
            cout << " Key not present" << endl;
        }
        break;
    case 9:
        deleteAll();
        lastChange = "9. Delete Full Linked List.";
        break;
    case 10:
      if(head!=NULL){
        int pos;
        cout<<" Enter your pos : ";
        cin>>pos;
        kNodeReverse(pos);
        lastChange = "10. Reverseed after possition "+to_string(pos);
      }
      else
       cout<<"  Empty Linked List.\n";
      break;
    case 11:
        cout<<" Length : " << length() << endl;
        break;
    case 12:
        int k;
        cout << " Enter how many node want to append first : ";
        cin>>k;
        if(k<2)
            cout<<" Wrong Input.\n";
        else{
            kAppend(k);
            lastChange="12. Append last "+to_string(k)+" node at first.";
        }
        break;
    case 13:
      system("clear");
      cout << "\t Thank You. \n" << endl;
      exit(0);
      break;
    default:
      cout << "\t Wrong Choice \n \t Choice again." << endl;
    }
    clrscr();
  }
}

int main()
{
    // insertAtHead(5);
    // insertAtHead(3);
    // insertAtTail(7);
    // insertAtTail(9);
    // display();
    // cout << searchKey(10-1) << endl;

    cout << " <---- Welcome to Double Linked List Program ----> \n";
    menu();

    return 0;
}
