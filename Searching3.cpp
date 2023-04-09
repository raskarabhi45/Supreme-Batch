#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 1 find element in nearly sorted array need to revise      
int BinarySearch(vector<int> arr,int target)
{
    int s=0;
    int e=arr.size()-1;
    int mid=s+(e-s)/2;

    while(s<=e)
    {
        if(arr[mid]==target)
        {
            return mid;
        }
        if(arr[mid-1]>=0 && arr[mid-1]==target)
        {
            return mid-1;
        }
        if(arr[mid+1] <arr.size() && arr[mid+1]==target)
        {
            return mid+1;
        }
        else if(arr[mid]>target)
        {
            e=mid-2;
        }
        else
        {
            s=mid+2;
        }
         mid=s+(e-s)/2;
    }
    return -1;
}

//POORA KHEL SEARCH SPACE KA HAI JUST STICK TO IT
//2 Divide 2 numbers using BinarySearch

int DividebyTwo(int dividend,int divisor)
{
    int s=0;
    int e=abs(dividend);
    int ans=1;
    int mid=s+(e-s)/2;

    while(s<=e)
    {
        //perfect solution
        if(abs(mid*divisor)==abs(dividend))
        {
            return mid;
        }
        //not perfect solution
        if(abs(mid*divisor)>abs(dividend))
        {
            e=mid-1;
        }
        else{
            //ans store and right
            ans=mid;
            s=mid+1;
        }

        mid=s+(e-s)/2;
    }
     // for handling negative conditions
    if((divisor<0 && dividend<0) || (divisor>0 && dividend>0))
    return ans;
    else
    {
        return -ans;
    }

}

//very important REMEMBER++++++++                          REVISE
//first approach using xor operator very easy
// 3 find odd occuring elements in array
// all elements occur even number of time except one find that number which comes odd number of times
// even odd me ans right me hoga 
// and odd even me ans left me hoga
// ans ka index always even index pe hoga thoda socho
int oddOccurance(vector<int> arr)
{
    int s=0;
    int e=arr.size()-1;
    int mid=s+(e-s)/2;

    while(s<=e)
    {
        if(s==e)
        {//single element
            return s;
        }

        // 2 cases mid-even and mid odd
        if(mid%2==0)
        {
            if(arr[mid]==arr[mid+1])
            {
                s=mid+2;
            }
            else
            {
                e=mid;
            }
        }
        else
        {
            if(arr[mid]==arr[mid-1])
            {
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
            
        }
        mid=s+(e-s)/2;
    }
    return -1;

}

//homework 
//1 find  pairs with different k in array
// 2 find k closest element in giver array
//3 expontial search
// 4 unbounded binary search
// 5 advance questions
//book allocation
// pointer partition
//aggresive cows
//eko spot


int main()
{
    // 1 find element in nearly sorted array
    // vector<int> arr{10,3,40,20,50,80,70};
    // int target=50;
    // int ans=BinarySearch(arr,target);
    // if(ans==-1)
    // {
    //     cout<<"Not found"<<endl;
    // }
    // else
    // {
    //     cout<<"found at index " <<ans;
    // }
    // //2
    // int dividend=10;
    // int divisor=4;
    // int ans=DividebyTwo(dividend,divisor);
    // cout<<"ans is "<<ans<<endl;

    //3 odd occurance

   vector<int> arr{3,3,7,7,10,11,11};
    int ans=oddOccurance(arr);
    cout<<"index is "<<ans<<endl;
    cout<<"value is "<<arr[ans]<<endl;


    return 0;
}