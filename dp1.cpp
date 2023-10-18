// Dynamic programming lecture 1
//#############################
//DOneeeeeeeeeeeeeeeeeeeeeee
//###################

// DP= recursion + memorisation
// kahavat :-> Those who forget the past are condemed to repeat it
// past ke experience se sikho
// jo chiz ek baar calcuate kr chuke ho use dubara calculate krne ki need nhi hai simple
// main tumahara code optimize , TC km kr dungi , speed increases bs use store kr lena
// DP ek tumahara dost hai jo tumhe dream company me leke jayegi for sure

// Top- Down approach  = recurion+ memorisation
// bottom up approach  = tabulation method = iterative way
// space optimization = O(1)
// ek baar jo calculate kiya hai use hum dubara calculate nhi krte

// when to apply DP
// overlapping subproblems same problam ko bar baar solve krna
// optimal substructure optimal solution of bigger problem can be calculated by optimal solution of smaller problem

// fibonacci number
//  f(n)= f(n-1)+ f(n-2);
// f(0)=0  and f(1)=1; base case
// create dp array
//  1 vector<int> dp(n+1,-1)
//  2 ans ko store kro dp me
//  3 return kro dp array ko
//  4 base case ke just baad check kro if dp[n]!=-1 //means if ans laready exists

#include <iostream>
#include <vector>
using namespace std;

// 1 fibonacii number leetcode
int recSolve(int n)
{
    // base case
    if (n == 1 || n == 0)
    {
        return n;
    }

    int ans = recSolve(n - 1) + recSolve(n - 2);
    return ans;
}

// top dowm n se 2 tk ka solution
int topDownSolve(int n, vector<int> &dp)
{
    // base case
    if (n == 1 || n == 0)
    {
        return n;
    }

    // step 3  check of ans already exists or not in the dp 
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // step 2:  replace ans in dp
    //return krne se pehle store krlo dp me
    dp[n] = topDownSolve(n - 1, dp) + topDownSolve(n - 2, dp);
    return dp[n];
}

// bottom up 2 se n tk
int bottomUpSolve(int n) // tabulation method
{
    // step 1 craete dp array
    vector<int> dp(n + 1, -1);

    // step 2  observe base case in above solution
    dp[0] = 0;
    if (n == 0)
    {
        return dp[0];
    }
    dp[1] = 1;

    // step 3  top dowm approach me n kaise travel kr rha hai uske ulta kro
    for (int i = 2; i <= n; i++)
    {
        dp[i] = d[i - 1] + dp[i - 2];//same expression
    }
    return dp[n];
}

// space optomisation
int spaceOptSolve(int n)
{
    // step 2  observe base case in above solution
    int prev2 = 0;
    if (n == 0)
    {
        return prev2;
    }
    int prev1 = 1;
    if (n == 1)
    {
        return prev1;
    }
    int curr;
    // step 3  top dowm approach me n kaise travel kr rha hai uske ulta kro
    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        // shifting
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int fib(int n)
{
    // int ans=recSolve(n);
    // return ans;

    // step 1  create dp array
    //  vector<int> dp(n+1,-1);
    //  int ans=topDownSolve(n,dp);
    //  return ans;

    return bottomUpSolve(n);
}

int main()
{

    return 0;
}
