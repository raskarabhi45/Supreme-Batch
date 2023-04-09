//homework Divide and conquer and     backtracking
//[8,4,2,1] ye array sorted array se kitna soor hai
//output 6 
//means me kitne swap kru ki muze ye array sort mile
#include<iostream>
#include<vector>
using namespace std;


//1 Count inversiona
//approach 1
 int reversePairs(vector<int>& nums) {
        
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]>nums[j])
                {
                    cnt++;
                }
                else
                {
                    cnt=cnt;
                }
            }
        }

        return cnt;
    }

//approach 2 best using merge sort
long merge(vector<int>&arr,vector<int> &temp,int mid,int s,int e)
{
    int i=s,k=s,j=mid+1;
    long cnt=0;

    while(i<=mid && j<=e)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }
        else  //arr[i]>arr[j] inversion count case
        {  
            temp[k++]=arr[j++];
            cnt=cnt+mid-i+1; //
        }

    }

    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }

     while(j<=e)
    {
        temp[k++]=arr[j++];
    }

    while(s<=e)
    {
        arr[s]=temp[s];
        ++s;
    }

    return cnt;


}


long mergesort(vector<int> &arr,vector<int>&temp,int s,int e)
{
    if(s>=e)
    {
        return 0;
    }
    long cnt=0;

    int mid=s+(e-s)/2;

    cnt+=mergesort(arr,temp,s,mid);
    cnt+= mergesort(arr,temp,mid+1,e);
    cnt+=merge(arr,temp,s,mid,e);

    return cnt;
}

long countInversions(vector<int> arr)
{
    long cnt=0;  //inversion counts
    vector<int> temp(arr.size(),0);
    cnt=cnt+mergesort(arr,temp,0,arr.size()-1);

    // for(int i=0;i<arr.size();i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    return cnt;

}







//2 inplace merge sort
// approach 1 using swap and partition wala trika
//approach 2 
//gap method
//gap=ceil((n+m)/2)  //ceil=2.5=3   
//gap=(total_size/2)+(total_size%2)

void mergeInplace(vector<int>&v,int s,int mid,int e)
{
    int total_len=e-s+1;
    int gap=(total_len/2)+(total_len%2);   //ceil

    while(gap>0)
    {
        int i=s, int j=s+gap;

        while(j<=end)
        {
            if(v[i]>v[j])
            {
                swap(v[i],v[j]);
            }
            i++;
            j++;
        }

        gap=gap<=1?0:(gap/2)+(gap%2)  //update gap
    }

}

mergesort(vector<int> &v,int s,int e)
{
    if(s>=e)
    {
        return;
    }

    int mid=s+(e-s)/2;

    mergesort(v,s,mid);
    mergesort(v,mid+1,e);
    mergeInplace(v,s,mid,e);


}



//3 maximum subarray sum
//approach 1 naive brute force
//find all subarraya
//find maximum of them

//approach 2
//D and C


//4 Quick sort (end element as pivot)
//in lekshe bhaiya style
//1 pivot =end;
//2 i=start-1;
// j=start+1;
//a[pivot]=4

void quickSort(int arr[],int s,int e)
{
    if(s>=e)
    {
        return;
    }

    int pivot=e;
    int i=s-1;
    int j=s;

    while(j<pivot)
    {
        if(arr[i]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    j++;
    swap(arr[i],arr[pivot]);

    quickSort(arr,s,i-1);
    quickSort(arr,i+1,e);



}




int main()
{
    // vector<int> arr(5);
    // arr.push_back(2);
    //  arr.push_back(4);
    //   arr.push_back(6);
    //    arr.push_back(2);
    //     arr.push_back(1);
    
    // long cnt=countInversions(arr);
    // cout<<cnt<<endl;
    int arr[]={4,6,7,1,6,9};
    int s=0;
    int e=5;
    quickSort(arr,s,e);
    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }



    return 0;
}

