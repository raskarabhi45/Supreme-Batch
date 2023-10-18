// lecture 3 dynamic programming
// 2d dp
//###################################
//##################################

#include <iostream>
using namespace std;

// 1d dp
// 1 Painting Fence algorithm       (hard level problem)
// dp third lecture
// same color  3 baar nhi daal skte
// 2 se jyada same color pas nhi hone chahia
// like no RRR no BBB no GGG 2 bar chlenge painj krna
#include <iostream>
#include <vector>
using namespace std;

//exponential complexity
int solveUsingRecursion(int n, int k)  //n yani fences and  k yani colors
{
  if (n == 1)  //yani ek hi fence hai to R/G/B kr  skte to ans k yani 3 aayega
  {
    return k;
  }
  if (n == 2)
  {
    return (k + k * (k - 1));   //just make table find out this formula
  }

  //baki ke lia recursion call 
  int ans = (solveUsingRecursion(n - 2, k) + solveUsingRecursion(n - 1, k)) * (k - 1);
  return ans;
}

//Memorisation
int solveUsingMem(int n, int k, vector<int> &dp)
{
  if (n == 1)
  {
    return k;
  }
  if (n == 2)
  {
    return (k + k * (k - 1));
  }

  if (dp[n] != -1)    //kya ans pehle se present hai
    return dp[n];

 //ans store krdo dp me
  dp[n] = (solveUsingMem(n - 2, k, dp) + solveUsingMem(n - 1, k, dp)) * (k - 1);
  return dp[n];
}


//Tabulation method
int solveUsingTab(int n, int k)
{
  vector<int> dp(n + 1, 0);
  //upr wala base case dekho
  dp[1] = k;
  dp[2] = (k + k * (k - 1));

//bottom up approach  upr wwala n se 1 tk ja rha tha
//to ye 3 se n tk jayega qki 1 and 2 wala
  for (int i = 3; i <= n; i++)
  {
 //n ke upr i traverse kr  rha hai
    dp[i] = (dp[i - 2] + dp[i - 1]) * (k - 1);
  }
  return dp[n];
}


//with the space optimization
//qki dp[i]   dp[i-1] and dp[i-2] pe depend kr rha hai
int solveSO(int n, int k)
{

  int prev2 = k;
  int prev1 = (k + k * (k - 1));

  for (int i = 3; i <= n; i++)
  {

    int curr = (prev2 + prev1) * (k - 1);
    // shhift -> yaha hi galti karunga 
    prev2 = prev1;
    prev1 = curr;
  }
  return prev1;
}

int main()
{

  int n = 4;
  int k = 3;

  // int ans = solveUsingRecursion(n, k);

  // vector<int> dp(n+1, -1);
  // int ans = solveUsingMem(n, k,dp);

  int ans = solveSO(n, k);
  cout << "ans: " << ans << endl;

  return 0;
}



//very important question
// from here 2d DP 
 //o-1 snapsack problem
// value sum maximum aana chahiye
// 2 nd problem   0-1 snapsack problem
// bs include  and wxclude wala pattern
//weight array and value array
#include <iostream>
#include <vector>
using namespace std;

// index = index  of last element
int solveUsingRecursion(int weight[], int value[], int index, int capacity)
{
  // base case -> only 1 item
  if (index == 0)  //agr ek hi item hai
  {
    if (weight[0] <= capacity)
    {
      return value[0];
    }
    else
      return 0;
  }

  // include and exclude
  int include = 0;
  //agr weight  chota hai capacity se tohi inlcude krunga
  if (weight[index] <= capacity)  //include krna hai  //index p[iche ja rha hai //capacity km ho rhi hogi
    include = value[index] + solveUsingRecursion(weight, value, index - 1, capacity - weight[index]);


//agr eclud ekiya to capcacity utni hi rhegi bs index piche jayega
  int exclude = 0 + solveUsingRecursion(weight, value, index - 1, capacity);

  int ans = max(include, exclude);
  return ans;
}


