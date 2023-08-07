// sunday  29/4/2023
//  Queue started
//  mostly used in the graph and sliding window
//  also in Operating System
//  FIFO first in first out
//  rear always represent empty block
//  push ->  rear and pop front

#include <iostream>
#include <queue>
#include <deque>
using namespace std;
// 0 wali game me rear empty block pe hota  hai
// and -1 wali game me rear data wale block pe hota hai

class Queue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int data)
    {
        if (rear == size)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    void pop()
    {
        if (front == rear) 
        {
            cout << "Q is empty" << endl;
        }
        else
        {
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }

    int getFront()
    {
        if (front == rear)
        {
            cout << "Q is empty" << endl;
        }
        else
        {
            return arr[front];
        }
    }

    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int getSize()
    {
        return rear - front;
    }
};

// Circular queue
// front==rear==-1 at start

class CQueue
{
public:
    int size;
    int *arr;
    int front;
    int rear;

    CQueue(int size)
    {
        this -> size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data)
    {
        // queue full  //add one more condition
        if ((front == 0) && (rear == size - 1))
        {
            cout << "Q is full " << endl;
        }

        // single element case first elem
        else if (front == -1)
        {
            front = rear = 0;
            arr[rear] = data;
            // rear++;
        }

        // circular nature rear ko firse aage se lao
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = data;
        }

        // normal flow
        else
        {
            rear++;
            arr[rear] = data;
        }
    }

    void pop()
    {
        // empty check
        if (front == -1)
        {
            cout << "Q is empty" << endl;
        }

        // single element check /q empty ho gyi to front rear=-1
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }

        // cricular nature maintain sare pop krne ke baad
        else if (front == size - 1)
        {
            front = 0;
        }

        // normal flow
        else
        {
            front++;
        }
    }
};

// input restricted queue
// rear input push back pop back pop front

// output restricted queue
//

// Doubly Ended Queue  (deque  deck pronounce krte hai)
// push rear push front pop rear pop front
class Deque
{
public:
    int size;
    int *arr;
    int front;
    int rear;

    Deque(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = +1;
    }

    void pushRear(int data)
    {
        // queue full  //add one more condition
        if ((front == 0) && (rear == size - 1))
        {
            cout << "Q is full " << endl;
            return;
        }

        // single element case first elem
        else if (front == -1)
        {
            front = rear = 0;
            arr[rear] = data;
            // rear++;
        }

        // circular nature
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = data;
        }

        // normal flow
        else
        {
            rear++;
            arr[rear] = data;
        }
    }

    void pushFront(int data)
    {
        // queue full  //add one more condition
        if ((front == 0) && (rear == size - 1))
        {
            cout << "Q is full " << endl;
            return;
        }

        // single element case first elem
        else if (front == -1)
        {
            front = rear = 0;
            arr[rear] = data;
            // rear++;
        }

        // circular nature
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
            arr[rear] = data;
        }

        // normal flow
        else
        {
            front--;
            arr[rear] = data;
        }
    }

    void popFront()
    {
        // empty check
        if (front == -1)
        {
            cout << "Q is empty" << endl;
            return ;
        }

        // single element check /q empty ho gyi to front rear=-1
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        // cricular nature maintain
        else if (front == size - 1)
        {
            front = 0;
        }
        // normal flow
        else
        {
            front++;
        }
    }

    void popRear()
    {
        // empty check
        if (front == -1)
        {
            cout << "Q is empty" << endl;
        }

        // single element check /q empty ho gyi to front rear=-1
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        // cricular nature maintain
        else if (rear == 0) //q ki pop hai
        {
            rear = size - 1;
        }
        // normal flow
        else
        {
            rear--;
        }
    }
};

int main()
{
    // creation
    //  queue<int> q;

    // //insertion
    // q.push(11);
    // q.push(21);
    // q.push(51);
    // q.push(101);
    // q.push(111);

    // //size
    // cout<<q.size()<<endl;  //5

    // q.pop();
    // cout<<q.front()<<endl;  //21

    // if(q.empty())
    // {
    //     cout<<"q is empty"<<endl;
    // }
    // else
    // {
    //     cout<<"not empty"<<endl;
    // }

    Queue q(10);
    q.push(11);
    q.push(21);
    q.push(51);
    q.push(101);
    q.push(111);

    deque<int> dq;

    cout << q.getSize();
    return 0;
}