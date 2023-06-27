// 14/6/2023 wednseday
// dynamic programmimng lecture 6
//  dp on strings

// 1 LCS   longest common subsequence
// original string ka parts just comdition is ordered maintained
class Solution
{
public:
    int solveUsingRecursion(string text1, string text2, int i, int j)
    {
        if (i == text1.length())
        {
            return 0;
        }
        if (j == text2.length())
        {
            return 0;
        }
        int ans = 0;
        if (text1[i] == text2[j])
        {
            ans = 1 + solveUsingRecursion(text1, text2, i + 1, j + 1);
        }
        else
        {
            ans = 0 + max(solveUsingRecursion(text1, text2, i, j + 1), solveUsingRecursion(text1, text2, i + 1, j));
        }

        return ans;
    }

    int solveUsingMem(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
    {
        if (i == text1.length())
        {
            return 0;
        }
        if (j == text2.length())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = 0;
        if (text1[i] == text2[j])
        {
            ans = 1 + solveUsingMem(text1, text2, i + 1, j + 1, dp);
        }
        else
        {
            ans = 0 + max(solveUsingMem(text1, text2, i, j + 1, dp), solveUsingMem(text1, text2, i + 1, j, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int solveUsingTab(string a, string b)
    {
        vector<vector<int>> dp(a.length() + 100, vector<int>(b.length() + 100, 0));

        for (int i = a.length() - 1; i >= 0; i--)
        {
            for (int j = b.length() - 1; j >= 0; j--)
            {
                int ans = 0;
                if (a[i] == b[j])
                {
                    ans = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    ans = 0 + max(dp[i][j + 1], dp[i + 1][j]);
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }

    int solveUsingTabSO(string a, string b)
    {
        // vector<vector<int>> dp(a.length()+100,vector<int>(b.length()+100,0));
        vector<int> curr(b.length() + 1, 0);
        vector<int> next(b.length() + 1, 0);

        for (int i = a.length() - 1; i >= 0; i--)
        {
            for (int j = b.length() - 1; j >= 0; j--)
            {
                int ans = 0;
                if (a[i] == b[j])
                {
                    ans = 1 + next[j + 1];
                }
                else
                {
                    ans = 0 + max(curr[j + 1], next[j]);
                }
                curr[j] = ans;
            }
            // shift
            next = curr;
        }

        return next[0];
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int i = 0;
        int j = 0;
        // return solveUsingRecursion(text1,text2,i,j);

        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        //  return solveUsingMem(text1,text2,i,j,dp);

        // return solveUsingTab(text1,text2);
        return solveUsingTabSO(text1, text2);
    }
};



//2 longest palindromic subsequence
//same as above just
//first strimng go left to right 
//and second string go right to left
class Solution {
public:
//aditya varma code is better than this try once

   int solve(string a,string b)
   {
       vector<int>curr(b.length()+1,0);
       vector<int>next(b.length()+1,0);

       for(int i=a.length()-1;i>=0;i--)
       {
           for(int j=b.length()-1;j>=0;j--)
           {
               int ans=0;
               if(a[i]==b[j])
               {
                   ans=1+next[j+1];
               }
               else
               {
                   ans=max(next[j],curr[j+1]);

               }
               curr[j]=ans;
           }
           next=curr;
       }
       return next[0];
   }

    int longestPalindromeSubseq(string s) {
        string revstr=s;
        reverse(revstr.begin(),revstr.end());
        int ans=solve(s,revstr);
        return ans;

        
    }
};



//VERY IMPORTANT QUESTION
// 3   EDIT DISTANCE        
class Solution {
 public:
  int solveUsingRecursion(string &a,string &b,int i,int j){
      //base case
      if(i==a.length()){
        return b.length()-j;
      }
      if(j==b.length()){
        return a.length()-i;
      }
      int ans=0;
      if(a[i]==b[j]){
         ans= solveUsingRecursion(a,b,i+1,j+1);
      }
      else{
          //oparation peform karo
          int insert=1+solveUsingRecursion(a,b,i,j+1);
          int deleted=1+solveUsingRecursion(a,b,i+1,j);
          int replace=1+solveUsingRecursion(a,b,i+1,j+1);
          ans=min(insert,min(deleted,replace));
      }
      return ans;
  }


  int solveUsingMem(string &a,string &b,int i,int j,vector<vector<int>>&dp){
      //base case
      if(i==a.length()){
        return b.length()-j;
      }
      if(j==b.length()){
        return a.length()-i;
      }

      if(dp[i][j]!=-1){
        return dp[i][j];
      }

      int ans=0;
      if(a[i]==b[j]){
         ans= solveUsingMem(a,b,i+1,j+1,dp);
      }
      else{
          //oparation peform karo
          int insert=1+solveUsingMem(a,b,i,j+1,dp);
          int deleted=1+solveUsingMem(a,b,i+1,j,dp);
          int replace=1+solveUsingMem(a,b,i+1,j+1,dp);
          ans=min(insert,min(deleted,replace));
      }
      dp[i][j] =ans;
      return dp[i][j];
  }

  int solveUsingTab(string a,string b){
  vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1,0));

  for(int j=0;j<=b.length();j++){
    dp[a.length()][j]=b.length()-j;
  }
  for(int i=0;i<=a.length();i++){
    dp[i][b.length()]=a.length()-i;
  }

  for(int i=a.length()-1;i>=0;i--){
    for(int j=b.length()-1;j>=0;j--){
      //cooopppyy paste
      int ans=0;
      if(a[i]==b[j]){
         ans= dp[i+1][j+1];
      }
      else{
          //oparation peform karo
          int insert=1+dp[i][j+1];
          int deleted=1+dp[i+1][j];
          int replace=1+dp[i+1][j+1];
          ans=min(insert,min(deleted,replace));
      }
      dp[i][j] =ans;
     
    }
  }
  return dp[0][0];



  }

  //little bit mistake here edit
  int solveUsingTabSO(string a,string b){
  // vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1,0));
   vector<int> curr(b.length()+1,0);
   vector<int> next(b.length()+1,0);
  

  for(int j=0;j<=b.length();j++){
    next[j]=b.length()-j;
  }
  
  for(int i=a.length()-1;i>=0;i--){
    //eveery row startts here
    curr[b.length()]=a.length()-i; //yahi bhoolego tum

    for(int j=b.length()-1;j>=0;j--){
      //cooopppyy paste
      int ans=0;
      if(a[i]==b[j]){
         ans= next[j+1];
      }
      else{
          //oparation peform karo
          int insert=1+curr[j+1];
          int deleted=1+next[j];
          int replace=1+next[j+1];
          ans=min(insert,min(deleted,replace));
      }
      curr[j] =ans;
     
    }
    //shift
    next=curr;
  }
  return next[0];



  }



  int minDistance(string word1, string word2) {
   
    if(word1.length()==0){
        return word2.length();
    }

    if(word2.length()==0){
        return word1.length();
    }
    int i=0,j=0;
    // return solveUsingRecursion(word1,word2,i,j);

    vector<vector<int>> dp(word1.length(),vector<int>(word2.length(),-1));
    // return solveUsingMem(word1,word2,i,j,dp);

    // return solveUsingTab(word1,word2);
    return solveUsingTabSO(word1,word2);


  }
};          