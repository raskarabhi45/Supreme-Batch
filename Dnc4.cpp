//divide and conquer 4
//n queen problem
//output
// 0 0 1 0 
// 1 0 0 0
// 0 0 0 1
// 0 1 0 0

// 0 1 0 0
// 0 0 0 1
// 1 0 0 0
// 0 0 1 0

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