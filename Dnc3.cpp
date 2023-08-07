//# 22/2//2023
//#Divide and  Conquer
//wednesday
//tooo easy 
//Doneeeeeeeeeeeeeeeeeeeeeeeee

#include<iostream>
#include<vector>
using namespace std;

// 1 Rat in maze problem

bool isSafe(int i,int j,int row,int col,int arr[3][3],vector<vector<bool>> & visisted)
{
   // 1 x and y 2d array ke andar ane chahia
   //2 array ke andr us cell pr one pda hona chahia
   //3 visited false hona chahia pehle visit nhi
   if(((i>=0 && i<=row) &&(j>=0 && j<=col) //range me hone chahia i and j
   && ( arr[i][j]==1)    // vhapr jana possible hona chahia
   && (visisted[i][j]==false)))  //visited nhi hona chahia pehle se
   {
      return true;
   }
   else
   {
      return false;
   }
}

void solveMaze(int arr[3][3],int row,int col,int i,int j,vector<vector<bool>> &visited,vector<string> &path,string output)
{
   //base case answer mil gya
   //lastme phuch gye
   if(i==row-1 && j==col-1)
   {
      //answer found
      path.push_back(output);   
      return;
   }
   //simple 4 direction me to move krna hai bs

   //DLRU
   //down i+1,j
   if(isSafe(i+1,j,row,col,arr,visited))
   {
      visited[i+1][j]=true;
      solveMaze(arr,row,col,i+1,j,visited,path,output+'D');
      //backtrack
      visited[i+1][j]=false;
   }

   //left i,j-1
   if(isSafe(i,j-1,row,col,arr,visited))
   {
      visited[i][j-1]=true;
      solveMaze(arr,row,col,i,j-1,visited,path,output+'L');
      //backtrack
      visited[i][j-1]=false;
   }


   //right i,j+1
   if(isSafe(i,j+1,row,col,arr,visited))
   {
      visited[i][j+1]=true;
      solveMaze(arr,row,col,i,j+1,visited,path,output+'R');
      //backtrack
      visited[i][j+1]=false;
   }

   //up i-1,j
   if(isSafe(i-1,j,row,col,arr,visited))
   {
      visited[i-1][j]=true;
      solveMaze(arr,row,col,i-1,j,visited,path,output+'U');
      //backtrack
      visited[i-1][j]=false;
   }

}



 int main()
 {
   int maze[3][3]={
      {1,0,0},
      {1,1,0},
      {1,1,1}};
      //op printing the results
          //  DDRR DRDR
          if(maze[0][0]==0)
          //jb starting point hi zeroo hoga
          {
            cout<<"No path exists"<<endl;
          }

   int rows=3;
   int cols=3;

   vector<vector<bool>>visited(rows,vector<bool>(cols,false));
   //src ki value ko true krdete hai
   visited[0][0]=true;

   vector<string> path ;  ///sare path store kregi
   string output="";
   solveMaze(maze,rows,cols,0,0,visited,path,output);

   cout<<"printing the results"<<endl;
   for(auto i:path)
   {
      cout<<i<<" ";
   }
   cout<<endl;

   if(path.size()==0)
   {
      cout<<"No Path exists"<<endl;
   }

    return 0;
 }