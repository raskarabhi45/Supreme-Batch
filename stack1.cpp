// stack started
// sunday 23/4/2023
// follows LIFO order last in first out order
//**************middle element

#include <iostream>
using namespace std;

class Stack
{
private:
        int *arr;
        int top;
        int size;

public:
        Stack(int size)
        {
                arr = new int[size];
                this->size = size;
                top = -1;
        }

        // functions
        void push(int data)
        {
                if (size - top > 1)
                {
                        // space available
                        // insert
                        top++;
                        arr[top] = data;
                }
                else
                {
                        // space not available
                        cout << "Stack Overflow" << endl;
                }
        }

        void pop()
        {
                if (top == -1)
                {
                        // stack is empty
                        cout << "Stack underflow, cant delete element" << endl;
                }
                else
                {
                        // stack is not empty
                        top--;
                }
        }

        int getTop()
        {
                if (top == -1)
                {
                        cout << "There is not element in Stack " << endl;
                }
                else
                {
                        return arr[top];
                }
        }

        // return number of valid elements present in stack
        int getSize()
        {
                return top + 1;
        }

        bool isEmpty()
        {
                if (top == -1)
                {
                        return true;
                }
                else
                {
                        return false;
                }
        }
};


class Stack2
{
public:
        int *arr;
        int size;
        int top1;
        int top2;

        Stack(int size)
        {
                arr = new int[size];
                this->size = size;
                top1 = -1;
                top2 = size;
        }

        // functions
        void push1(int data)
        {
                if (top2 - top1 == 1)
                {
                        // space not available
                        cout << "OVERFLOW in stack 1" << endl;
                }
                else
                {
                        // space available
                        top1++;
                        arr[top1] = data;
                }
        }

        void pop1()
        {
                if (top1 == -1)
                {
                        // stack empty
                        cout << "UNDERFLOW in stack 1" << endl;
                }
                else
                {
                        // stack not empty
                        arr[top1] = 0;
                        top1--;
                }
        }

        void push2(int data)
        {
                if (top2 - top1 == 1)
                {
                        // space not available
                        cout << "OVERFLOW in stack 2" << endl;
                }
                else
                {
                        top2--;
                        arr[top2] = data;
                }
        }


        void pop2()
        {
                if (top2 == size)
                {
                        // stack 2 is empty
                        cout << "UNDERFLOW in stack 2" << endl;
                }
                else
                {
                        // stack 2 is not empty
                        arr[top2] = 0;
                        top2++;
                }
        }

        void print()
        {
                cout << endl;
                cout << "top1: " << top1 << endl;
                cout << "top2: " << top2 << endl;
                for (int i = 0; i < size; i++)
                {
                        cout << arr[i] << " ";
                }
                cout << endl;
        }
};

int main()
{

        // CREATION
        stack<int> s; // Stack s(5);

        // insertion
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);
        // s.push(60);

        while (!s.isEmpty())
        {
                cout << s.getTop() << " ";
                s.pop();
        }
        cout << endl;

        cout << "Size of stack " << s.getSize() << endl;

        s.pop();

        string str = "babbar";

        stack<char> s;
        for (int i = 0; i < str.length(); i++)
        {
                s.push(str[i]);
        }

        while (!s.empty())
        {
                cout << s.top() << " ";
                s.pop();
        }
        cout << endl;

        return 0;
}

// problems

//  middle of LL
//  void printMiddle(stack<int> &s, int &totalSize) {
//          if(s.size() == 0 ) {
//                  cout << "There is no element in stack" << endl;
//                  return ;
//          }

//         //base case
//         if(s.size() == totalSize/2 + 1)  {
//                 cout << "Middle element is: " << s.top() << endl;
//                 return;
//         }

//         int temp = s.top();
//         s.pop();

//         //recursive call
//         printMiddle(s, totalSize);

//         //backtrack;
//         s.push(temp);

// }

// int main() {
//         stack<int> s;

//         s.push(10);
//         s.push(20);
//         s.push(30);
//         s.push(40);
//         s.push(50);
//         s.push(60);
//         s.push(70);

//         int totalSize = s.size();
//         printMiddle(s,totalSize);

//         return 0;
// }