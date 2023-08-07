// queue 3rd lecture
//###########################################
//revise AGAIN
////#######################################
#include <iostream>
#include <queue>
using namespace std;

// 1 first non- repeating character in a string
string solve(string str)
{
    int freq[26] = {0};
    queue<char> q;

    string ans = "";

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        // increment frequency
        freq[ch - 'a']++; //aski of a=97 mapping 0 se krne le lia -'a' kr rhe hai
        // q.push
        q.push(ch);

        while (!q.empty())
        {
            if (freq[q.front() - 'a'] > 1)
            {
                q.pop(); //repeated he to pop kr diya
            }
            else
            {
                ans.push_back(q.front()); //non repeated mila to push kr diya
                break;
            }
        }
 //agr hme non repeating character nhi mila to # push kr diya
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    // cout << "Final Ans: " << ans << endl;
    return ans;
}

int main()
{
    string str = "zarcaazrd";
    cout << " Final ans is: " << solve(str) << endl;

    return 0;
}


//little bit tricky
// 2/petrol station wala problme
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {

        // kitna petrol kam padgya
        int deficit = 0;
        // kitna petrol bacha hua h
        int balance = 0;
        // circuit kaha se start krre ho
        int start = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            balance += gas[i] - cost[i];
            if (balance < 0) //petrol km pd gys
            {
                // yahi pr galti hogi
                deficit = deficit+ abs(balance);
                start = i + 1;
                balance = 0;
            }
        }

        if (balance >= deficit) //circle comple ho gya hai
        {
            return start;
        }
        else
        {
            return -1;
        }
    }
};


//yahapr wwindoiw me sbse pehla maximum number btana hai
// 3  maxSlidingWindow
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> ans;

        // first window of k size
        for (int i = 0; i < k; i++)
        {
            // chote element remove krdo,
            while (!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }
            // inserting index, so that we can checkout of window element
            dq.push_back(i);
        }

        // store answer for first window
        ans.push_back(nums[dq.front()]);

        // remaining windows ko process
        for (int i = k; i < nums.size(); i++)
        {
            // out of window element ko remove krdia
            if (!dq.empty() && i - dq.front() >= k) //same last lecture jaisa
            {
                dq.pop_front();
            }

            // ab firse current element k liyue chotte element
            // ko remove krna h
            while (!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }
            // inserting index, so tht we can checkout of window element
            dq.push_back(i);

            // current window ka answer store krna h
            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};