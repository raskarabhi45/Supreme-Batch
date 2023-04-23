//saturday
//linked list session 4
//22/4/23
//pointer replacement must do in LL questions instead of data replacement

#include<iostream>
using namespace std;


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


//1 check whether LL is palindrome or not
//find middle
//new LL 

void print(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;
    }

    cout<<endl;
}


Node* reverse(Node* head)
{
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=curr->next;

    while(curr!=NULL)
    {
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }

    return prev;
}

//tc O(n)
bool checkPalindrome(Node* head)
{
    if(head==NULL)
    {
        cout<<"LL is empty"<<endl;
        return true;
    }

    if(head->next==NULL)
    {
        return true;
    }

    //for greater than one node
    //step A find middle node
    Node* slow=head;
    Node* fast=head->next;  //just for we want exact half middle not )n+1 / wala    while(fast!=NULL)
    {
        fast=fast->next;

    if(fast!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }

    }

    //slow pointer middle ko point kr rha hoga

    //step 2 reverse LL after middle
    Node* reverseLLHead=reverse(slow->next);
    //join the reverse LL to left part
    slow->next=reverseLLHead;

    //step C start comparison
    Node* temp1=head;
    Node* temp2=reverseLLHead;
    while(temp2!=NULL)
    {
        if(temp1->data!=temp2->data)
        {
            return false;
        }
        else
        {
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    return true;
}




//tc O(n)  sc(1)
//2 remove duplicates from a sorted linked list
//approach 1
//curr->data==curr->next->data
//equal nhi hai to aage bdo
//equal hai to curr->next  ko curr->next->next pe dalo simple
// |10|->|20|->|20|->|40|->|40|->
// |10|->|20|->|40|->
void removeDuplicatesLL(Node* &head)
{
    if(head==NULL && head->next==NULL)
    {
        cout<<"No duplicates"<<endl;
        return;
    }

    //more than one node
    Node* curr=head;
    while(curr!=NULL)
    {
        if((curr->next!=NULL) && (curr->data==curr->next->data))
        {
            Node* temp=curr->next;
           curr->next=curr->next->next;   //this importaant
           //delete node
           temp->next=NULL;
           delete temp;
           
           delete temp;
        }
        else
        {
            curr=curr->next;
        }
    }
}


//3  remove duplicates from unsorted LL Homework
//using map  stored in map 
//sort ll and check



//4 bohot jyada pyara question very very very important
//sort 0 , 1 , and 2
// //approach 1 count 0,1,2 and add one by one in linked list t.c O(n)  s.c O(1)
// |2|->|2|->|0|->|1|->|1|->
// |0|->|1|->|1|->|2|->|2|->
//tc O(n)  sc(1)
void sortZeroOneTwo(Node* &head)
{
    int zero=0;
    int one=0;
    int two=0;

    Node* temp=head;
    while(temp!=NULL)
    {
        //step 1 find cnt of 0,1,2
        if(temp->data==0)
        {
            zero++;
        }
        else if(temp->data==1)
        {
            one++;
        }
        else if(temp->data==2)
        {
            two++;
        }
        temp=temp->next;
    }

    //step 2 fill 0,1,2 in original ll
    temp=head;
    while(temp!=NULL)
    {
        //fill zeros
        while(zero--)
        {
            temp->data=0;
            temp=temp->next;
        }

        //fill ones
          while(one--)
        {
            temp->data=1;
            temp=temp->next;
        }
        //fill twos
        while(two--)
        {
            temp->data=2;
            temp=temp->next;
        }
    }
}

//approach 2  pyari approach

// // zerokahead onekahead twokahead
// |2|->|2|->|0|->|1|->|1|->
// |0|->|1|->|1|->|2|->|2|->
Node* sort2(Node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return NULL;
    }
    //create dummy node
    Node* zeroHead=new Node(-1);
    Node* zeroTail=zeroHead;

    Node* oneHead=new Node(-1);
    Node* oneTail=oneHead;

    Node* twoHead=new Node(-1);
    Node* twoTail=twoHead;

    //traverse original LL
    Node* curr=head;
    while(curr!=NULL)
    {
        if(curr->data==0)
        {
            Node* temp=curr;  //zero wali node deparate ki
            curr=curr->next;
            temp->next=NULL;

            //append 0 node in zeroHead LL
            zeroTail->next=temp;
            zeroTail=temp;

        }
        else if(curr->data==1)
        {
             Node* temp=curr;  //zero wali node deparate ki
            curr=curr->next;
            temp->next=NULL;

            //append 0 node in zeroHead LL
            oneTail->next=temp;
            oneTail=temp;
            
        }
        else if(curr->data==2)
        {
            Node* temp=curr;  //zero wali node deparate ki
            curr=curr->next;
            temp->next=NULL;

            //append 0 node in zeroHead LL
            twoTail->next=temp;
            twoTail=temp;
            
        }
    }

    //ab yha pr 0,1,2 tino LL ready hai
    //now join them
    //remove dummy nodes

    //modify one wali list
    Node* temp=oneHead;
    oneHead=oneHead->next;
    temp->next=NULL;
    delete temp;

    //modify 2 wali list
    temp=twoHead;
    twoHead=twoHead->next;
    temp->next=NULL;
    delete temp;

    //join list
    if(oneHead!=NULL)
    {
        //one wali list is non empty
        zeroTail->next=oneHead;
        if(twoHead!=NULL)
        {
            oneTail->next=twoHead;
        }
    }
    else
    {
        //one wali list empty
        if(twoHead!=NULL)
        {
            zeroTail->next=twoHead;
        }
    }

    //remove zerohead dummy node
    temp=zeroHead;
    zeroHead=zeroHead->next;
    temp->next=NULL;
    delete temp;
    

    //return head of modified ll
    return zeroHead;
}

//5 add two numbers represented by linked list
//steps
//1 reverse both linked list
//1 add both of them
//      |2|->|4|->
// |2|->|3|->|4|->
// |2|->|5|->|8|->  sum
//tc O(n)  sc(1)
Node* solve(Node* &head1,Node* head2)
{
    if(head1==NULL)
    {
        return head2;
    }

if(head2==NULL)
    {
        return head1;
    }

    //1 reverse both ll
    head1=reverse(head1);
    head2=reverse(head2);

    //2 add both ll
    Node* ansHead=NULL;
    Node* ansTail=NULL;
    int carry=0;

    while(head1!=NULL && head2!=NULL)
    {
        //calculate sum
        int sum = carry + head1->data + head2->data;
        int digit=sum%10;  //find digit to crceate node
        carry = sum/10;  //calculate carry

        //created new node digit
        Node* newNode=new Node(digit);
        if(ansHead==NULL)  //attach newnode to wnaswr wali ll
        {
            //1st node insert
            ansHead=newNode;
            ansTail=newNode;
        }
        else
        {
            ansTail->next=newNode;
            ansTail=newNode;
        }

        head1=head1->next;
        head2=head2->next;
    }

    while(head1!=NULL)  //jb head1 bada hoga 
    {
        int sum=carry+head1->data;
        int digit=sum%10;
        carry=sum/10;

        Node* newNode=new Node(digit);
        ansTail->next=newNode;
        ansTail=newNode;
        head1=head1->next;

    }

     while(head2!=NULL)
    {
        int sum=carry+head2->data;
        int digit=sum%10;
        carry=sum/10;

        Node* newNode=new Node(digit);
        ansTail->next=newNode;
        ansTail=newNode;
        head2=head2->next;

    }

    //handle carry alg se
    while(carry!=0)
    {
        int sum=carry;
        int digit=sum%10;
        carry=sum/10;

        Node* newNode=new Node(digit);
        ansTail->next=newNode;
        ansTail=newNode;
    
    }

    //3 reverse ans wali ll
    ansHead=reverse(ansHead);
    return ansHead;
}


///6 merge two sorted lindked list


int main()
{

    Node* head=new Node(2);
    Node* second=new Node(2);
    Node* third=new Node(0);
    Node* fourth=new Node(1);
    Node* fifth=new Node(1);
  

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=NULL;

  //1
    // bool isPalindrome=checkPalindrome(head);

    // if(isPalindrome)
    // {
    //     cout<<"LL is Palindrome"<<endl;
    // }
    // else
    // {
    //     cout<<"Not palindrome"<<endl;
    // }

    //2remove duplicates
    // print(head);
    // removeDuplicatesLL(head);
    // print(head);

    //4 so
    // sortZeroOneTwo(head);
    // print(head);

//    head= sort2(head);
//     print(head);

    Node* head1=new Node(2);
    Node* second1=new Node(4);
    head1->next=second1;

    
    Node* head2=new Node(2);
    Node* second2=new Node(3);
    Node* third2=new Node(4);
    head2->next=second2;
    second2->next=third2;
  print(head1);
  print(head2);
    Node* ans=solve(head1,head2);
    print(ans);



    

    return 0;
} 
