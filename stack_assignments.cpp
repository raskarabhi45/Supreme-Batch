//stack assignments
#include<iostream>
using namespace std;

// 1 remove all adjacent duplicates strings
class Solution {
public:
    string removeDuplicates(string s) {
        
        // approach 1  using string
        string ans="";
        int i=0;
        while(i<s.length())
        {
        if(ans.length()>0 && ans[ans.length()-1]==s[i])
            {
                ans.pop_back();
            }
             else
            {
                ans.push_back(s[i]);
            }
            i++;
         }
              return ans;
        }

        //approach 2 using stack
        stack<char> st;

        for(auto ch:s)
        {
            if(!st.empty() && st.top()==ch)
            {
                //pair up
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }

        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;

      
    }
};


// 2 Minimum bracket reversal
//reversal ke baad na string ko balanca bnana
int countRev(string s)
{
    //if odd sized string then impossible to make pairs
    if(s.size() &1)
    {
        return -1;
    }

    stack<char> st;
    for(char ch:s)
    {
        if(ch=='{')
        {
            st.push(ch);
        }
        else
        {
            if(!st.empty() && st.top()=='{')
            {
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }

    //if stack is still non empty lets count reversal

    while(!st.empty())
    {
        char a=st.top();
        st.pop();
        char b=st.top();
        st.pop();

        if(a==b)
        {
            ans+=1;
        }
        else
        {
            ans+=2;
        }
    }

    return ans;

}


// 3 Next greater element in Linked list
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ll;
        while(head)
        {
            ll.push_back(head->val);
            head=head->next;
        }

        stack<int>st;
        vector<int>ans(ll.size()); //init 0 here automically of vector of llinked list array initialized with 0 

        for(int i=0;i<ll.size();i++)
        {
            while(!st.empty()  && ll[i]>ll[st.top()])
            {
                //means ith element is the next greater of the element index present in stack
                int kids=st.top();
                st.pop();
                ans[kids]=ll[i];
            }
            st.push(i);
        }
        return ans;
    }
};


// 4 Celebraty problem gfg
//put all elements in stack
// jb tk stack ka size 1 nhi hota tb tk 2 2 person nikalenege 
//kya a b ko janta hai
//celebraty kisko nhi janta and sb celebraty ko jante hai
//ahr stack 1 size of ho gya to that single person in stack might be the celebraty
//lets verify it
int celebraty(vector<vector<int>> &M,int n)
{
    stack<int> st;

    //step1 push all persons in stack
    for(int i=0;i<n;i++)
    {
        st.push(i);
    }

    //step2 find aisa element ki jo celebraty ho skta hai
    //discard method to get might be celevraty
    while(st.size()!=1)
    {
        int a=st.top();
        st.pop();
        int b=st.top();
        st.pop();

        //if a knows b
        if(M[a][b])
        {
            //a is not celcebraty
            st.push(b);
        }
        else
        {
            //b is not celebraty
            st.push(a);
        }
    }
    // step 1
    // check that single person is actually celebrity
    int mightBeCelebraty=st.top();
    st.pop();

    //celebrary should not know anyone
    //row 0 honi chahia
    for(int i=0;i<n;i++)
    {
        if(M[mightBeCelebraty][i]!=0)
        {
            return -1;
        }
    }

    //everybody should know the celebraty
    for(int i=;i<n;i++)
    {
        if(M[i][mightBeCelebraty]!==0 && i!=mightBeCelebraty)
        {
            return -1;
        }
    }

    //then mightBeCelebraty is the celebraty
    return mightBeCelebraty;


}

int main()
{

    return 0;
}