//website cpp reference .com   c++.com    
#include<iostream>
#include<limits.h>
using namespace std;
//10/2/23 friday
//why array of index is started from 0 below is reason
//arr+index*datatype
// 1
void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
 // 2
void inc(int arr[],int size)
{
    arr[0]=arr[0]+10;
    printArray(arr,size);

}
 // 3
//Linaer Search in array
bool find(int arr[],int size,int key)
{
    for(int i=0;i<size;i++)
    {
        if(key==arr[i])
        {
            return true;
        }
    }

    //not present
    return false;
}

//count 0s nad 1s in array



int main()
{
    //Array declaration
    // int arr[10];
    // char arr2[106];
    // bool arr[34];
    // cout<<"Arrays created successfully"<<endl;
    // cout<<arr<<endl;
    // cout<<&arr<<endl;
    // cout<<main<<endl;

    //Array Initailization
    // int arr[]={11,21,51,101,111};
    // int brr[]={11,21,51,101,111};
    // cout<<"Array initialized successfully"<<endl;

    //index and access in arrayf
    // int arr[]={5,6};
    // int size=2;
    // inc(arr,size);

    // printArray(arr,size);  //it always pass by reference when there is array in function
    
    // int arr[5]={1,3,5,7,9};
    // int size=5;
    // int key;
    // cout<<"Enter key to find in array"<<endl;
    // cin>>key;
    // if(find(arr,size,key))
    // {
    // cout<<"Found"<<endl;
    // }
    // else
    // {
    //     cout<<"not found"<<endl;
    // }


    //4 count number of zeros and once
    // int arr[]={0,1,0,0,0,0,1,1,1,1,0,0,1,0,1};
    // int size=15;

    // int numzero=0;
    // int numone=0;

    // for(int i=0;i<size;i++)
    // {
    //     if(arr[i]==0)
    //     {
    //         numzero++;
    //     }
    //     if(arr[i]==1)
    //     {
    //         numone++;
    //     }
    // }

    // cout<<"Number of zeros "<<numzero<<endl;
    // cout<<"Number of ones "<<numone<<endl;

//5
    // find maximum in arrry
    // int size=11;
    // int arr[]={3,4,6,7,9,66,4,46,6,77,9};
    // int max=INT_MIN;

    // for(int i=0;i<size;i++)
    // {
    //     if(arr[i]>max)
    //     {
    //         max=arr[i];

    //     }
    // }
    // cout<<"Maximum number is "<<max<<endl;

//6
//find minimum
    // int size=11;
    // int arr[]={3,4,6,7,9,66,4,46,6,77,9};
    // int min=INT_MAX;

    // for(int i=0;i<size;i++)
    // {
    //     if(arr[i]<min)
    //     {
    //         min=arr[i];

    //     }
    // }
    // cout<<"Minimum number is "<<min<<endl;


//7 
    //Extreme print in array
    // int arr[10]={11,22,33,44,55,66,77,88,99};
    // //output
    // //11 99 22 88 33 77 44 66 55
    // int size=9;
    // int start=0;
    // int end=size-1;

    // while(start<=end)
    // {

    //     if(start==end)
    //     {
              // for single element
    //         cout<<arr[start]<<" ";
    //     }
    //    else
    //    {
    //     cout<<arr[start]<<" ";
    //     cout<<arr[end]<<" ";
        
    //    }
    //    start++;
    //     end--;
    // }



//8
    //reverse an array
    // int arr[10]={11,22,33,44,55,66,77,88,99};
    // // 99 88 77 66 55 44 33 22 11
    // int size=9;
    // int start=0;
    // int end=size-1;
    // while(start<=end)
    // {//step 1 
    // swap(arr[start],arr[end]);
    // //
    // start++;
    // end--;
        
    // }

    // for(int i=0;i<size;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    
    
    
    









    return 0;
}