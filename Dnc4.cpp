//divide and conquer 4
//n queen problem  8 type of movememnts
//n queen such that no queen can attack each other
//output
// 0 0 1 0 
// 1 0 0 0
// 0 0 0 1
// 0 1 0 0

// 0 1 0 0
// 0 0 0 1
// 1 0 0 0
// 0 0 1 0

//for this there isnno solution for 2*2 and 3*3 board
// input n*n matrix and n queen
//map insertion or retrivel O(1)  time me ho jata hai

#include<iostream>
#include<vector>
using namespace std;

void printSolution(vector<vector<int>> &board,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
     cout<<endl;

}
//hme sirf 3 direction me check krna haoi
// upper left diagonal
// left row
// bottom left diagonal

bool isSafe(int row,int col,vector<vector<int>> &board,int n)
{
    //check krna chahte hai ki kya mai current cell [row][col] pr queen rkh skta hoo ya nhi
   
    int i=row;
    int j=col;

    //check now
    while(j>=0)
    {
        if(board[i][j]==1)
        {
            return false;
        }
        j--;
    }

    //check upper left diagonal
    i=row;
    j=col;
    while(i>=0 && j>=0)
    {
        if(board[i][j]==1)
        {
            return false;
        }
        i--;
        j--;
    }

    //check bottom left diagonal
    i=row;
    j=col;
    while(i<n && j>=0)
    {
        if(board[i][j]==1) //queen dikh gyi
        {
            return false;
        }
        i++;
        j--;
    }


    return true;
}

void solve(vector<vector<int>> &board,int col,int n)
{
    //base case
    if(col>=n)
    {
        printSolution(board,n);
        return;
    }

    //ek case solve krna hai baki recursion sambhal lega
    for(int row=0;row<n;row++)
    {
        if(isSafe(row,col,board,n))
        {
            //safe hai to queen rakhdo
            board[row][col]=1;  //queen at the cell

            //recurion solution
            solve(board,col+1,n);

            //backtracking
            board[row][col]=0;   // empty cell

        }
    }
}

int main()
{
    int n=4;
    vector<vector<int>> board(n,vector<int>(n,0));
    int col=0;
    solve(board,col,n);

    return 0;
}


//using unordered map 
// leetcode solution
class Solution {
public:

    unordered_map<int,bool> rowCheck;
    unordered_map<int,bool> upperLeftDiagnolCheck;
    unordered_map<int,bool> bottomLeftDiagnolCheck;

    void storeSolution(vector<vector<char>> &board, int n, vector<vector<string> > &ans) {
        vector<string> temp;
        for(int i=0; i<n; i++) {
            string output = "";
            for(int j=0; j<n ;j++) {
                output.push_back(board[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }


    bool isSafe(int row, int col, vector<vector<char>> &board, int n) {

        if(rowCheck[row] == true )
            return false;
            
        if(upperLeftDiagnolCheck[n-1+col-row] == true)
            return false;
            
        if(bottomLeftDiagnolCheck[row+col] == true)
            return false;

        return true;  
}


    void solve(vector<vector<char>> &board, int col, int n, vector<vector<string> > &ans  ) {
    //base case
    if(col >= n) {
        storeSolution(board, n, ans);
        return ;
    }

    //1 case solve karna h , baaki recursion sambhal lega

    for(int row = 0; row <n; row++) {
        if(isSafe(row, col, board, n)) {
        //rakh do
        board[row][col] = 'Q';
        rowCheck[row] = true;
        upperLeftDiagnolCheck[n-1+col-row] = true;
        bottomLeftDiagnolCheck[row+col] = true;
            
        //recursion solution laega
        solve(board, col+1, n, ans);
        //backtracking
        board[row][col] = '.';
        rowCheck[row] = false;
        upperLeftDiagnolCheck[n-1+col-row] = false;
        bottomLeftDiagnolCheck[row+col] = false;
        }

    }
}


        vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n,'.'));
        vector<vector<string> > ans;
        int col = 0;
        //0 -> empty cell
        //1 -> Queen at the cell
        solve(board, col, n, ans);
        return ans;
    }
};