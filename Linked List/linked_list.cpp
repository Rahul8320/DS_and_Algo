#include <cstdlib>
#include <iostream>
#include <new>
#include <string>

using namespace std;

class node {
public:
  int data;
  node *next;

  node(int val) {
    data = val;
    next = NULL;
  }
};
node *head = NULL;
node *ptr = NULL;
string lastChange = "NULL";

void insertHead(int val) {
  node *n = new node(val);
  n->next = head;
  head = n;
}

bool search(int key) {
  ptr = head;
  while (ptr != NULL) {
    if (ptr->data == key) {
      return true;
    }
    ptr = ptr->next;
  }
  return false;
}

void insertTail(int val) {
  if (head == NULL) {
    insertHead(val);
    return;
  }
  node *n = new node(val);

  ptr = head;
  while (ptr->next != NULL) {
    ptr = ptr->next;
  }
  ptr->next = n;
}

void insertAny(int val) {
  int key;
  cout << " Enter the key to search : ";
  cin >> key;
  if (search(key)) {
    int pos;
    cout << " Enter \n 1. Before \n 2. After \n the value : ";
    cin >> pos;
    if (pos == 2) {
      node *n = new node(val);
      if (ptr->next == NULL) {
        ptr->next = n;
      } else {
        n->next = ptr->next;
        ptr->next = n;
      }
    }
    if (pos == 1) {
      ptr = head;
      node *lptr = ptr;
      node *n = new node(val);
      while (ptr->data != key) {
        lptr = ptr;
        ptr = ptr->next;
      }
      if (ptr == head) {
        n->next = head;
        head = n;
      } else {
        n->next = lptr->next;
        lptr->next = n;
      }
    }
  } else {
    cout << " Key NOT present." << endl;
  }
}

void deleteAtHead() {
  ptr = NULL;
  if (head == NULL) {
    cout << " Empty Linked List." << endl;
    return;
  }
  if (head->next == NULL) {        //! only one node present
    ptr = head;
    head = NULL;
    ptr->next = NULL;
    delete (ptr);
    return;
  } else {                //! delete first node
    ptr = head;
    head = head->next;
    ptr->next = NULL;
    delete (ptr);
    return;
  }
}

void deleteAkey(int key) {
  ptr = NULL;
  if (head == NULL) {
    cout << " Empty Linked List." << endl;
    return;
  }
  if(!search(key))
  {
    cout<<" Key Not Present."<<endl;
    return;
  }
  if (head->next == NULL && head->data == key) {       //! key is only one node 
    ptr = head;
    head = NULL;
    ptr->next = NULL;
    delete (ptr);
    return;
  }
  if (head->data == key) {             //! key in head node with others
    ptr = head;
    head = head->next;
    ptr->next = NULL;
    delete (ptr);
    return;
  }
  ptr = head;
  node* del=NULL;
  while (ptr->next->data != key) {
    ptr=ptr->next;                 //?  Find pervious node
  }
    del = ptr->next;
    if (ptr->next->next == NULL) {        //! key is last node
      ptr->next = NULL;
      delete (del);
      return;
    }
    ptr->next = ptr->next->next;
    delete (del);
}

void deleteAtTail() {
  ptr = NULL;
  if (head == NULL) {
    cout << " Empty Linked List." << endl;
    return;
  }
  if (head->next == NULL) {     //! only one key node
    ptr = head;
    head = NULL;
    delete (ptr);
    return;
  }               //! Last node
    ptr = head;
    while (ptr->next->next!= NULL) {
      ptr = ptr->next;              //? Find pervious node
    }
    node* del = ptr->next;
    ptr->next=NULL;
    delete (del);
    return;
  
}

void deleteAll()
{
    ptr = head;
    if (head == NULL) {      //! check for empty list
        cout << " Empty Linked List." << endl;
        return;
    }
    while (ptr!=NULL) {        //? delete all node
        node* del = ptr;
        ptr=ptr->next;
        head=ptr;
        delete(del);
    }
    cout<<" Full List Deleted."<<endl;
}

void display() {
  ptr = head;
  if(head == NULL)
  {
    cout<<" Empty Linked List.\n";
    return;
  }
  while (ptr != NULL) {
    cout << ptr->data << "--> ";
    ptr = ptr->next;
  }
  cout << "NULL" << endl;
}

