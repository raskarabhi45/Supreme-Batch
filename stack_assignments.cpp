//stack assignments
//######################################/
//Remaining
//#####################################

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
            ans+=1; //ek reversal krna pdega
        }
        else
        {
            ans+=2;  //2 reversal krne pdenge
        }
    }

    return ans;

}


// 3 Next greater element in Linked list  //just go for it @Google @Microsoft @Facebook @Amazon @Netflix @Adobe

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
//agr stack 1 size of ho gya to that single person in stack might be the celebraty
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


//5 n stack in array


// 6 online stock span
class StockSpanner {
public:
   stack<pair<int,int>>st;

    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1;
        while(!st.empty()  && st.top().first<price)
        {
            span=span+st.top().second;
            st.pop();
        }

        st.push({price,span});
        return span;
        
    }
};


//6 Simply path

//7 Check if word is valid after substutions


//stillll not got ittt seems     little bit tougher
//8 decode string
class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        for(auto ch:s){
            if(ch==']'){
                string stringToRepeat="";
                while(!st.empty() && !isdigit(st.top()[0])){
                    string top=st.top();
                    stringToRepeat+=top=="["?"":top;
                    st.pop();
                }
                string numericTimes="";
                while(!st.empty() && isdigit(st.top()[0])){
                    numericTimes+=st.top();
                    st.pop();
                }
                reverse(numericTimes.begin(),numericTimes.end());
                int n=stoi(numericTimes);

                //final decoding
                string currdecode="";
                while(n--){
                    currdecode+=stringToRepeat;
                }
                st.push(currdecode);

            }else {
                string temp(1,ch);
                st.push(temp);
            }
            
        }
        string ans;
            while(!st.empty()){
                ans+=st.top();
                st.pop();
            }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

//9 max rectangle in binary matrix
// largest area in histogram prerequisite
//remaining


//10 Car fleet  ##########################
class Solution {

    class Car{
        public:
        int pos,speed;
        Car(int p,int s):pos(p),speed(s) {};
    };

    static bool myComp(Car &a,Car &b)
    {
        return a.pos < b.pos;
    }

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        for(int i=0;i<position.size();i++)
        {
            Car car(position[i],speed[i]);
            cars.push_back(car);
        }
        sort(cars.begin(),cars.end(),myComp);

        stack<float> st;
        for(auto car:cars)
        {
            float time=(target-car.pos)/((float) car.speed);

            while(!st.empty()  && time >=st.top())
            {
                st.pop();
            }
            st.push(time);
        }

        return st.size();
    }
};


//11 car fleet 2

int main()
{

    return 0;
}