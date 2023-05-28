//heap 3
//luv nsit
//kush nsit

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//1 Merge K sorted arrays
//op
//0 1 2 3 4 5 6 7 8 9 10 11 
class info
{
    public:
    int data;
    int row;
    int col;

//is type ka data me heap me inseert krunga
    info(int val,int r,int c)
    {
        data=val;
        row=r;
        col=c;
    }


};


class compare
{
    public:
    bool operator()(info* a,info* b)
    {
        return a->data>b->data;
    }
};



vector<int> mergeKSortedArrays(int arr[][4],int k,int n)
{
    priority_queue<info*,vector<info*>,compare>minHeap;

    //hr array ka first element insert kro
    for(int i=0;i<k;i++)
    {
        info* temp=new info(arr[i][0],i,0);
        minHeap.push(temp);
    }

    vector<int> ans;

    while(!minHeap.empty())
    {
        info* temp=minHeap.top();
        int topElement=temp->data;
        int topRow=temp->row;
        int topCol= temp->col;
        minHeap.pop();

        ans.push_back(topElement);

        if(topCol+1 <n)
        {
            info* newInfo=new info(arr[topRow][topCol+1],topRow,topCol+1);

            minHeap.push(newInfo);
        }
    }

    return ans;

}

//#####################
// 2 merge K sorted Linked list
// leetcode 23 solved

class compare{
    public:
    bool operator()(ListNode* a, ListNode* b)
    {
        return a->val > b->val;
    }
};


class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare > minHeap;

        int k=lists.size();
        if(k==0)
        {
            return NULL;
        }

        //first element of every linked list ko insert krdo heap pe
        for(int i=0;i<k;i++)
        {
            if(lists[i]!=NULL)
            {
                minHeap.push(lists[i]);
            }
        }

        ListNode* head=NULL;
        ListNode* tail=NULL;

        while(!minHeap.empty())
        {
            ListNode* temp=minHeap.top();
            minHeap.pop();

            //temp cmay or may not be the first element of answer Linked list
            if(head==NULL)
            {
                //temp->first element of ans LL
                head=temp;
                tail=temp;
                if(tail->next!=NULL)
                {
                    minHeap.push(tail->next);
                }
            }
            else
            {
                //temp if not 1st elem
                tail->next=temp;
                tail=temp;
                if(tail->next!=NULL)
                {
                    minHeap.push(tail->next);
                }

            }
        }

        return head;
        
    }
};

//edit
//vimppppppppppppppppppppp
///3 Amazon me aaya hai
//k sorted LL hai aapke pas
//Smallest range in k list 
//632. Smallest Range Covering Elements from K Lists  leetcode
class node{
    public:
    int data;
    int row;
    int col;

    node(int d,int r,int c)
    {
        data=d;
        row=r;
        col=c;
    }
};

class compare{
    public:
    bool operator()(node* a,node* b)
    {
        return a->data>b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int mini=INT_MAX;
        int maxi=INT_MIN;

        priority_queue<node*,vector<node*>,compare > minHeap;
        int k=nums.size();

        for(int i=0;i<k;i++)
        {
            int elem=nums[i][0];
            int maxi=max(maxi,elem);
            int mini=min(mini,elem);
            minHeap.push(new node(elem,i,0));
        }

        int ansStart=mini;
        int ansEnd=maxi;

        while(!minHeap.empty())
        {
            node* top=minHeap.top();
            int topElem=top->data;
            int topRow=top->row;
            int topCol=top->col;
            minHeap.pop();

            //mini updated
            mini=topElem;  //range update hue hai

            //check for answer
            int currRange=maxi-mini;
            int ansRange=ansEnd-ansStart;
            if(currRange<ansRange)
            {
                ansStart=mini;
                ansEnd=maxi;
            }

            //check for new elemnt in same list
            if(topCol+1 <nums[topCol].size())
            {
                maxi=max(maxi,nums[topRow][topCol+1]);
                node* newNode=new node(nums[topRow][topCol+1],topRow,topCol+1);
                minHeap.push(newNode);
            }
            else
            {
                break;
            }
        }

        vector<int> ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);

        return ans;
    }
};

int main()
{
    int arr[][4]={{2,4,6,8},{1,3,5,7},{0,9,10,11}};
    int k=3;
    int n=4;


vector<int> ans=mergeKSortedArrays(arr,k,n);
for(auto i:ans)
{
    cout<<i<<" ";
}
cout<<endl;

    return 0;
}