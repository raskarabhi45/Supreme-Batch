// dynamming programming lecture lecture 2
//#######################################
//Almost done
//######################################
//  only 2 problems
#include <iostream>
using namespace std;

// 1  coin change problem
class Solution
{
public:
    int solveUsingRecursion(vector<int> &coins, int amount)
    {
        // base case
        if (amount == 0) // zero to without element ho jayega
        {
            return 0;
        }
        if (amount < 0) // mini ko update nhi krna chahta
        {
            return INT_MAX;
        }
        // lets solve 1 case
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int ans = solveUsingRecursion(coins, amount - coins[i]);
            if (ans != INT_MAX) // ek valid ans mila to mini ko update kro
            {
                mini = min(mini, ans + 1); // upr jate vkt yaad rkhna niche wala coin +1 krnaa
            }
        }
        return mini;
    }

    // top down approach
    int solveMem(vector<int> &coins, int amount, vector<int> &dp)
    {
        // base case
        if (amount == 0) // zero to without element ho jayega
        {
            return 0;
        }
        if (amount < 0) // mini ko update nhi krna chahta
        {
            return INT_MAX;
        }

        // ans already exists
        if (dp[amount] != -1)
        {
            return dp[amount];
        }

        // lets solve 1 case
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int ans = solveMem(coins, amount - coins[i], dp);
            if (ans != INT_MAX) // ek valid ans mila to mini ko update kro
            {
                mini = min(mini, ans + 1); // upr jate vkt yaad rkhna niche wala coin
            }
        }

        dp[amount] = mini;
        return dp[amount];
    }

//revise again
   //Tabulation method
    // bottom up approach
    int solveTab(vector<int> coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX)
            dp[0] = 0;
        // bottom hum 0 se target tk jayenge
        //bt zero already assign kiya hai upr so 1 se start kro
        for (int target = 1; target <= amount; target++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (target - coins[j] >= 0)  //
                    && dp[target - coins[j]] != INT_MAX;
                {
                    int ans = dp[target - coins[j]];
                    dp[target] = min(dp[target], 1 + ans);
                }
            }
        }

        return dp[amount];
    }

    // hr ek value ke aage check kro coins leke
    int coinChange(vector<int> &coins, int amount)
    {

        //    int ans=solveUsingRecursion(coins,amount);
        //    if(ans==INT_MAX)
        //    {
        //        return -1;
        //    }
        //    else
        //    {
        //        return ans;
        //    }

        vector<int> dp(amount + 1, -1);
        int ans = solveMem(coins, amount, dp);
        if (ans == INT_MAX)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};



// 2 house robber problem leetcode
//professional robber no 2 adjacent can be robbed
// dp[i]  ith index pe aate aate tum kitna money kma kuche ho
class Solution {
public:

   //n-> represents the index of current house
   //include exclude pattern
   int solveUsingRecursion(vector<int> &nums,int n)
   {
       if(n<0)
       {
           return 0;
       }
       if(n==0)
       {
           return nums[0];
       }
       
       //jb pehla include krte hai tb 
       int include=solveUsingRecursion(nums,n-2)+nums[n];  //include isme nums[n] inlcude kr rhe hai
       int exclude=solveUsingRecursion(nums,n-1)+0;  //exclude

       return max(include,exclude);
   }

   int solveUsingMem(vector<int> &nums,int n,vector<int> &dp)
   {
        if(n<0)
       {
           return 0;
       }
       if(n==0)
       {
           return nums[0];
       }

       if(dp[n]!=-1)
       {
           return dp[n];
       }

       int include=solveUsingMem(nums,n-2,dp)+nums[n];  //include
       int exclude=solveUsingMem(nums,n-1,dp)+0;  //exclude

       dp[n]= max(include,exclude);
       return dp[n];

   }


   int solveUsingTabulation(vector<int> & nums,int n)
   {
       vector<int> dp(n+1,0);
       dp[0]=nums[0];
       
       for(int i=1;i<n;i++)
       {
           int temp=0;
           if(i-2>=0) //check i-2 >0 or not valid index
           { 
               temp=dp[i-2];
               
           }
           int include=dp[i-2]+nums[i];  //include
           int exclude=dp[i-1]+0;  //exclude

           dp[i]= max(include,exclude);
      
       }

        return dp[n];

   }

//with space optimisation
//qki 2 pe hi depenedent hai prev1 and prev2
   int solveUsingTabulation(vector<int> & nums,int n)
   {
       prev2=0;
       prev1=nums[0];
    //    vector<int> dp(n+1,0);
    //    dp[0]=nums[0];
       int curr=0;
       
       for(int i=1;i<n;i++)
       {
           int temp=0;
           if(i-2>=0)
           { 
               temp=prev2;
               
           }
           int include=temp+nums[i];  //include
           int exclude=prev1+0;  //exclude

           curr= max(include,exclude);
           prev2=prev1;
           prev1=curr;
      
       }

        return dp[n];

   }



    int rob(vector<int>& nums) {
    //  using recursion
     int n=nums.size()-1;
    //  return solveUsingRecursion(n+1,-1);

     //using dp array
     vector<int> dp(n+1,-1);
     return solveUsingMem(nums,n,dp);
        

    }
};


int main()
{

    return 0
}
}
}
;