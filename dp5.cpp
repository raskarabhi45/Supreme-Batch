//dynamic programming lecture 5


//1 Guess number higher or lower
class Solution {
public:

    int solveUsingRecursion(int start, int end) {
        if(start >= end)
            return 0;
        
        int ans = INT_MAX;
        for(int i=start; i<=end; i++) {
            ans = min(ans, i + max(solveUsingRecursion(start,i-1),solveUsingRecursion(i+1, end)));
        }
        return ans;
    }

    int solveUsingMem(int start, int end, vector<vector<int> >& dp) {
        if(start >= end)
            return 0;

        if(dp[start][end] != -1) {
            return dp[start][end];
        }
        
        int ans = INT_MAX;
        for(int i=start; i<=end; i++) {
            ans = min(ans, i + max(solveUsingMem(start,i-1, dp),solveUsingMem(i+1, end, dp)));
        }
        dp[start][end] = ans;
        return dp[start][end];
    }

    int solveUsingTab(int n) {
        vector<vector<int> > dp(n+2, vector<int>(n+2, 0));

        for(int start=n; start >= 1; start-- ) {
            for(int end = 1; end<=n; end++) {
                
                if(start>=end)
                    continue;
                else {
                    int ans = INT_MAX;
                    for(int i=start; i<=end; i++) {
                        ans = min(ans, i + max(dp[start][i-1],dp[i+1][end]));
                    }
                    dp[start][end] = ans;
                }
            }
        }
        return dp[1][n];

    }

    int getMoneyAmount(int n) {
        //int ans = solveUsingRecursion(1,n);
        // vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
        // int ans = solveUsingMem(1, n, dp);

        int ans = solveUsingTab(n);
        return ans;
    }
};









/// problem 2 leetcode
//min cost tree from leaf values
class Solution {
public:
    int solveUsingRecursion(vector<int>& arr,map< pair<int,int> , int >& maxi, int left, int right) {
        //base case
        if(left == right)
            return 0;

        int ans = INT_MAX;

        for(int i=left; i<right; i++) {
            ans = min(ans, 
            maxi[{left,i}]*maxi[{i+1, right}] 
            + solveUsingRecursion(arr, maxi, left, i)
            + solveUsingRecursion(arr, maxi, i+1, right) );
        }
        return ans;
    }

    int solveUsingMem(vector<int>& arr,map< pair<int,int> , int >& maxi, int left, int right, vector<vector<int> >& dp) {
        //base case
        if(left == right)
            return 0;

        if(dp[left][right] != -1) {
            return dp[left][right];
        }

        int ans = INT_MAX;

        for(int i=left; i<right; i++) {
            ans = min(ans, 
            maxi[{left,i}]*maxi[{i+1, right}] 
            + solveUsingMem(arr, maxi, left, i, dp)
            + solveUsingMem(arr, maxi, i+1, right, dp) );
        }
        dp[left][right] =  ans;
        return dp[left][right];
    }

    int solveUsingTab(vector<int>& arr, map< pair<int,int> , int >& maxi) {
        int n = arr.size();
        vector<vector<int> > dp(n+1, vector<int>(n+1, 0));

        for(int left = n-1; left>=0; left--) {
            for(int right=0; right<=n-1; right++) {

                if(left>=right)
                    continue;
                else {
                    //valid range
                      int ans = INT_MAX;

                    for(int i=left; i<right; i++) {
                        ans = min(ans, 
                        maxi[{left,i}]*maxi[{i+1, right}] 
                        + dp[left][i]
                        + dp[i+1][right]);
                    }
                    dp[left][right] =  ans;
                    
                }

            }
        }
    return dp[0][n-1];
    }


    int mctFromLeafValues(vector<int>& arr) {
        map< pair<int,int> , int> maxi;
        //pre-computation   
        for(int i=0;i<arr.size(); i++) {
            // pair<int,int> p;
            // p.first = i;
            // p.second=i;
            // maxi[p] = arr[i];

            maxi[{i,i}] = arr[i];
            for(int j=i+1; j<arr.size(); j++) {
                maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
            }
        }
        int n = arr.size();
        // int ans = solveUsingRecursion(arr, maxi, 0, n-1);
        // vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
        // int ans = solveUsingMem(arr, maxi, 0, n-1, dp);
        int ans = solveUsingTab(arr, maxi);
        return ans;

    }
};





