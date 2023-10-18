//Doneeeeeeeeeeeeeeeeeeeeeeeeeeeee

//saturday 11/02/2023
//Recursion 2
#include<iostream>
#include<vector>
#include<string.h>
#include<limits.h>
#include<algorithm>
using namespace std;


//1 climbing stairs
//n stair pe pohchne ke kitne ways hai
// Enter the value of n
// 5
// Answer is : 8
int climbStairs(int  n)  // you can make 1 or 2 moves only not different than this
{
    //base case
    if(n==0 || n==1)
    {
        return 1;
    }
    int ans=climbStairs(n-1)+climbStairs(n-2);
    return ans;
}


// 2 print array using recursion
void printArray(int arr[],int n,int i)
{
    // base case
    if(i>=n)
    {
        return ;
    }
    //ek case solve krdala
    cout<<arr[i]<<" ";
    //baki recursion sambha dega
    printArray(arr,n,i +1);
}

//without passing index 
void printArray(int arr[],int n)
{
    //base case
    if(n==0)
    {
        return ;
    }
    //ek case solve krdala
    cout<<arr[0]<<" ";
    //baki recursion sambha dega
    printArray(arr+1,n-1);
}


//3 to find max element in array
void findMax(int arr[],int n,int i,int &maxi)
{
    //base case
    if(i>=n)
    {
        //array khtm ho gya
        return;
    }
    // 1 case solve krna hai
    //current element ko check kro max hai ya nhi
    if(arr[i]>maxi)
    {
        maxi=arr[i];
    }
    //baki recursion sambhal lega
    findMax(arr,n,i+1,maxi);
}

//4 to find minimum element in array
void findMin(int arr[],int n,int i,int &mini)
{
    //base case
    if(i>=n)
    {
        //array khtm ho gya
        return;
    }
    // 1 case solve krna hai
    //current element ko check kro max hai ya nhi
    mini=min(mini,arr[i]);
    // if(arr[i]<mini)
    // {
    //     mini=arr[i];
    // }
    //baki recursion sambhal lega
    findMin(arr,n,i+1,mini);
}

//5 traverse string  
//here we are checking
//we can also return index of the particular 
bool checkKey(string &str,int i,char &key)
{
    if(i>=str.length())
    return false;

    if(str[i]==key)
    {
        return true;
    }

    //baki recursion dekhega
    return checkKey(str,i+1,key);
}

//check once again
void checkKey(string &str,int i,char &key,vector<int>&v)
{
    if(i>=str.length())
    return ;

    if(str[i]==key)
    {
        v.push_back(str[i]);
    }

    //baki recursion dekhega
    checkKey(str,i+1,key,v);
}

//6 input 647 op 6 4 7
//print digits from number
//using loops
// void digits(int no)
// {
//     int digit;
//     while(no>0)
//     {
//         digit=no%10;
//         cout<<digit<<" ";
//         no=no/10;
//     }
// }
// using recursion  
void digits(int no)
{
    //base case working my code
    // if(no>0)
    // {
    //     int digit=no%10;
    //     cout<<digit<<" ";
    //     digits(no/10);
    // }

   //base case
    if(no==0)
    {
        return;
    }
   //ek case solve
    int digit=no%10;  
    cout<<digit<<" ";

    //baki recursion sambhal lega
    digits(no/10);
}




int main()
{
    //1
    // int n;
    // cout<<"Enter the value of n"<<endl;
    // cin>>n;

    // int ans=climbStairs(n);
    // cout<<"Answer is : "<<ans<<endl;

     //2
    // int arr[5]={11,21,51,101,111};
    // int n=5;
    // int i=0;
    // printArray(arr,n,i);
    // printArray(arr,n);

    //3
    //  int arr[]={11,21,51,101,111,44,77,33};
    //  int n=8;
    //  int maxi=INT_MIN;
    //  int i=0;
    //  findMax(arr,n,i,maxi);

    //  cout<<"maximum number is "<<maxi<<endl;

    //  //4
    //  int mini=INT_MAX;
    //  int j=0;
    //  findMin(arr,n,j,mini);
    //  cout<<"minimum number is "<<mini<<endl;
    //  maximum number is 111
    //  minimum number is 11

    //5 
    // string str="abhishekRaskar";
    // char key='R';
    // int i=0;
    // vector<int>ans;
    // // int ans=checkKey(str,i,key,ans);
    // // cout<<"answer is "<<ans<<endl;
    // checkKey(str,i,key,ans);
    // cout<<"printing ans"<<endl;
    // for(auto i:ans)
    // {
    //     cout<<ans[i]<<" ";
    // }


    int no=1234;
    digits(no);



    return 0;
}