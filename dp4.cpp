// dynamic programming lkecture 4
// 2d array  only 1 question

#include <iostream>
using namespace std;

// 1 partition equal subset sum
// leetcode
class Solution
{
public:
    bool solveUsingRecursion(int index, vector<int> &nums, int target)
    {
        // base case
        int n = nums.size();
        if (index >= n)
        {
            return 0;
        }

        if (target < 0)
        {
            return 0;
        }
        if (target == 0)
        {
            return 1;
        }

        bool include = solveUsingRecursion(index + 1, nums, target - nums[index]);
        bool exclude = solveUsingRecursion(index + 1, nums, target);

        return (include || exclude);
    }

    // top down DP
    bool solveUsingMem(int index, vector<int> &nums, int target, vector<vector<int>> &dp)
    {
        // base case
        int n = nums.size();
        if (index >= n)
        {
            return 0;
        }

        if (target < 0)
        {
            return 0;
        }
        if (target == 0)
        {
            return 1;
        }

        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }

        bool include = solveUsingMem(index + 1, nums, target - nums[index], dp);
        bool exclude = solveUsingMem(index + 1, nums, target, dp);

        dp[index][target] = (include || exclude);
        return dp[index][target];
    }

    // bottom up DP
    bool solveUsingTabulation(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        for (int i = 0; i < nums.size(); i++)
        {
            dp[i][0] = 1;
        }

        for (int index = n - 1; index >= 0; index--)
        {
            for (int t = 1; t <= target; t++)
            {
                bool include = 0;
                if (t - nums[index] >= 0)
                    include = dp[index + 1][t - nums[index]];
                bool exclude = dp[index + 1][t];

                dp[index][t] = (include || exclude);
            }
        }

        return dp[0][target];
    }

    // with space optimization
    bool solveUsingTabulationSO(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<bool> curr(target + 1, 0);
        vector<bool> next(target + 1, 0);

        for (int i = 0; i < nums.size(); i++)
        {
            curr[0] = 1;
            next[0] = 1;
        }

        for (int index = n - 1; index >= 0; index--)
        {
            for (int t = 1; t <= target; t++)
            {
                bool include = 0;
                if (t - nums[index] >= 0)
                    include = next[t - nums[index]]; // index+1 yani next
                bool exclude = next[t];

                curr[t] = (include || exclude);
            }
            // shift
            next = curr;
        }

        return next[target];
    }

    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
        }
        // yhahi glti krunga
        if (sum & 1) // for odd no partition possible
            return false;
        int target = sum / 2;
        int index = 0;

        // bool ans=solveUsingRecursion(index,nums,target);

        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        // bool ans=solveUsingMem(index,nums,target,dp);

        // bool ans=solveUsingTabulation(nums,target);

        bool ans = solveUsingTabulationSO(nums, target);

        return ans;
    }
};

// 2nd problem
// number of dies roll with target sum
class Solution
{
public:
    int MOD = 1000000007;

    int solveUsingRecursion(int n, int k, int target)
    {
        // base case
        if (n < 0)
            return 0;
        if (n == 0 && target == 0) // diece bhi nhi hai and target bhinhi hai
            return 1;
        if (n == 0 && target != 0)
            return 0;
        if (n != 0 && target == 0)
            return 0;

        int ans = 0;
        for (int i = 1; i <= k; i++)
        {
            ans = ans + solveUsingRecursion(n - 1, k, target - i);
        }
        return ans;
    }

    int solveUsingMem(int n, int k, int target, vector<vector<int>> &dp)
    {
        // base case
        if (n < 0)
            return 0;
        if (n == 0 && target == 0) // diece bhi nhi hai and target bhinhi hai
            return 1;
        if (n == 0 && target != 0)
            return 0;
        if (n != 0 && target == 0)
            return 0;

        if (dp[n][target] != -1) // check weather ans is already present or not
            return dp[n][target];

        int ans = 0;
        for (int i = 1; i <= k; i++)
        {
            if (target - i >= 0)
                ans = (ans % MOD + solveUsingMem(n - 1, k, target - i, dp) % MOD) % MOD;
        }
        dp[n][target] = ans; // store ans in dp
        return dp[n][target];
    }

    int solveUsingTabulation(int n, int k, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        dp[0][0] = 1;

        for (int index = 1; index <= n; index++)
        {
            for (int t = 1; t <= target; t++)
            {
                int ans = 0;
                for (int i = 1; i <= k; i++)
                {
                    if (t - i >= 0)
                        ans = ((ans % MOD + dp[index - 1][t - i]) % MOD) % MOD;
                }
                dp[index][t] = ans; // store ans in dp
            }
        }
        return dp[n][target];
    }

    int solveUsingTabulationSO(int n, int k, int target)
    {
        vector<int> prev(target + 1, 0);
        vector<int> curr(target + 1, 0);

        prev[0] = 1;

        for (int index = 1; index <= n; index++)
        {
            for (int t = 1; t <= target; t++)
            {
                int ans = 0;
                for (int i = 1; i <= k; i++)
                {
                    if (t - i >= 0)
                        ans = (ans % MOD + (prev[t - i]) % MOD) % MOD;
                }
                curr[t] = ans; // store ans in dp
            }
            // shift
            prev = curr;
        }
        return prev[target];
    }

    int numRollsToTarget(int n, int k, int target)
    {

        // return solveUsingRecursion(n,k,target);

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        // return solveUsingMem(n,k,target,dp);
        // return solveUsingTabulation(n,k,target);
        return solveUsingTabulationSO(n, k, target);
    }
};

int main()
{

    return 0;
}