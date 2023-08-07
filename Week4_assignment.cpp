//#####################################################
//remaining questions
//#####################################################

#include<iostream>
using namespace std;

//done
//1 K diff pairs in an array
// class Solution {
// public:
//     int findPairs(vector<int>& nums, int k) {
//         // int cnt=0;
//       //approach 1
//         // for(int i=0;i<nums.size();i++)
//         // {
//         //     for(int j=i+1;j<nums.size();j++)
//         //     {
//         //         if(abs(nums[i]-nums[j])==k)
//         //         {
//         //             cnt++;
//         //         }
//         //     }
//         // }
//         // return cnt;

//         //approach 2 
//     //     sort(nums.begin(),nums.end());
//     //     set<pair<int,int>>cnt;
//     //     int i=0,j=1;
//     //     while(j<nums.size())
//     //     {
//     //         int diff=nums[j]-nums[i];
//     //         if(diff==k)
//     //         {
//     //            cnt.insert({nums[i],nums[j]});
//     //             i++;
//     //             j++;
//     //         }
//     //         else if(diff>k)
//     //         {
//     //             i++;
//     //         }
//     //         else
//     //         {
//     //             j++;
//     //         }
//     //         if(i==j)
//     //         {
//     //             j++;    //REMEMBER++;
//     //         }
//     //     }
//     //     return cnt.size();
//     // 

//     //aproach 3 binay search
//     sort(nums.begin(),nums.end());
//     set<pair<int,int>>cnt;

//     for(int i=0;i<nums.size();i++)
//     {
//         if(bs(nums,i+1,nums[i]+k)!=-1)
//         {
//             cnt.insert({nums[i],nums[i]+k});
//         }
        
//     }
//     return cnt.size();


//     }

//     int bs(vector<int> &nums,int s,int key)
//     {
//         int end=nums.size()-1;
//         while(s<=end)
//         {
//             int mid=(s+end)/2;   

//             if(nums[mid]==key)
//             {
//                 return mid;
//             }     
//             else if(key>nums[mid])
//             {
//                 s=mid+1;
//             }
//             else
//             {
//                 end=mid-1;
//             }
//         }
//         return -1;

//     }
// };

//2 Find k closest element


//3 Exponentioan search ans unbounded Binary search


//4 Book Allocation problem


//5 painters partition problem


//6 Aggresive cows


//7 EKO SPOJ


//8 PRATA SPOJ


