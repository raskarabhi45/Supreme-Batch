//###################################...
//Duplicate number negative marking method and third approach
//4 find missing number   didnt understood
//9 factorial of large number
//###################################...

#include<iostream>
#include<vector>
using namespace std;

// 1 Sort Colors on Leetcode
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         //Approach 1 sort method
//         // sort(nums.begin(),nums.end());
 
//             Approach 2
//         //2 counting method
//         // int ones,zeros,twos;
//         // ones=zeros=twos=0;
//         // for(int i=0;i<nums.size();i++)
//         // {
//         //     if(nums[i]==0)
//         //     {
//         //         zeros++;
//         //     }
//         //     else  if(nums[i]==1)
//         //     {
//         //         ones++;
//         //     }
//         //     else
//         //     {
//         //         twos++;
//         //     }

//         // }

//         // //spread
//         // int i=0;
//         //     while(zeros--)
//         //     {
//         //         nums[i]=0;
//         //         i++;
//         //     }

//         //     while(ones--)
//         //     {
//         //         nums[i]=1;
//         //         i++;
//         //     }

//         //     while(twos--)
//         //     {
//         //         nums[i]=2;
//         //         i++;
//         //     }

//             Approach  the best one
//             // inplace shuffle 
//             // pointer approach
//             // best Approach
//             int low=0;
//             int h=nums.size()-1,i=0;
//             while(i<=h)
//             {
//                 if(nums[i]==0)
//                 {
//                     swap(nums[low],nums[i]);
//                     low++;
//                     i++;
//                 }
//                 else if(nums[i]==1)
//                 {
//                     i++;
//                 }
//                 else
//                 {
//                     swap(nums[i],nums[h]);
//                     h--;
//                 }
//             }
//     }
// };

//very easy 
// 2 move all negavtive numbers to left side of an array
// approach one sort 
//dutch national flag
// void moveAllNegToLeft(int *arr,int n)
// {
//     //Dutch National flag Algorithm
//     int low=0,high=n-1;
//     while(low<high)
//     {
//         if(arr[low]<0)
//         {
//             low++;
//         }
//         else if(arr[high]>0)
//         {
//             high--;
//         }
//         else
//         {
//             swap(arr[low],arr[high]);
//         }
//     }

// }

//3  Find Duplicate number Leetcode
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
        // Approach No 1
    //     int n=nums.size();
    //     sort(nums.begin(),nums.end());
    //     int i,j;
    //     for(i=0;i<n-1;i++)
    //     {
    //        if(nums[i]==nums[i+1])
    //        return nums[i];
    //     }
    //    return -1;



    // Approach 2     REMEMBER++    
    //Negative marking Method
    //just simply one by one mark negative
    // int ans=-1;
    // for(int i=0;i<nums.size();i++)
    // {
    //     int index=abs(nums[i]);
    //     //already visited
    //     if(nums[index]<0)
    //     {
    //         ans=index;
    //         break;
    //     } 
    //     //visited mark
    //     nums[index]=nums[index]*(-1);          
    // }
    // return ans ;    


// Approach 3 best one
// positioning method 
//     while(nums[0]!=nums[nums[0]])
//     {
//         swap(nums[0],nums[nums[0]]);
//     }
//     return nums[0];
//     }
// };


//4 Find missing element in an array

// void findMissing(int arr[],int n)
// {
    // Approach 1 
//Visited method
// for(int i=0;i<n;i++)
// {
//     int index=abs(arr[i]);
//     if(arr[index-1]>0) //coz array index strating from zero
//     {
//         arr[index-1]*=-1; //mark visited that is -1
//     }
// }

// for(int i=0;i<n;i++)
// {
//     if(arr[i]>0)  //agr not visited mila to vhi wala number missing hai
//     cout<<i+1<<" ";
// }

// Approach 2
// //Sorting swapping method
// int i=0;
// while(i<n)
// {
//     int index=arr[i]-1;
//     if(arr[i]!=arr[index])
//     {
//         swap(arr[i],arr[index]);
//     }
//     else
//     {
//         i++;
//     }
// }
// for(int i=0;i<n;i++)
// {
//     if(arr[i]!=i+1)
//     cout<<i+1<<" ";
// }

// }

// 5 find first Repeating Element
//Remaining gfg
// User function template in C++

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        // code here
        //approach 1
        //Working Time Limit exceeded
        // int index=-1;
        // for(int i=0;i<n;i++){
        //     int val=arr[i];
        //     for(int j=i+1;j<n;j++){
        //         if(val==arr[j]){
        //           return i+1;
        //         }
        //     }
        // }
        // return index;
        
        //approach 2
       int index=-1;
       unordered_map<int,int> mp;
       
       for(int i=0;i<n;i++){
           mp[arr[i]]++;
       }
       
       for(int i=0;i<n;i++){
           if(mp[arr[i]]>1){
               return i+1;
           }
       }
       return index;
    }
};


// 6  common element in 3 sorted array...
//remaining gfg

