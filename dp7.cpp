//16/6/2023  friday
//The  END OF DYNAMIC PROGRAMMING
//elements of programming interviews book for DSA
//dynamic programming lecture 7 
//last lecture

//1 find the length of longest increasing subsequence
//take not take ie. include and exclude pattern
//tabulation remaining
class Solution {
public:

    int solveUsingRecursion(vector<int> &nums,int curr,int prev)
    {
        //base case
        if(curr>=nums.size()){
            return 0;
        }
        //include
        int include=0;
        //agr koi bhi element include nhi hua hai to include kro and agr curr bda hai prev se to include kro
        if(prev==-1 || nums[curr]>nums[prev]){
         include=1+solveUsingRecursion(nums,curr+1,curr);
        }

        //exclude
        int exclude=0+ solveUsingRecursion(nums,curr+1,prev);

        int ans=max(include,exclude);
        return ans;
    }


     int solveUsingMem(vector<int> &nums,int curr,int prev,vector<vector<int>>&dp)
    {
        //base case
        if(curr>=nums.size()){
            return 0;
        }

        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        //include
        int include=0;
        //agr koi bhi element include nhi hua hai to include kro and agr curr bda hai prev se to include kro
        if(prev==-1 || nums[curr]>nums[prev]){
         include=1+solveUsingMem(nums,curr+1,curr,dp);
        }
        //exclude
        int exclude=0+ solveUsingMem(nums,curr+1,prev,dp);

        dp[curr][prev+1]=max(include,exclude);  //yha +1 is lia kiya qki -1 index nhi hota hai +1 krne se 0 index hoga
        return dp[curr][prev+1];
    }

     int solveUsingTab(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int> > dp(n+1, vector<int>(n+1, 0));

        for(int curr = n-1; curr>=0; curr--) {
            for(int prev = curr - 1; prev >= -1; prev--) {
                //include
                int include = 0;
                if(prev == -1 || arr[curr] > arr[prev])
                    include = 1 + dp[curr+1][curr + 1];

                //excude
                int exclude = 0 + dp[curr+1][prev + 1];

                dp[curr][prev + 1] = max(include, exclude);   
            }
        }
        return dp[0][0];
    }
    
    int solveOptimal(vector<int>& arr) {
        if(arr.size() == 0)
            return 0;
        vector<int> ans;
        ans.push_back(arr[0]);

        for(int i=1; i<arr.size(); i++) {
            if(arr[i] > ans.back()) {
                //include
                ans.push_back(arr[i]);
            }
            else {
                //overwrite
                //find index of just bada element
                int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[index] = arr[i];
            }
        }
        return ans.size();
    }


int solveUsingTabSO(vector<int>& arr) {
        int n = arr.size();
        //vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for(int curr = n-1; curr>=0; curr--) {
            for(int prev = curr - 1; prev >= -1; prev--) {
                //include
                int include = 0;
                if(prev == -1 || arr[curr] > arr[prev])
                    include = 1 + nextRow[curr + 1];

                //excude
                int exclude = 0 + nextRow[prev + 1];

                currRow[prev + 1] = max(include, exclude);   
            }
            //shift
            nextRow = currRow;
        }
        return nextRow[0];
    }


    int lengthOfLIS(vector<int>& nums) {
        
        int curr=0;  //index of current element
        //index of last e;ement that included in subsequence array that is prev
        int prev=-1;  //taki me compare kr sku bda hai ya chota 
        // int ans=solveUsingRecursion(nums,curr,prev);
        // return ans;

        int n=nums.size();
        vector<vector<int>>dp (n,vector<int>(n+1,-1));
        int ans=solveUsingMem(nums,curr,prev,dp);
        return ans;

        
    }
};







//DP with binary search
// arr[0,1,0,3,2,3] 
//agr bda hai to include krlo vrna override krdo
//n log n
//optimal solution
int solveoptimal(vector<int> &nums){
    if(nums.size()==0){
        return 0;
    }

    vector<int> ans;
    ans.push_back(arr[0]);

    for(int i=1;i<nums.size();i++){
        if(arr[i]>ans.back()){
            //include
            ans.push_back(arr[i]);
        }
        else
        {
            //ovrrride
            //find index of just bda element
            int index=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
            nums[index]=arr[i];
        }
    }

    return ans.size();
}


//homeword
//same as longest incresing subsequence
//2   354. Russian Doll Envelopes



//max height by staking cuboid leetcode
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        //sort kr diya assending order me qki question ne bola tha ki u can rearrange 
        //width length height
        //wi<=wj && hi<=hj && li<=lj

        //sort every array
        for(auto &a:cuboids){
            sort(a.begin(),a.end());  
        }

        //sort the 2D array
        sort(cuboids.begin(),cuboids.end());

        // for(int i=0;i<cuboids.size();i++){  //just for printing
        //     for(int j=0;j<cuboids.size();j++){
        //         cout<<cuboids[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        //LIS ka logic

        return 0;
    }
};

class Solution {
public:
    bool check(vector<int>& a, vector<int>& b) {
        if(b[0] <= a[0] && b[1]<=a[1] && b[2] <= a[2])
            return true;
        else
            return false;
    }
    int solveUsingTabSO(vector<vector<int>>& arr) {
        int n = arr.size();
        //vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for(int curr = n-1; curr>=0; curr--) {
            for(int prev = curr - 1; prev >= -1; prev--) {
                //include
                int include = 0;
                if(prev == -1 || check(arr[curr], arr[prev]))
                    include = arr[curr][2] + nextRow[curr + 1];

                //excude
                int exclude = 0 + nextRow[prev + 1];

                currRow[prev + 1] = max(include, exclude);   
            }
            //shift
            nextRow = currRow;
        }
        return nextRow[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {

        //sort every array
        for(auto &a: cuboids) {
            sort(a.begin(), a.end());
        }

        //sort the 2D array
        sort(cuboids.begin(), cuboids.end());

        //apply lis logic
        int ans = solveUsingTabSO(cuboids);
        return ans;
        
    }
};