void reverseLinkList()
{
  node* pervious = NULL;
  node* current = head;
  node* next;
  while(current!=NULL)
  {
    next = current->next;
    current->next = pervious;
    pervious=current;
    current=next;
  }
  head=pervious;
  cout << "  Linked List reverse successfull.\n";
}

node* reverseRecursive(node* &head)
{
  if(head == NULL || head->next == NULL)
    return head;

  node* newhead = reverseRecursive(head->next);
  head->next->next=head;
  head->next = NULL;
  return newhead;
}

node* reversekNode(node* &head,int k)
{
  node* pre = NULL;
  node* cur = head;
  node* nxt;

  int count = 0;
  while(cur!=NULL && count < k)
  {
    nxt = cur -> next;
    cur->next = pre;

    pre=cur;
    cur=nxt;
    count++;
  }

  if(nxt!=NULL)
  {
    head->next = reversekNode(nxt, k);
  }

  return pre;
}

void clrscr() {
  cout << "\n   Press Enter to proced. ";
  getchar();
  if (cin.get() == '\n')
    system("clear");

  // cout<< "\033[2J\033[1;1H";  // Clear screen output .
}

void menu() {
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
    cout << "10. Reverse Linked List." << endl;
    cout << "11. Reverse with Recurssion." << endl;
    cout << "12. Reverse K Node. " << endl;
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
        insertTail(k);
      }
      lastChange = "0. Insert " + to_string(num) + " node into Linked List.";
      break;
    case 1:
      int val;
      cout << " Enter the value to be insert in linked-list : ";
      cin >> val;
      insertHead(val);
      lastChange = "1. Insert " + to_string(val);
      break;
    case 2:
      cout << " Enter the value to be insert in linked-list : ";
      cin >> val;
      insertTail(val);
      lastChange = "2. Insert " + to_string(val);
      break;
    case 3:
      cout << " Enter the value to be insert in linked-list : ";
      cin >> val;
      insertAny(val);
      lastChange = "3. Insert " + to_string(val);
      break;
    case 4: // int val;
      cout << " Enter the key to be searched in linked-list : ";
      cin >> val;
      if (search(val))
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
        deleteAkey(key);
        lastChange = "8. Delete " + to_string(key) +" Node.";
        break;
    case 9:
        deleteAll();
        lastChange = "9. Delete Full Linked List.";
        break;
    case 10:
      if(head!=NULL){
        reverseLinkList();
        lastChange = "10. Reverseed Linked List.";
      }
      else
       cout<<"  Empty Linked List.\n";
      break;
    case 11:
      if (head!=NULL)
      {
        head = reverseRecursive(head);
        cout << " Linked List reversed Successfull.\n";
        lastChange = "11. Reverseed Linked List.";
      }
      else {
        cout<<"  Empty Linked List.\n";
      }
      break;
    case 12:
    if(head != NULL)
    {
      int k;
      cout << " Enter the k value : ";
      cin >> k;
      head = reversekNode(head,k);
      lastChange = "12. Reversed " + to_string(k) + " Node";
    }
    else {
      cout<<"  Empty Linked List.\n";
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

void makeCycle(int pos)
{
  ptr=head;
  node* startNode;

  int count=1;
  while(ptr->next!=NULL)
  {
    if(count==pos)
    {
      startNode=ptr;
    }
    count++;
    ptr=ptr->next;
  }
  ptr->next=startNode;
}

bool deteceCycle()
{
  node* slow = head;
  node* fast = head;

  while(fast!=NULL && fast->next!=NULL)
  {
    slow = slow->next;
    fast = fast->next->next;

    if(slow==fast)
    {
      return true;
    }
  }
  return false;
}

void removeCycle()
{
  node* slow = head;
  node* fast = head;

  do
  {
    slow = slow->next;
    fast = fast->next->next;
  }while(slow!=fast);
  
  slow=head;
  while(slow->next!=fast->next)
  {
    slow=slow->next;
    fast=fast->next;
  }
  fast->next=NULL;
}

int main() {
  // clrscr();
  cout << " <---- Welcome to Program ----> \n";
  // menu();
  for(int i=0;i<6;i++)
  {
    insertTail(i+1);
  }
  display();
  makeCycle(5);
  if(deteceCycle())
  {
    cout << "Cycle Present in Linked List.\n";
    removeCycle();
    cout<<"Cycle removed Successfull.\n";
    display();
  }
  else {
    cout << "Cycle Not Present.\n";
  }
  cout<<deteceCycle()<<endl;
  return 0;
}
