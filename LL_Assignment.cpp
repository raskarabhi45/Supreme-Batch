#include<iostream>
using namespace std;

//Assignment solutions
//need to understand all once in detail
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
              headB=headB->next;//to B hum aage se start krrnege
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
        ListNode* mptr=ans; //merge pointer
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
//in simple way sarii linked list ko merge krna hai bs

Node* merge(Node* a,Node* b)
{
    if(a==NULL) return b;
    if(b==NULL) return a;

    Node* ans=NULL;

    if(a->data<b->data)
    {
        ans=a;
        a->bottom=merge(a->bottom,b);
    }
    else
    {
        ans=b;
        b->bottom=merge(a,b->bottom);
    }
    return ans;
}

Node* flatten(Node* root)
{
    if(root==NULL)
    {
        return NULL;
    }

    Node* mergedLL=merge(root,flatten(root->next));
    return mergedLL;

}


//6 clone Linked list with Random pointer


//7 Rotate List
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
    int getLength(ListNode* head)
    {
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            len++;
            temp=temp->next;
        }
        return len;
    }
  
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL) return NULL;

        int len=getLength(head);
        int actualRotateK=(k%len);
        if(actualRotateK==0)  return head; //jaisi hai vaisi 
        int newLastNodePos=len-actualRotateK-1;
        ListNode* newLastNode=head;
        for(int i=0;i<newLastNodePos;i++)
        {
            newLastNode=newLastNode->next;
        }

        ListNode* newHead=newLastNode->next;
        newLastNode->next=NULL;

        ListNode* it=newHead;
        while(it->next)
        {
            it=it->next;
        }
        it->next=head;
        return newHead;
    }
};


//8 Delete N nodes after M Nodes
void linkdelete(struct Node* head,int M,int N)
{
    if(head==NULL) return;
    Node* it=head;
    for(int i=0;i<M-1;i++)
    {
        //if M nodes are not available
        if(it==NULL) return;
        it=it->next;
    }

    //it->would be at Mth node
    if(it==NULL)  return;

    Node* MthNode=it;
    it=MthNode->next;
    for(int i=0;i<N;i++)
    {
        if(it==NULL) break;

        Node* temp=it->next;
        delete it;
        it=temp;
    }
    MthNode->next=it;
    linkdelete(it,M,N);
}

//9 find min/max number between critical points (LC-2058)


//10 merge nodes in between zeros
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
    ListNode* mergeNodes(ListNode* head) {
        
        if(head==NULL) return NULL;

        ListNode *slow=head,*fast=head->next,*newLastNode=NULL;
        int sum=0;

        while(fast)
        {
            if(fast->val!=0)
            {
                sum+=fast->val;
            }
            else
            {
                //jaise hi fast ki val 0 ho gyi
                //fast->val=0 2 consecutive 0 mil gye
                slow->val=sum;
                newLastNode=slow;
                slow=slow->next;
                sum=0;
            }

            fast=fast->next;
        }

        ListNode *temp=newLastNode->next;

        //just former new list
        newLastNode->next=NULL;

      //deleting old list
        while(temp)
        {
            ListNode* nxt=temp->next;
            delete temp;
            temp=nxt;
        }

        return head;
    }
};



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