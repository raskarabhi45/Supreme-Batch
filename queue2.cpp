//sunday 30th April 2023
//2nd lecture of stack 

#include <iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueue(queue<int> &q) {
        stack<int> s;

        //step 1: put all elements of q into s
        while(!q.empty() ) {
                int element = q.front();
                q.pop();

                s.push(element);
        }

        //step2: put all element from stackinto q
        while(!s.empty()) {
                int element = s.top();
                s.pop();

                q.push(element);
        }
}

void reverseQueueRecursion(queue<int> & q) {
        //Base case
        if(q.empty()) 
                return;

        //step A
        int temp = q.front();
        q.pop();

        //step B
        reverseQueueRecursion(q);

        //step C;
        q.push(temp);
}

void reverseK(queue<int> &q, int k ) {
        //StepA: queue ->k elements  -> stack

       
        stack<int> s;
        int count = 0;
        int n = q.size();

        if(k <= 0 || k > n)
                return ;

        while(!q.empty()){
                int temp = q.front();
                q.pop();
                s.push(temp);
                count++;

                if(count == k)
                        break;
        } 

        //stepB: stack -> q me qapas
        while(!s.empty()) {
                int temp = s.top();
                s.pop();
                q.push(temp);
        }

        //step C: push n-k element from q front to back 
        count = 0;
        while(!q.empty() && n-k != 0) {
                int temp = q.front();
                q.pop();
                q.push(temp);
                count++;

                if(count == n-k)
                        break;
        }

}

void interleaveQueue(queue<int> &q) {
        //Step A: separate both halves
        int n = q.size();
        if(q.empty())
                return;
        int k = n/2;
        int count = 0;
        queue<int> q2;

        while(!q.empty()) {
                int temp = q.front();
                q.pop();
                q2.push(temp);
                count++;

                if(count == k)
                        break;
        }

        //stepB: interleaving start krdo
        while(!q.empty() && !q2.empty()) {
                int first = q2.front();
                q2.pop();

                q.push(first);

                int second = q.front();
                q.pop();

                q.push(second);
        }
        //odd wala case
        if(n&1) {
               int element = q.front();
               q.pop();
               q.push(element);
        }
}

void solve(int arr[],int n, int k ) {
        deque<int> q;
        //process first window of size k 
        for(int i=0; i<k; i++) {
                if(arr[i] < 0) {
                        q.push_back(i);
                }
        }

        //remaining window ko process kro
        for(int i=k; i<n; i++) {
                //answer dedo purani wondow ka 
                if(q.empty()) {
                        cout << 0 << " ";
                }
                else {
                        cout << arr[q.front()] << " ";
                }

                //out of window elements ko remove krdo
                while((!q.empty()) && (i - q.front() >= k)) {
                        q.pop_front();
                }

                //check current element for insertion 
                if(arr[i] < 0 ) 
                        q.push_back(i);

        }

        //answer print karonfor last window
       if(q.empty()) {
                cout << 0 << " ";
        }
        else {
                cout << arr[q.front()] << " ";
        }


}


int main() {
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  q.push(6);
  q.push(7);
  q.push(8);
  q.push(9);

//   reverseQueueRecursion(q);

  //reverseK(q, 3);

  interleaveQueue(q);
  
  cout << "printing Queue after reversing recursively" << endl;
  while(!q.empty()) {
          cout << q.front() << " ";
          q.pop();
  }
  cout << endl;

    int arr[] = {12,-1,-7,8,-15,30,16,28};
  int size = 8;
  
  int k = 3;

  solve(arr,size,k);



  return 0;
}