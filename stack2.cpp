// 26/4/2023
// wednesday
//###################################################
//Almost Done  Sort a stack wala dekhna pdega
//###################################################

// stack 2 lecture
#include <iostream>
#include <stack>
#include <string>
using namespace std;

//////////Problem solving//////////////////////
//********************sort a stack

//  1  insert at bottom
void insertAtBottom(stack<int> &s, int target)
{
    // base case
    if (s.empty())
    {
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();

    // recursive call
    insertAtBottom(s, target);

    // Back Tracking
    s.push(topElement);
}

// reverse stack
// 101 51 21 11
// 11 21 51 101
void reverseStack(stack<int> &s)
{
    // top
    // pop
    // recursive call
    // insertatbottom
    // base case
    if (s.empty())
    {
        return;
    }

    int target = s.top();
    s.pop();

    // reverse stack
    reverseStack(s);

    // insertAtBottom target
    insertAtBottom(s, target);
}

// 3 very very important
//  valid parenthesis problem
bool isValidParenthesis(string str)
{
    stack<char> s;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];

        // opening bracket
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else // closing bracket
        {
            if (!s.empty())
            {
                char topCh = s.top();
                if (ch == ')' && topCh == '(')
                {
                    // matching bracktes
                    s.pop();
                }
                else if (ch == ']' && topCh == '[')
                {
                    // matching bracktes
                    s.pop();
                }
                else if (ch == '}' && topCh == '{')
                {
                    // matching bracktes
                    s.pop();
                }
                else
                {
                    // brackets not matching
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

// 4 sort a stack
// top bda and niche wale element chote  pop ke baad

void insertSorted(stack<int> &s, int target)
{
    // base case
    if (s.empty())
    {
        s.push(target);
        return;
    }

    if (s.top() >= target)
    {
        s.push(target);
        return;
    }

    int topElem = s.top();
    s.pop();

    insertSorted(s, target);

    // BT
    s.push(topElem);
}

void sortStack(stack<int> &s)
{
    // base case
    if (s.empty())
    {
        return;
    }

    int topElem = s.top();
    s.pop();

    sortStack(s);

    insertSorted(s, topElem);
}

// todays last question
// 5 remove redudant brackets

int main()
{
    stack<int> s;
    s.push(11);
    s.push(21);
    s.push(51);
    s.push(101);
    s.push(111);

    // while(!s.empty())
    // {
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }

    if (s.empty())
    {
        cout << "stack is empty" << endl;
    }

    int target = s.top(); /// pehle make sure kro ki stack empty nhi hai
    s.pop();

    // insertAtBottom(s,target);

    // while(!s.empty())
    // {
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }

    // 2
    //   while(!s.empty())
    //  {
    //      cout<<s.top()<<" ";
    //      s.pop();
    //  }
    //  reverseStack(s);
    //       while(!s.empty())
    //  {
    //      cout<<s.top()<<" ";
    //      s.pop();
    //  }

    // 3
    //  string str="([{}])";
    //  bool ans=isValidParenthesis(str);
    //  cout<<ans;

    // 4
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    // op 101 51 21 11
    sortStack(s);
    //       while(!s.empty())
    // {
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }

    return 0;
}