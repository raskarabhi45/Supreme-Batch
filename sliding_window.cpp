/////thursday 6/7/2023

// sliding window lecture



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        //we will store indexes in deque
        vector<int> ans;

        //process first k size window 
        for(int i=0; i<k; i++) {

            while(!dq.empty() &&  nums[dq.back()] < nums[i])
                dq.pop_back();
            //insert element
            dq.push_back(i);
        }

        //ans store karlo for 1st window
        ans.push_back(nums[dq.front()]);

        //remaining windows
        for(int i=k; i<nums.size(); i++) {
            //removal
            if(!dq.empty() && i-k >= dq.front()) 
                dq.pop_front();

            //additional
            while(!dq.empty() &&  nums[dq.back()] < nums[i])
                dq.pop_back();
            //insert element
            dq.push_back(i);

            ///ans store
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};




class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b) {
        return a.first < b.first;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int> > data;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++) {
            int val = nums[i];
            int index = i;
            data.push_back({val,index});
        }

        sort(data.begin(), data.end(), cmp);

        int start = 0;
        int end = data.size() - 1;
        while(start < end) {
            if(data[start].first + data[end].first == target) {
                ans.push_back(data[start].second);
                ans.push_back(data[end].second);
                break;
            }
            else if(data[start].first + data[end].first >  target) {
                end--;
            }
            else {
                start++;
            }
        }
        return ans;





    }
};







//minimum size subarray sum leetcode
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {   //algorithm
        //1) algo start with one size window from the extreme left
        //2) increment end pointer till you achieve the target specify in problem
        //3) once u achieve the target then try miimizing the window

        int i=0;
        int j=0;
        int sum=0;
        int len=INT_MAX;

        while(j<nums.size()){
            //include current number
            sum=sum+nums[j];
            //mere pass 1 window ka sum ready hai
            while(sum>=target){
                //minimize means left me eleme hai unko htana hai, len bhi update krlena,i/start ko aage bdhana pdega

                len=min(len,j-i+1);
                sum=sum-nums[i]; 
                i++;
            }
            j++;
        }

        if(len==INT_MAX){
            return 0;
        }
        else{
            return len;
        }
    }
};


//reviseeeeeeeeeeeeeeeeee
// smallest window in a string containing all the characters of another string
class Solution {
public:
    string minWindow(string s, string p) {
        int len1 = s.length();
        int len2 = p.length();
        int start = 0;
        int ansIndex = -1;
        int ansLen = INT_MAX;
        
        if(len1 < len2) {
            return "";
        }
        
        unordered_map<char, int> strMap;
        unordered_map<char, int> patMap;
        //to keep track of all characters of P string
        for(int i=0; i<p.length(); i++) {
            char ch = p[i];
            patMap[ch]++;
        }
        
        int count = 0;
        for(int i=0; i<s.length(); i++) {
            char ch = s[i];
            
            strMap[ch]++;
            
            //valid character -> jo character tumhare opattern me bhi ho 
            if(strMap[ch] <= patMap[ch] ) {
                count++;
            }
            
            if(count == len2) {
                
                //window is readyv
                
                //minimise the window -> freq decrement, ans update , start ko aage badhana h 
                
                while(strMap[s[start]] > patMap[s[start]] ||patMap[s[start]] == 0 ) {
                    
                    if(strMap[s[start]] > patMap[s[start]])
                        strMap[s[start]]--;
                        
                    start++;
                }
                
                //ans update
                int lengthOfWindow = i - start + 1;
                if(lengthOfWindow < ansLen ) {
                    ansLen = lengthOfWindow;
                    ansIndex = start;
                }
                
                
            }
        }
        
        if(ansIndex == -1)
            return "";
        else
            return s.substr(ansIndex, ansLen);
    }
};