//Doneeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee

// Sunday 12/2/23 @12pm 
// 2d arrays    
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//linear mapping index at linear=c*i+j; c=number of columns i=row index j=col index
//n rows  index= 0 to n-1;
//m col index= 0 to m-1              

//VECTOR OF VECTOR
// vector<vector<int>> v;
//VECTOR OF VECTOR
//outer   inner datatype name
//access v[][]  same like array;

////////////////////////////////////////////////////////////////////////
//Problem Solving

//1 ROW SUM PRINT
void printRowWiseSum(int arr[][3],int row,int col)
{
    //row wise travaersal
    for(int i=0;i<row;i++)
    {
        int sum=0;
        for(int j=0;j<col;j++)
        {
            sum=sum+arr[i][j];
        }
        cout<<sum<<endl;
    }

}

//2 COLUMN WISE SUM PRINT
void printColWiseSum(int arr[][3],int row,int col)
{
    //row wise travaersal
    for(int i=0;i<row;i++)
    {
        int sum=0;
        for(int j=0;j<col;j++)
        {
            sum=sum+arr[j][i]; //only change
        }
        cout<<sum<<endl;
    }

}

//3 LINEAR SEARCH IN 2D ARRAY
bool findKey(int arr[][3],int row,int col,int key)
{
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++)
    {
        if(arr[i][j]==key)          //**                           
        {
            return true;
        }
    }
  }
  return false;
}

// 4 Max in 2D array
int getMax(int arr[][3],int row,int col)
{
    int max=INT_MIN;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(arr[i][j]>max)
            {
                max=arr[i][j];
            }
        }
        
    }
    return max;
}

// 5 min in 2D array

int getMin(int arr[][3],int row,int col)
{
    int min=INT_MAX;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(arr[i][j]<min)
            {
                min=arr[i][j];
            }
        }
        
    }
    return min;
}

//Maximum number is 9
//Minimum number is 1

// 6 TRANSPOSE OF MATRIX
void transpose(int arr[][3],int row,int col,int trans[][3])
{//for entire loop we get same matrix again
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
        trans[j][i]=arr[i][j];
        }
    }
}

void PrintArray(int arr[][3],int row,int col)
{
    for(int i=0;i<row;i++)
{
     for(int j=0;j<col;j++)
     {
        cout<<arr[i][j]<<" ";
     }
     cout<<endl;
}
}


int main()
{
    //declare 2d array
//     int arr[3][3];

//     //initization
    // int brr[3][3]={
    //     {1,2,3},
    //     {4,5,6},
    //     {7,8,9}};

// //row wise print
// cout<<"Printing row wise"<<endl;
//     for(int i=0;i<3;i++)
//     {  //for every row we need to print calue in each column
//         for(int j=0;j<3;j++)
//         {
//             cout<<brr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// cout<<endl;
// //col wise print
// cout<<"Printing column wise"<<endl;
//  for(int i=0;i<3;i++)
//     {  
//         for(int j=0;j<3;j++)
//         {
//             cout<<brr[j][i]<<" ";
//         }
//         cout<<endl;
//     }

// int arr[3][3];
// int row=3;
// int col=3;

// //input
// //row wise input
// for(int i=0;i<row;i++)
// {
//      for(int j=0;j<col;j++)
//      {
//         cin>>arr[i][j];
//      }
// }

// cout<<"Printing row wise"<<endl;
// for(int i=0;i<row;i++)
// {
//      for(int j=0;j<col;j++)
//      {
//         cout<<arr[i][j]<<" ";
//      }
//      cout<<endl;
// }


// //input
// //col wise input
// for(int i=0;i<row;i++)
// {
//      for(int j=0;j<col;j++)
//      {
//         cin>>arr[j][i];
//      }
// }

// cout<<"Printing col wise"<<endl;
// for(int i=0;i<row;i++)
// {
//      for(int j=0;j<col;j++)
//      {
//         cout<<arr[j][i]<<" ";
//      }
//      cout<<endl;
// }


////////////////////////////////////////////////////////////////////////
//Problem Solving in 2d arrays

// int arr[3][3];
// int row=3;
// int col=3;
// for(int i=0;i<row;i++)
// {
//      for(int j=0;j<col;j++)
//      {
//         cin>>arr[i][j];
//      }
// }

// cout<<"Printing row wise"<<endl;
// for(int i=0;i<row;i++)
// {
//      for(int j=0;j<col;j++)
//      {
//         cout<<arr[i][j]<<" ";
//      }
//      cout<<endl;
// }

// printRowWiseSum(arr,row,col);
// printColWiseSum(arr,row,col);
//Linaer search 
// int key=8;
// if(findKey(arr,3,3,key))       
// {
//     cout<<"true"<<endl;
// }
// else
// {
//     cout<<"false"<<endl;
// }
//  int brr[3][3]={
//         {1,2,3},
//         {4,5,6},
//         {7,8,9}};
// int row=3;
// int col=3;
// int ans=getMax(brr,row,col);
// cout<<"Maximum number is "<<ans<<endl;

// int ans1=getMin(brr,row,col);
// cout<<"Minimum number is "<<ans1<<endl;
// cout<<"Printing array"<<endl;
// PrintArray(brr,row,col);
// int trans[3][3];
// transpose(brr,row,col,trans);
// cout<<"Printing transpose array"<<endl;
// PrintArray(trans,row,col);
// Printing array
// 1 2 3
// 4 5 6
// 7 8 9
// Printing transpose array
// 1 4 7
// 2 5 8
// 3 6 9







//VECTOR
// vector<vector<int>> arr; representaion of 2d matrix

// vector<int> a{1,2,3};
// vector<int> b{1,2,3};
// vector<int> c{1,2,3};

// arr.push_back(a);
// arr.push_back(b);
// arr.push_back(c);

// for(int i=0;i<arr.size();i++)
// {
//     for(int j=0;j<arr[0].size();j++)
//     {
//       cout<<arr[i][j]<<" ";
//     }
//     cout<<endl;
// }


//VECTOR Another way representation

int row=3;
int col=5;
vector<vector<int>> arr(row,vector<int>(col,45));

for(int i=0;i<arr.size();i++)
{
    for(int j=0;j<arr[0].size();j++)
    {
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}
// 45 45 45 45 45
// 45 45 45 45 45
// 45 45 45 45 45
//ex
//vector<vector<int>> brr(5,vector<int>(5,-8))

    return 0;
}