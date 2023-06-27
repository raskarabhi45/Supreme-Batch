// lecture 3 dynamic programming
// 2d dp

#include <iostream>
using namespace std;

// 1d dp
// 1 Painting Fence algorithm       (hard level problem)
// dp third lecture
#include <iostream>
#include <vector>
using namespace std;

int solveUsingRecursion(int n, int k)
{
  if (n == 1)
  {
    return k;
  }
  if (n == 2)
  {
    return (k + k * (k - 1));
  }

  int ans = (solveUsingRecursion(n - 2, k) + solveUsingRecursion(n - 1, k)) * (k - 1);
  return ans;
}

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

  if (dp[n] != -1)
    return dp[n];

  dp[n] = (solveUsingMem(n - 2, k, dp) + solveUsingMem(n - 1, k, dp)) * (k - 1);
  return dp[n];
}

int solveUsingTab(int n, int k)
{
  vector<int> dp(n + 1, 0);
  dp[1] = k;
  dp[2] = (k + k * (k - 1));

  for (int i = 3; i <= n; i++)
  {

    dp[i] = (dp[i - 2] + dp[i - 1]) * (k - 1);
  }
  return dp[n];
}

int solveSO(int n, int k)
{

  int prev2 = k;
  int prev1 = (k + k * (k - 1));

  for (int i = 3; i <= n; i++)
  {

    int curr = (prev2 + prev1) * (k - 1);

    // shhift -> yaha hi galti karunga ya karungi
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

// value sum maximum aana chahiye
// 2 nd problem   0-1 snapsack problem
// bs include  and wxclude wala pattern
#include <iostream>
#include <vector>
using namespace std;

// index = index  of last element
int solveUsingRecursion(int weight[], int value[], int index, int capacity)
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

  // include and exclude
  int include = 0;
  if (weight[index] <= capacity)
    include = value[index] + solveUsingRecursion(weight, value, index - 1, capacity - weight[index]);

  int exclude = 0 + solveUsingRecursion(weight, value, index - 1, capacity);

  int ans = max(include, exclude);
  return ans;
}

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
  vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

  for (int w = weight[0]; w <= capacity; w++)
  {
    if (weight[0] <= capacity)
    {
      dp[0][w] = value[0];
    }
    else
      dp[0][w] = 0;
  }

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

int solveUsingSO(int weight[], int value[], int n, int capacity)
{

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
    // shift
    prev = curr;
  }
  return prev[capacity];
}

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

  // vector<vector<int> > dp(n, vector<int>(capacity+1 , -1));
  // int ans = solveUsingMem(weight, value, n-1, capacity, dp);

  int ans = solveUsingSO2(weight, value, n, capacity);

  cout << "Ans: " << ans << endl;

  return 0;
}