//2 state change ho rhi hai capacity and  index so 2d dp bneggi
//dp[index][capacity]
int solveUsingMem(int weight[], int value[], int index, int capacity, vector<vector<int>> &dp)
{
  // base case -> only 1 item
  if (index == 0)
  {
    if (weight[0] <= capacity)
    {
      return value[0];
    }
    else
      return 0;
  }

  if (dp[index][capacity] != -1)
    return dp[index][capacity];

  // include and exclude
  int include = 0;
  if (weight[index] <= capacity)
    include = value[index] + solveUsingMem(weight, value, index - 1, capacity - weight[index], dp);

  int exclude = 0 + solveUsingMem(weight, value, index - 1, capacity, dp);

  dp[index][capacity] = max(include, exclude);
  return dp[index][capacity];
}

int solveUsingTabulation(int weight[], int value[], int n, int capacity)
{
  //create dp array
  vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

//base case dekho uske hisanb se changes kro
  for (int w = weight[0]; w <= capacity; w++) //zeroth row me add kr diya
  { 
    if (weight[0] <= capacity)
    {
      dp[0][w] = value[0];  
    }
    else
      dp[0][w] = 0;
  }


//step 3 val kaha se kaha tk ja rhe hai
// i=index , j=capcacity 
//dp[i][j] here yani
//ith index tk ki item ke lia ja capcacity ke sath maximum val kya nikal skti hai
  for (int index = 1; index < n; index++)
  {
    for (int wt = 0; wt <= capacity; wt++)
    {
      // include and exclude
      int include = 0;
      if (weight[index] <= wt)
        include = value[index] + dp[index - 1][wt - weight[index]];

      int exclude = 0 + dp[index - 1][wt];

      dp[index][wt] = max(include, exclude);
    }
  }
  return dp[n - 1][capacity];
}


//Optimisation
//qki dp include and exclude pe depend krta hai
// dp[index][wt]  dp[index-1][wt]  and  dp[index-1][wt-weight[index]];
int solveUsingSO(int weight[], int value[], int n, int capacity)
{
//just create 2 1d arrays
  vector<int> prev(capacity + 1, 0);
  vector<int> curr(capacity + 1, 0);

  for (int w = weight[0]; w <= capacity; w++)
  {
    if (weight[0] <= capacity)
    {
      prev[w] = value[0];
    }
    else
      prev[w] = 0;
  }

  for (int index = 1; index < n; index++)
  {
    for (int wt = 0; wt <= capacity; wt++)
    {
      // include and exclude
      int include = 0;
      if (weight[index] <= wt)
        include = value[index] + prev[wt - weight[index]];

      int exclude = 0 + prev[wt];

      curr[wt] = max(include, exclude);
    }
    // shift very important#############################
    prev = curr;
  }
  return prev[capacity];
}

//more space optimisation
//just prev ko hatado and curr krdo uski jgha and shift ki jrrort nhi bs
//and loop me just capcacity se 0 te jao
int solveUsingSO2(int weight[], int value[], int n, int capacity)
{

  vector<int> curr(capacity + 1, 0);

  for (int w = weight[0]; w <= capacity; w++)
  {
    if (weight[0] <= capacity)
    {
      curr[w] = value[0];
    }
    else
      curr[w] = 0;
  }

  for (int index = 1; index < n; index++)
  {
    for (int wt = capacity; wt >= 0; wt--)
    {
      // include and exclude
      int include = 0;
      if (weight[index] <= wt)
        include = value[index] + curr[wt - weight[index]];

      int exclude = 0 + curr[wt];

      curr[wt] = max(include, exclude);
    }
  }
  return curr[capacity];
}

int main()
{

  int weight[] = {4, 5, 1};
  int value[] = {1, 2, 3};
  int n = 3;
  int capacity = 4;

  // int ans = solveUsingRecursion(weight, value, n-1, capacity);
                //n rows capcacity +1 columns
  // vector<vector<int> > dp(n, vector<int>(capacity+1 , -1));
  // int ans = solveUsingMem(weight, value, n-1, capacity, dp);

  int ans = solveUsingSO2(weight, value, n, capacity);

  cout << "Ans: " << ans << endl;

  return 0;
}