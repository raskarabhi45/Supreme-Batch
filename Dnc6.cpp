//Sudoku solver 
// 26/03/2023 Sunday
#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int val,int board[][9],int curr_row,int curr_col)
{
    //row check
    for(int col=0;col<9;col++)
    {
        if(board[curr_row][col]==val)
        {
            return false;
        }

    }

    //col check
    for(int row=0;row<0;row++)
    {
       if(board[row][curr_col]==val)
       {
        return false;
       }
    }

    //3*3 box check
    for(int i=0;i<9;i++)
    {
        if(board[3*(curr_row/3)+(i/3)][3*(curr_row/3)+(i%3)]==val)
        {
            return false;
        }
    }

    return true;

}

//this function returns true or false on basis we found solution or not
bool solveSudoku(board[9][9],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            //check for empty cell
            if(board[i][j]==0)
            {
                for(int val=1;val<=9;val++)
                {
                    //check for safety
                    if(isSafe(val,board,i,j))
                    {
                        //insert
                        board[i][j]=val;
                        //baki recursion sambhal lega
                        bool aageKaSolution=solve(board,n);
                        if(aageKaSolution==true)
                        {
                            return true;
                        }
                       
                       //backtracking
                       board[i][j]=0;
                    }
                }

                 return false;
            }

        }
    }

   return true;;
}

int main()
{
    // vector<vector>> board(9,vector<int>(9,0));
    //0> represents an empty cell

   int arr[9][9]={
    //0 represent empty cell
    {4,5,0,0,0,0,0,0,0},
    {0,0,2,0,7,0,6,3,0},
    {0,0,0,0,0,0,0,2,8},
    {0,0,0,9,5,0,0,0,0},
    {8,8,6,0,0,0,2,0,0},
    {0,2,0,6,0,0,7,5,0},
    {0,0,0,0,0,0,4,7,6},
    {0,7,0,0,4,5,0,0,0},
    {8,0,8,0,0,9,0,0,0}
   };

   int n=9;

   solveSudoku(board,n);
   cout<<"Printing the solution"<<endl;

   for(int i=0;i<9;i++)
   {
    for(int j=0;j<9;j++)
    {
        cout<<board[i][j]<<" ";
    }
    cout<<endl;
   }


    return 0;
}

// class Solution {
// public:
//     bool isSafe(int row, int col, vector<vector<char>>& board, char value) {
//         int n = board.size();

//         for(int i=0; i<n; i++) {
//             //row check
//             if(board[row][i] == value)
//                 return false;
            
//             //col check
//             if(board[i][col] == value) 
//                 return false;

//             //3*3 box check
//             if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == value) 
//                 return false;
//         }

//         return true;
//     }

//     bool solve(vector<vector<char>>& board) {
//         int n = board.size();

//         for(int i=0; i<n; i++) {
//             for(int j=0; j<n; j++) {
//                 //check for empty cell
//                 if(board[i][j] == '.') {
//                     //try to fill with values ranging from 1 to 9
//                     for(char val = '1'; val<='9'; val++) {
//                         //check for safety
//                         if(isSafe(i,j, board, val)) {
//                             //insert
//                             board[i][j] = val;
//                             //recursion sambal lega
//                             bool remainingBoardSolution = solve(board);
//                             if(remainingBoardSolution == true) {
//                                 return true;
//                             }
//                             else {
//                                 //backtrack
//                                 board[i][j] = '.';
//                             }
//                         }
//                     }
//                     //if 1 se 9 tak koi bhi value se solution
//                     //nahi nikla ,current cell pr, 
//                     //that means piche kahin pr galti h , 
//                     //go back by returning false
//                 return false;
//                 }
//             }
//         }
//         //all cells filled 
//         return true;
//     }
//     void solveSudoku(vector<vector<char>>& board) {
//         solve(board);
//     }
// };

