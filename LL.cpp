// Saturday 8/4/2023;
// Linked List started
// dynamically grow //shrink
// non-continuous memory allotcation
// collection of nodes
// node contains data and pointer to next node  [data,address]
// singly circular doubly circular doubly

//
// maggi ka packet phod do
// pani grm krlo
// maggi pani me dalo
// masala dal do
// 3 min wait
// plate me daldo

/////////////////////////////////////////////////
// ek bat dhyan me rkho ki linked list ke code me tum glti krne hi wale hai edge case pe
// so handle it lated

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        cout << "Node with val " << this->data << " deleted" << endl;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    }
    cout << endl;
}

// insertion at head
// 1 create a node
// 2 new node next ko head pe laga do
// 3 head ko new node ke upr lga do

void insertAtHead(Node *&head, Node *&tail, int data)
{
    // check for empty ll
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        // return;
    }
    else
    {

        // step 1
        Node *newNode = new Node(data);

        // step2
        newNode->next = head;

        // step 3
        //  if(head==NULL)
        //  {
        //      //empty list first node add hogi
        //     tail=newNode;
        //  }
        head = newNode;
    }
}

// insertion at end
// create node
// tail ke next me newnode
// tail ko newnode
void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        // return;
    }
    else
    {
        // step 1
        Node *newNode = new Node(data);
        // step1 2
        tail->next = newNode;
        // step 3
        tail = newNode;
    }

    // step1 create a node
    //  Node* newNode=new Node(data);
    // step 2 connect with tail node
    // first nide add hoine wali hai
    //  if(tail==NULL)
    //  {
    //      tail=newNode;
    //       head=newNode;
    //  }
    //  else

    // tail->next=newNode;

    // step 3
    // tail=newNode;
}

int findLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

// insertion  at position position and value basis
void insertAtPosition(Node *&head, Node *&tail, int data, int pos)
{
    if (pos == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }

    if (head == NULL) // empty linked list
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    int len = findLength(head);
    if (pos >= len)
    {
        insertAtTail(head, tail, data);
        return;
    }
    // step 1 find that position
    int i = 1;
    Node *prev = head;
    while (i < pos)
    {
        prev = prev->next;
        i++;
    }

    Node *curr = prev->next;

    // step2 create node
    Node *newNode = new Node(data);

    // step3  newNode ke next ko curr
    newNode->next = curr;
    // prev ke next ko newnode
    prev->next = newNode;
}

// Deletion in linked list

void deleteNode(int pos, Node *&head, Node *&tail)
{

    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return;
    }

    if (pos == 1)
    {
        // delete first
        // first node delete
        // head=head->next;
        // temp->next=NULL
        // delete temp
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp; // write destructor to delete node homework
        return;
    }

    int len = findLength(head);
    if (pos == len)
    {
        // delete last
        // find previous
        int i = 1;
        Node *prev = head;
        while (i < pos - 1)
        {
            prev = prev->next;
            i++;
        }

        prev->next = NULL;
        // tail=prev
        Node *temp = tail;
        tail = prev;
        // delete temp
        delete temp;
        return;
    }


    //deleting middle node
    //find prev and curr
    int i=1;
    Node* prev=head;
    while(i<pos-1)
    {
        prev=prev->next;
        i++;

    }

    Node* curr=prev->next;

    //step2
     prev->next=curr->next;

     //step3
     curr->next=NULL;

     delete curr;

}

int main()
{
    // Node* first=new Node(10);
    // Node* second=new Node(20);
    // Node* third=new Node(30);
    // Node* forth=new Node(40);
    // Node* fifth=new Node(50);

    // first->next=second;
    // second->next=third;
    // third->next=forth;
    // forth->next=fifth;

    // print(first);
    // |10|->|20|->|30|->|40|->|50|->

    // insertion in ll
    //  Node* head=new Node(10);
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 11);
    insertAtHead(head, tail, 21);
    insertAtHead(head, tail, 51);
    insertAtHead(head, tail, 101);
    insertAtHead(head, tail, 111);

    print(head);
    //|111|->|101|->|51|->|21|->|11|->|10|->

    insertAtTail(head, tail, 11);
    insertAtTail(head, tail, 11);
    insertAtTail(head, tail, 21);
    insertAtTail(head, tail, 101);
    print(head);
    //|111|->|101|->|51|->|21|->|11|->|11|->|11|->|21|->|101|->

    // insertAtPosition(head, tail, 500, 4);
    // insertAtPosition(head, tail, 600, 5);
    // insertAtPosition(head, tail, 1, 0);
    // insertAtPosition(head, tail, 2, 13);
    // print(head);

    deleteNode(1, head, tail);
    deleteNode(8, head, tail);
    //      Node with val 111 deleted
    // Node with val 101 deleted
    // |101|->|51|->|21|->|11|->|11|->|11|->|21|->

      deleteNode(4, head, tail);
      deleteNode(5, head, tail);
    print(head);
    //|101|->|51|->|21|->|11|->|21|->

    return 0;
}