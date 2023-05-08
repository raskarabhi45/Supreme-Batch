#include<iostream>
using namespace std;

////////Assignment solutions

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

//1 Kth node from the end
//  4     3        2     1      0
// |11 |->|21 |->|31 |->|41 |->|51 |->
// 31 is answer as 2th node from end
void solve(Node* &head,int &k,int &ans)
{
    if(head==NULL)
    {
        return ;
    }

    solve(head->next,k,ans);
    if(k==0)
    {
        ans=head->data;
    }
    k--;
}


int getNode(Node* &head,int k)
{
    int ans=-1;
    solve(head,k,ans);
    return ans;
}


void print(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<" |->";
        temp=temp->next;
    }
    cout<<endl;
}


//2 intersection of two Linked List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a=headA;
        ListNode* b=headB;

        while(a->next && b->next)
        {
            if(a==b)
            {
                return a;
            }
            a=a->next;
            b=b->next;
        }
        if(a->next==0)
        {
            // B LL is longer and equal
            //we need to find how much bigger it is
            int blen=0;
            while(b->next)
            {
                blen++;
                b=b->next;
            }
            while(blen--)
            {
              headB=headB->next;
            }
        }
        else
        {
            // A LL is longer
            //we need to find how much bigger it is
            int alen=0;
            while(a->next)
            {
                alen++;
                a=a->next;
            }
            while(alen--)
            {
              headA=headA->next;
            }
        }
        while(headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }
        return headA; 
    }
};



//3 Merge two sorted LL
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {

        if(left==NULL) return right;
        if(right==NULL) return left;

        ListNode* ans=new ListNode(-1);
        ListNode* mptr=ans;
        while(left && right)
        {
            if(left->val<=right->val)
            {
                mptr->next=left;
                mptr=left;
                left=left->next;    
            }
            else
            {
                mptr->next=right;
                mptr=right;
                right=right->next;
            }
        }
        if(left)
        {
            mptr->next=left;
        }

        if(right)
        {
            mptr->next=right;
        }
        return ans->next;    
    }
};

//4 sort list using merge sort
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  
    ListNode* merge(ListNode* left, ListNode* right) {

        if(left==NULL) return right;
        if(right==NULL) return left;

        ListNode* ans=new ListNode(-1);
        ListNode* mptr=ans;
        while(left && right)
        {
            if(left->val<=right->val)
            {
                mptr->next=left;
                mptr=left;
                left=left->next;    
            }
            else
            {
                mptr->next=right;
                mptr=right;
                right=right->next;
            }
        }
        if(left)
        {
            mptr->next=left;
        }

        if(right)
        {
            mptr->next=right;
        }
        return ans->next;    
    }

    ListNode* findMid(ListNode* &head)
    {
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;

    }

    ListNode* sortList(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        //break LL into two halves using mid node
        ListNode* mid=findMid(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;

        //re
        left=sortList(left);
        right=sortList(right);

        //merge both left and right LL
        ListNode* mergeLL=merge(left,right);
        return mergeLL;
    }
};


// 5 flatten linked list



int main()
{
    Node* first=new Node(11);
    Node* second=new Node(21);
    Node* third=new Node(31);
    Node* fourth=new Node(41);
    Node* fifth=new Node(51);

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=NULL;

    print(first);

    int ans=getNode(first,2);
    cout<<ans;

    //print(first);

    return 0;
}