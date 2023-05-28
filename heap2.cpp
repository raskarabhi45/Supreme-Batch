// wednesday 24/5/2023

#include <iostream>
#include <queue>
using namespace std;

// questions
// 1 kth smallest number from array
// approach 1 sort array and return arr[k-1]   TC nlog(n);

// approach 2
// min heap se O(n) space  hogi

// using max heap
// starting ke k element ka heap bnaya
// agar new element heap ke top se chota hoga tbhi insert krunga top ko htake
// max heap me k small elemnt hai
// so istime top me kth smallest element hoga

// mean heap se solve krna aana chahia
// but mean heap  q nhi lgana hai
// max heap se solve aana chahia
// max heap ka logic kaise work krta hai
// TC O(n)   SC O(k)
// 1 kth smallest element
int getKthSmallestElement(int arr[], int n, int k)
{
    // create max heap
    priority_queue<int> pq;

    // insert initial k elements
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // for remining element push only smaller elements
    for (int i = k; i < n; i++)
    {
        int elem = arr[i];
        if (elem < pq.top())
        {
            pq.pop();
            pq.push(elem);
        }
    }

    int ans = pq.top();
    return ans;
}

// 2 kth greatest element

getKthGreatestElement(int arr[], int n, int k)
{
    // create max heap
    priority_queue<int, vector<int>, greater<int>> pq;

    // insert initial k elements
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // for remining element push only greater
    for (int i = k; i < n; i++)
    {
        int elem = arr[i];
        if (elem > pq.top())
        {
            pq.pop();
            pq.push(elem);
        }
    }
    int ans = pq.top();
    return ans;
}

// homework
//  3  merge 2  max heaps
//  merge kro dono array ko that is heap ko
// fir usko build heap kro  O(m+n)

// 4 CBT is given and btao
// is this complete binary tree heap or not
// conditions for heap
// CBT  + heap property  (check kro ki parent apne child se bda hai kya bs)

pair<bool, int> solve(Node *root)
{
    // 0 node
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, INT_MIN);
        return p;
    }
    // base case  for single node
    if (root->left == NULL && root->right == NULL)
    {
        // leaf node
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = solve(root->left);
    pair<bool, int> rightAns = solve(root->right);

    // conditions
    if (leftAns.first == true &&
        rightAns.first == true &&
        root->data > leftAns.second &&
        root->data > rightAns.second)
    {
        return pair<bool, int> make_pair < true, root->data;
    }
    else
    {
        return pair<bool, int> make_pair < false, root->data;
    }
}

// 5 convert BST to max heap
// using heapify
// observation tha ki mera structure same rhega bs muze values pe dhyan dena hai

// 6 check tree is CBT or not

// 7 merge k sorted arrays
// k size ka heap bnao
//  sbhi ka first element mean heap me rkho

int main()
{
    // questions
    // 1
    int arr[] = {10, 5, 20, 4, 15};
    int n = 5;
    int k = 2;

    int ans = getKthSmallestElement(arr, n, k);
    cout << "kth element is " << ans << endl;

    // mainne max  heap create kiya hai
    //  priority_queue<int> pq;  //same as heap

    // pq.push(3);
    // pq.push(6);
    // pq.push(9);
    // pq.push(4);
    // pq.push(8);

    // cout<<"top element "<<pq.top()<<endl; 9
    // pq.pop();
    // cout<<"top element "<<pq.top()<<endl; 8
    // cout<<pq.size()<<endl;4
    // if(pq.empty())
    // {
    //     cout<<"max heap is empty"<<endl;
    // }
    // else
    // {
    //     cout<<"max heap is not empty"<<endl;
    // }

    // creation of min heap
    // container   //comparison
    // priority_queue<int,vector<int>,greater<int>> pq;
    // pq.push(3);
    // pq.push(6);
    // pq.push(9);
    // pq.push(4);
    // pq.push(8);

    // cout<<"top element "<<pq.top()<<endl;  3
    // pq.pop();

    // Questions
    // 1 kth smallest number from array
    // approach 1 sort array and return arr[k-1]   TC nlog(n);

    // approach 2
    // min heap se O(n) space  hogi

    // using max heap
    // starting ke k element ka heap bnaya
    // agar new element heap ke top se chota hoga tbhi insert krunga top ko htake
    // max heap me k small elemnt hai
    // so istime top ke kth smallest element hoga

    // mean heap se solve krna aana chahia
    // but mean heap  q nhi lgana hai
    // max heap se solve aana chahia
    // max heap ka logic kaise work krta hai

    return 0;
}