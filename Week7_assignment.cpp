#include<iostream>
#include<vector>
using namespace std;

//1 last Occurance of charater
//approach 1 using loop from left to right and store indexes of that element
// approach 2 using loop right to left and if element finds then return index

//approach 3 using recursion Left to right
void lastOccLTR(string &s,char x,int i,int &ans)
{
    //base case
    if(i>=s.length())
    {
        return;
    }
    //solution
    if(s[i]==x)
    {
        ans=i;
    }
    lastOccLTR(s,x,i+1,ans);
}

//approach 4 using recursion right to left
void lastOccRTL(string &s,char x,int i,int &ans)
{
    //base case
    if(i<0)
    {
        return;
    }
    //solution
    if(s[i]==x)
    {
        ans=i;
        return;
    }
    lastOccRTL(s,x,i-1,ans);
}

//approach 5 using strchar() inbuilt funbction


///////2 Reverse a string recursively
void reverseString(string &str,int s,int e)
{
    if(s>=e)
    {
        return;
    }
   
        swap(str[s],str[e]);
    
    reverseString(str,s+1,e-1);

}

// 3 add strings recursively leetcode
// class Solution {
// public:

//     string addRE(string num1,int p1,string num2,int p2,int carry=0)
//     //still not get it perfectly
//     {
//         //base case
//         if(p1<0 && p2<0)
//         {
//             if(carry!=0)
//             {
//                 return string(1,carry+'0');
//             }
//             return "";
//         }


//         //ek case solve kro
//         int n1=(p1>=0 ? num1[p1]:'0')-'0';
//         int n2=(p2>=0 ? num2[p2]:'0')-'0';
//         int sum=n1+n2+carry;
//         int digit=sum%10;
//         carry=sum/10;
//         string ans="";
//         ans.push_back(digit+'0');


//         //baki recursion kr dega
//         ans=ans+addRE(num1,p1-1,num2,p2-1,carry);
//         return ans;

//     }


//     string addStrings(string num1, string num2) {

//         string ans=addRE(num1,num1.size()-1,num2,num2.size()-1);
//         reverse(ans.begin(),ans.end());
//         return ans;
        
//     }
// };

//4 check pallindrome
// void isPallindrome(string &str,int s,int e)
// {
//     if(s>=e)
//     {
//         return true;
//     }
   
//        if(str[s]!=str[e])
//        {
//         return false;
//        }
    
//     isPallindrome(str,s+1,e-1);

// }

//5 Remove all occurance of a substring
//1 find part string position
//2 remove part from string
//3 call again the function from new string



//print all subarrays using recursion
// 1 
// 1 2
// 1 2 3
// 1 2 3 4
// 1 2 3 4 5

void printSubarray_util(vector<int> &nums,int s,int e)
{
    //base case
    if(e>=nums.size())
    {
        return;
    }



    // 1 case sol
    for(int i=s;i<=e;i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;


    //RE
    printSubarray_util(nums,s,e+1);
}


void printSubarrayNums(vector<int> &nums)
{
    for(int start = 0; start <nums.size(); start++) {
        int end = start;
        printSubarray_util(nums,start,end);
    }

}

//Best time to buy and sell stock leetcode
class Solution {
public:

void maxProfitSolve(vector<int> &prices,int i,int &minPrice,int &maxProfit)
{
    //base case
    if(i==prices.size())
    {
        return;
    }


    //sol for 1 case
    if(prices[i]<minPrice)
    {
        minPrice=prices[i];
    }

    int todaysProfit=prices[i]-minPrice;
    if(todaysProfit>maxProfit)
    {
        maxProfit=todaysProfit;
    }

    //RE
    maxProfitSolve(prices,i+1,minPrice,maxProfit);
}


    int maxProfit(vector<int>& prices) {

         //approach 2 using recursion

    int minPrice=INT_MAX;
    int maxProfit=INT_MIN;
    maxProfitSolve(prices,0,minPrice,maxProfit);
    return maxProfit;
    }
}





int main()
{
    // //1 find last occurance
    // string s;
    // cin>>s;
    // char x;
    // cin>>x;
    // int i=0;

    // int ans=-1;
    // lastOccLTR(s,x,i,ans);
    // cout<<ans<<endl;
    // int j=s.size()-1;
    // lastOccRTL(s,x,j,ans);
    // cout<<ans<<endl;

    //2 reverse a string
    // string str;
    // cin>>str;
    // cout<<str<<endl;
    // int s=0,e=str.size()-1;
    // reverseString(str,s,e);
    // cout<<str<<endl;

    //subarray
    vector<int> nums{1,2,3,4,5};
    printSubarrayNums(nums);


    return 0;
}

