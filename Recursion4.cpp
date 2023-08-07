// ############################################
//important questions almost done
// #######################################################

//Level Recursion level4
//15/03/2023
//wednesday
#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

//try later best questions
//wildcard pattern matching
//chicken and bulldozer question

//easyyy
//1 Coin change problem
//infinite supply of coins
//find out the minimum coins that matches the target
int solve(vector<int> &arr,int target)
{
    //base case   0 bnabe ke lia kitne element lgege
    if(target==0)  //zero to without element ho jayega
    {
        return 0;
    }
    if(target<0)
    {
        return INT_MAX; //mini ko update nhi krna chahta REMEMBER++
    }

    //lets solve 1 case
    //hr ek element ke lia array  me jitne bhi element hai unki call ja rhi hai to    travere kro
    int mini=INT_MAX;
    for(int i=0;i<arr.size();i++)
    {
        int ans=solve(arr,target-arr[i]); //target ko km ktre jana hai bs
        if(ans!=INT_MAX)  //qki o ans ki range se bahr nikl skta hai
        {
        mini=min(mini,ans+1); //qki hme target create krna hai  upr target -arr[i] kr rhe hai to yha +1
        }
    }
    return mini;
   
}

//easy
//2 cut into segments rod problem
//find maximum number of segments u can make  out of x,y,x lenghts
//maximum kitne kr skte
//exponentional time complexity
int solve2(int n,int x,int y,int z)
{
    //base case
    if(n==0) //jb rod ki length 0 ho gyi to rook gye
    {
        return 0; //agr rod ki len 0 hai to simply 0 seg hi cut ho payenge na
    }

    if(n<0) //rod ki len negative 
    {
        return INT_MIN;
    }

    //
    int ans1=solve2(n-x,x,y,z)+1;//n me se x wala piece kat liya
    int ans2=solve2(n-y,x,y,z)+1; //n me se y wala piece kat liya
    int ans3=solve2(n-z,x,y,z)+1; //n me se z wala piece kat liya
    

    int ans=max(ans1,max(ans2,ans3));                                                                                                               
    return ans;
}


//3 maximum sum of non adjacent element
//inclusion exclusion problem same as house robber problem
//example
//int arr[]={2,1,4,9}
//op    11
void solve3(vector<int>& arr,int i,int sum,int &maxi)
{
    //base case
    if(i>=arr.size())
    {
        //update maxi
        maxi=max(sum,maxi);
        return;
    }

    //include
    solve3(arr,i+2,sum+arr[i],maxi);                                                                

    //exclude
    solve3(arr,i+1,sum,maxi);
    
}




int main()
{
    //q1
    // vector<int>arr{1,2};
    // int target=5;
    // int ans=solve(arr,target);

    // cout<<"Answer is "<<ans<<endl;

  //q2
    // int n=7;
    // int x=5;
    // int y=2;
    // int z=2;
    // int ans=solve2(n,x,y,z);
    // if(ans<0)
    // {
    //     ans=0;
    // }
    // cout<<"Answer is "<<ans<<endl;

    //q3 
    vector<int>arr{2,1,4,9};
    //op 11 that is 2+9
    int sum=0;
    int maxi=INT_MIN;

    int i=0;
    solve3(arr,i,sum,maxi);
    cout<<maxi<<endl;

    


    return 0;
}