vector<int> commonElement(int a[],int b[],int c[],int n1,int n2,int n3)
{
    vector<int> ans;
    set<int>st;// created set to store unique element
    int i,j,k;
    i=j=k=0;
    while(i<n1 && j<n2 && k<n3)
    {
        if(a[i]==b[j]  && b[j]==c[k])
        {
            // ans.push_back(a[i]);
            st.insert(a[i]);
            i++;j++;k++;
        }
        else if(a[i]<b[j])
        {
            i++;
        }
        else if(b[j]<c[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }

    for(auto i:st)
    {
        ans.push_back(i);
    }



    return ans;
}


// 7 wave print a matrix   easy oneeee

// void wavePrintMatrix(vector<vector<int>> v)
// {
// int row=v.size();
// int col=v[0].size();
// for(int startcol=0;startcol<col;startcol++)
// {
//     //even number of column print -> Top to Bottom
//     if(startcol &1==0) //even number case
//     {
//         for(int i=0;i<row;i++)
//         {
//             cout<<v[i][startcol]<<" ";
//         }
//     }
//     else
//     {
//         //odd number of column print-> Bottom to top
//         for(int i=row-1;i>=0;i--)
//         {
//             cout<<v[i][startcol]<<" ";
//         }
//     }
// }


// }

// 8 spiral print in a matrix
//leetcode
// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         vector<int> ans;
//         int row=matrix.size();
//         int col=matrix[0].size();

//         int total_elements=row*col;

//         int startingRow=0;
//         int startingCol=0;
//         int endingCol=col-1;
//         int endingRow=row-1;

//         int cnt=0;
//         while(cnt<total_elements)
//         {
//             //print startingRow
//             for(int i=startingCol;i<=endingCol && cnt<total_elements;i++)
//             {
//                 ans.push_back(matrix[startingRow][i] );
//                 cnt++;
//             }

//             startingRow++;

//              //print endingCol
//             for(int i=startingRow;i<=endingRow && cnt<total_elements;i++)
//             {
//                 ans.push_back(matrix[i][endingCol]);
//                 cnt++;
//             }
//             endingCol--;

//              //print endingRow
//             for(int i=endingCol;i>=startingCol && cnt<total_elements;i--)
//             {
//                 ans.push_back(matrix[endingRow][i]);
//                 cnt++;
    
//             }
//             endingRow--;

//              //print startingCol
//             for(int i=endingRow;i>=startingRow && cnt<total_elements;i--)
//             {
//                 ans.push_back(matrix[i][startingCol]);
//                 cnt++;
//             }
//             startingCol++;
//         }
//      return ans;
        
//     }
// };


//8 Add two numbers represented by 2 array   GFG
//same like adding  two LL
class Solution{
    public:
    string calc_Sum(int *a,int n,int *b,int m){
    // Complete the function
    string ans;
    int i=n-1;
    int j=m-1;
    int carry=0;
    
    while(i>=0 && j>=0){
        int x=a[i]+b[j]+carry;
        int digit=x%10;
        carry=x/10;
        ans.push_back(digit+'0');  //for storing in string we added '0'
        i--,j--;
    }
    
    while(i>=0){
        int x=a[i]+carry;
        int digit=x%10;
        carry=x/10;
        ans.push_back(digit+'0');
        i--;
    }
    
    while(j>=0){
        int x=b[j]+carry;
        int digit=x%10;
        carry=x/10;
        ans.push_back(digit+'0');
        j--;
    }
    
    if(carry){
        int x=carry;
        ans.push_back(x+'0');
    }
    
    while(ans[ans.size()-1]=='0'){ //qki niche hum reverse kr rhe hai to last me zero hai O aage aayenge na so pop krdo
        ans.pop_back();  
    }
    
    reverse(ans.begin(),ans.end());
    return ans;
    
    
    }
};


//################################
//9 factorial of large number  GFG
class Solution {
public:
    vector<int> factorial(int N){
        // code here
        // for big number we cant store fact in int so that here we are stoaring that in array
        vector<int> ans;
        ans.push_back(1); //initialize with 1
        int carry=0;
        for(int i=2;i<=N;i++){
            for(int j=0;j<ans.size();j++){ //main LOGIC
                int x=ans[j]*i+carry;
                ans[j]=x%10; //remainder
                carry=x/10;  //carry
            }
            while(carry){ //if carry exists
                ans.push_back(carry%10); //for bda carry
                carry=carry/10;
            }
            
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};




int main()
{
// int arr[]={1,2,-3,4,-5,6};
// //output -5 -3 2 4 1 6
// int n=sizeof(arr)/sizeof(int);

// moveAllNegToLeft(arr,n);

// for(int i=0;i<n;i++)
// {
//     cout<<arr[i]<<" ";
// }

// int n;
// int arr[]={1,3,5,3,4};
// n=5;
// findMissing(arr,n);

//7
vector<vector<int>>v{
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
};
// wavePrintMatrix(v);
// output
//9 5 1 10 6 2 11 7 3 12 8 4 wave form

    return 0;
}