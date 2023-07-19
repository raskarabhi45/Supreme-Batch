//Doneeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee

// Friday 17/02/2023
//Searching and sorting 1
//binary search condition :
//all elements should be in monotonic order(means either in increasing order or in descrasing order)
//time complexity O(log(n))
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//binary search
// int binarySearch(int arr[],int size,int target)
// {
//     int start=0;
//     int end=size-1;
//     int mid=start+(end-start)/2;

//     while(start<=end)
//     {
//         int element=arr[mid];     

//         if(element==target)
//         {
//             return mid;
//         }
//         else if(target<element)
//         {
//             //search in left
//             end=mid-1;
//         }
//         else
//         {
//             //search in right
//             start=mid+1;
//         }
//         mid=start+(end-start)/2;
//     }
//     return -1;
// }


// // 2 Find 1st occurance of an element
//approach 1 traverse loop from start then return whenever u will find tha target

//approach2
// int firstOccurance(vector<int> v,int target)
// {
//     int s=0;
//     int e=v.size()-1;
//     int mid= (s+e)/2;
//     int ans=-1;

//     while(s<=e)
//     {
//         if(v[mid]==target)
//         {
//             //store ans and then left bcoz small element is always in the left side
//             ans=mid;
//             e=mid-1;
//         }
//         else if(target<v[mid])
//         {
//             //left me search
//             e=mid-1;
//         }
//         else
//         {
//             //right me search krna
//             s=mid+1;

//         }
//         mid=(s+e)/2;
//     }
//     return ans;
// }




// 3 Find last occurance of an element
//approach 1 traverse loop from end then return whenever u will find tha target

//approach 2
// int lastOccurance(vector<int> v,int target)
// {
//     int s=0;
//     int e=v.size()-1;
//     int mid= s+(e-s)/2;;
//     int ans=-1;

//     while(s<=e)
//     {
//         if(v[mid]==target)
//         {
//             //store ans and then right qki hme last occurance nikalna hai bs
//             ans=mid;
//             s=mid+1;
//         }
//         else if(target<v[mid])
//         {
//             //left me search
//             e=mid-1;
//         }
//         else
//         {
//             //right me search krna
//             s=mid+1;

//         }
//         mid=s+(e-s)/2;
//     }
//     return ans;
// }

//4 Total number of occurance

//simple ans
//totalOccurance=lastOccurance-firstOccurance+1 

//homework
// 5 Smallest missing element
//try it 

// int findMissingElement(vector<int>v)
// {
//  int s=0;
//  int e=v.size()-1;
//  int mid=s+(e-s)/2;
// }


//  next kecture me solve kiye hai

// 6 Peak element in a mountain Array
// 7 find pivot using BinarySearch
// 8 sort rotated array
// find square root


int main()
{
    // int arr[]={2,3,4,5,6,7,8,15,16};
    // int size=9;
    // int target=6;

    // int indexoftarget=binarySearch(arr,size,target);

    // if(indexoftarget==-1)
    // {
    //     cout<<"Target not found"<<endl;
    // }
    // else
    // {
    //     cout<<"Target found at "<<indexoftarget<< " index"<<endl;
    // }

    // vector<int> v{1,2,3,4,5,6,7,8};
    // int arr[]={1,2,3,4,5,6,7,8};
    // int size=8;

// for vector
    // if(binary_search(v.begin(),v.end(),3))
    // {
    //     cout<<"Found"<<endl;;
    // }
    // else
    // {
    //     cout<<"Not found"<<endl;
    // }

    //for array using inbuilt 
     //              1st address , last address key
    //   if(binary_search(arr,arr+size,3))
    // {
    //     cout<<"Found"<<endl;;
    // }
    // else
    // {
    //     cout<<"Not found"<<endl;
    // }

    // vector<int> v{1,2,3,4,4,4,4,4,7,8};
    // int target=4;
    // int indexofFirstOcc=firstOccurance(v,target);
    // cout<<"Ans is "<<indexofFirstOcc<<endl;
    // int indexofLastOcc=lastOccurance(v,target);
    // cout<<"Ans is "<<indexofLastOcc<<endl;

    //using inbuilt functions
    // for first occurance and same like last occurance
    // auto ans2=lower_bound(v.begin(),v.end(),target);
    // cout<<"ans is "<<ans2-v.begin()<<endl;

     vector<int> v{1,2,3,4,6,7,8,9};
    int peak= findPeakinMountainArray(v);

    return 0;
}