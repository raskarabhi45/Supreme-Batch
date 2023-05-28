//queue assignment
#include<iostream>
using namespace std;


//queue FIFI  stack LIFO
//1 Queue using stacks
//s1->s2 push
//add x to s1
//s2 to s1 push

class MyQueue {
public:
stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int pop=-1;
        if(!s2.empty())
        {
            pop=s2.top();
        }
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }

            pop=s2.top();
        }
        s2.pop();
        return pop;
        
    }
    
    int peek() {
        int front=-1;
        if(!s2.empty())
        {
            front=s2.top();
        }
        else
       {
           while(!s1.empty())
           {
               s2.push(s1.top());
               s1.pop();
           }
           front=s2.top();

       }
       return front;

    }
    
    bool empty() {

        return s1.empty() && s2.empty();
        
    }
};



//2 stack using queue
//push x
//push x to queue 2
//q1 -> q2
//q2->q1

//pop
//q1.front() will give you top() of stack
//top()
//

//method2 uising only one queue
//push kro in q
//loop size-1
//q.pop()  and q.push()  //reverse krna chahte hai queue

class MyStack {
public:
queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;i++)
        {
            int front=q.front();
            q.pop();
            q.push(front);
            //iske bad jo last in kiya hai vo q ke front me chla jata hai
        }
    }
    
    int pop() {
        int top=q.front();
        q.pop();
        return top;
    }
    
    int top() {

        return q.front();
        
    }
    
    bool empty() {
        return q.empty();
    }
};



//3 k- queues in an array
//similar as N stacks in an array


int main()
{

    return 0;
}