//friday
//21/04/2023
#include<iostream>
using namespace std;
///problems


class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

void print(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;
    }

}

int getLength(Node* &head)
{
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        cnt++;
    }

    return cnt;

}

//1 find middle of element of linked list
//  2 pointer approach
//tortoise approach fast and slow 
//t.c O(1)
// |10|->|20|->|30|->|40|->|50|->
// middle element is 30
Node* getMiddle(Node* &head)
{
    if(head==NULL)
    {
        cout<<"LL is empty"<<endl;
        return head;
    }

    if(head->next==NULL) //only one node
    {
        return head;
    }

    //for greater than one node
    Node* slow=head;
    Node* fast=head;
   // agr fast null hai to vo last node pr hoga
    while(slow!=NULL && fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
    }

    return slow;
}



//very very very very very important
//2 Reverse linked list in K groups
//1 case hum solve kargenge baki recursion kr dega
// |10|->|20|->|30|->|40|->|50|->|60|->
// |30|->|20|->|10|->|60|->|50|->|40|->

Node* reversekNodes(Node* &head,int k)
{
    if(head==NULL)
    {
        cout<<"LL is empty"<<endl;
    }

    int len=getLength(head);
    if(k>len)
    {
        //cout<<"enter valid value for k"<<endl;
        return head;
    }

    //it means number of nodes in LL is >=k
    //step A: reverse first k nodes of LL
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=curr->next;
    int cnt=0;

    while(cnt<k)
    {
        forward=curr->next;  //aage ki node nikalo
        curr->next=prev;
        prev=curr;
        curr=forward;
        cnt++;

    }

    //step B : ecursive call
    if(forward!=NULL)
    {
        //we still have nodes left to reverse
        Node* recursionKaAns=reversekNodes(forward,k);
       head->next= recursionKaAns;
    }

    //step c return head of modified LL
    return prev;

}


//3 check whether LL is circular or not  //homework
//bhai tum head ho



//4 
//check loop is present or node
//appraoch 1 using map key value address and true  map<Node*,bool>
//approach 2 floyd cycle detection
//slow and fast
//slow==fast loop present
//fast==null loop absent
// floyd cycle detection
//yaha pr fast and slow ka anti clockwise distance km hota ja rha hai 1 se
//to garanty se o ekbar to milegi hi   that is the logic behind it

// Loop is present or not 1  1 means loop is present
bool checkForLopp(Node* &head)
{
    if(head==NULL)
    {
        cout<<"LL is empty"<<endl;
        return false;
    }

    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL )
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }

        if(slow==fast)
        {
            return true;
        }
    }

    //fast Null hoya
    return false;
}



//5 starting point of loop find kro
//step A slow of fast ko meet kravo taki pta chle loop hai
//step B  slow ko start se shuru kro
//step C fir jaha slow and fast meet kegenge no wo starting point hoga




//6 remove loop





int main()
{
    Node* head=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(30);
    Node* fourth=new Node(40);
    Node* fifth=new Node(50);
    Node* sixth=new Node(60);
    Node* seventh=new Node(70);
    Node* eighth=new Node(80);
    Node* ninth=new Node(90);

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=seventh;
    seventh->next=eighth;
    eighth->next=ninth;
    ninth->next=fifth;

    // print(head);
    // Node* mid=getMiddle(head);               1
    // cout<<endl;
    // cout<<"middle element is "<<mid->data<<endl;

    // head=reversekNodes(head,3);                  2
    // print(head);

    cout<<"Loop is present or not "<<checkForLopp(head)<<endl;              //3


    return 0;
}