// heap lecture 4
// 27/5/2023 saturday

// problemsssssss
// 1 remove stones to minimize the total
// simple maxheap lgao  and k operations lgao
// leetcode
class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int> maxHeap;
        for (int i = 0; i < piles.size(); i++)
        {
            maxHeap.push(piles[i]);
        }

        while (k--)
        {
            int maxElem = maxHeap.top();
            maxHeap.pop();
            maxElem = maxElem - floor(maxElem / 2);
            maxHeap.push(maxElem);
        }

        int sum = 0;
        while (!maxHeap.empty())
        {
            int temp = maxHeap.top();
            maxHeap.pop();
            sum = sum + temp;
        }

        return sum;
    }
};


// 2 Reorganize String
// minimum cost to cut the ropes same pattern wala questions

class node
{
public:
    char data;
    int cnt;

    node(int d, int c)
    {
        data = d;
        cnt = c;
    }
};

class compare
{
public:
    bool operator()(node a, node b)
    {
        return a.cnt < b.cnt;
    }
};

class Solution
{
public:
    string reorganizeString(string s)
    {
        // int hash[26]={0};

        // for(int i=0;i<s.size();i++)
        // {
        //     hash[s[i]-'a']++;
        // }

        // //find most freq char
        // char max_freq_char;
        // int max_freq=INT_MIN;
        // for(int i=0;i<26;i++)
        // {
        //     if(hash[i]>max_freq)
        //     {
        //         max_freq=hash[i];
        //         max_freq_char=i+'a';
        //     }
        // }

        // int index=0;
        // while(max_freq >0 && index <s.size())
        // {
        //     s[index]=max_freq_char;
        //     max_freq--;
        //     index=index+2;
        // }

        // if(max_freq!=0)
        // {
        //     return "";
        // }

        // hash[max_freq_char-'a']=0;

        // //lets place rest of the characters
        // for(int i=0;i<26;i++)
        // {
        //     while(hash[i]>0)
        //     {
        //         index=index>=s.size() ? 1: index;
        //         s[index]=i+'a';
        //          hash[i]--;
        //         index=index+2;
        //     }
        // }

        // return s;

        // using heap
        //  create mapping
        int freq[26] = {0};

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            freq[ch - 'a']++;
        }

        priority_queue<node, vector<node>, compare> maxHeap;

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] != 0)
            {
                node temp(i + 'a', freq[i]);
                maxHeap.push(temp);
            }
        }

        string ans = "";

        while (maxHeap.size() > 1)
        {
            node first = maxHeap.top();
            maxHeap.pop();
            node second = maxHeap.top();
            maxHeap.pop();

            ans += first.data;
            ans += second.data;

            first.cnt--;
            second.cnt--;

            if (first.cnt != 0)
            {
                maxHeap.push(first);
            }

            if (second.cnt != 0)
            {
                maxHeap.push(second);
            }
        }

        if (maxHeap.size() == 1)
        {
            node temp = maxHeap.top();
            maxHeap.pop();
            if (temp.cnt == 1)
            {
                ans += temp.data;
            }
            else
            {
                return "";
            }
        }

        return ans;
    }
};

// 3 Longest Happy String
// leetcode 1405

class node
{
public:
    char data;
    int cnt;

    node(int d, int c)
    {
        data = d;
        cnt = c;
    }
};

class compare
{
public:
    bool operator()(node a, node b)
    {
        return a.cnt < b.cnt;
    }
};

class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {

        priority_queue<node, vector<node>, compare> maxHeap;

        if (a > 0)
        {
            node temp('a', a);
            maxHeap.push(temp);
        }

        if (b > 0)
        {
            node temp('b', b);
            maxHeap.push(temp);
        }

        if (c > 0)
        {
            node temp('c', c);
            maxHeap.push(temp);
        }

        string ans = "";

        while (maxHeap.size() > 1)
        {
            node first = maxHeap.top();
            maxHeap.pop();
            node second = maxHeap.top();
            maxHeap.pop();

            if (first.cnt >= 2)
            {
                ans += first.data;
                ans += first.data;
                first.cnt -= 2;
            }
            else
            {
                // ek bar hai
                ans += first.data;
                first.cnt--;
            }

            if (second.cnt >= 2 && second.cnt <= first.cnt) // change bhuloge
            {
                ans += second.data;
                ans += second.data;
                second.cnt -= 2;
            }
            else
            {
                // ek bar hai
                ans += second.data;
                second.cnt--;
            }

            if (first.cnt > 0)
            {
                maxHeap.push(first);
            }

            if (second.cnt > 0)
            {
                maxHeap.push(second);
            }
        }
        if (maxHeap.size() == 1)
        {
            node temp = maxHeap.top();
            maxHeap.pop();

            if (temp.cnt >= 2)
            {
                ans += temp.data;
                ans += temp.data;
                temp.cnt -= 2;
            }
            else
            {
                // ek bar hai
                ans += temp.data;
                temp.cnt--;
            }
        }

        return ans;
    }
};


// Maharati Question
// heap ka last question
// 4 median in  a stream

#include <iostream>
using namespace std;

int signum(int a, int b)
{
    if (a == b)
    {
        return 0;
    }

    if (a > b)
    {
        return 1;
    }

    if (a < b)
    {
        return -1;
    }
}

void callMedian(int median, priority_queue<int> &minHeap, priority_queue<int>, greater < int >> &minHeap, int elem)
{

    switch (signum(minHeap.size(), maxHeap.size()))
    {
    case 0:
        if (elem > median)
        {
            minheap.push(elem);
            median = minHeap.top();
        }
        else
        {
            // chota hai elem median se
            maxHeap.push(elem);
            median = maxHeap.top();
        }
        break;
    case 1:
        if (elem > meadian)
        {
            int minTop = minHeap.top();
            minHeap.pop();
            maxHeap.push(minTop);
            minHeap.push(elem);
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
        else
        {
            maxHeap.push(elem);
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
        break;
    case -1:
        if (elem > median)
        {
            minHeap.push(elem);
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
        else
        {
            int maxTop = maxHeap.top();
            maxHeap.pop();
            minHeap.push(maxTop);
            minHeap.push(elem);
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
        break;
    }
}

int main()
{
    int arr[6] = {5, 7, 2, 9, 3, 8};
    int n = 6;
    int median = 0;
    priority_queue<int>, greater < int >> minHeap;
    priority_queue<int> maxHeap;

    for (int i = 0; i < n; i++)
    {
        int elem = arr[i];
        median = callMedail(median, minHeap, maxHeap, elem);
        cout << "->" << median << "";
    }

    return 0;
}
