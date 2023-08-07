//Doneeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
//11/3/2k23 saturday
#include<iostream>  
#include<vector>
#include<limits.h>
using namespace std;

//1 find unique element very important [1,2,3,3,4,2,1] ans is 4 that occurs only one
// int findUnique(vector<int> arr)
// {
//     int ans=0;
//     for(int i=0;i<arr.size();i++)
//     {
//         ans=ans^arr[i];  // using xor ^ operation  will cance out the common elem       
//     }
//     return ans;
// }


//Smart Dimak
int main()
{
//     //create vector 
//     //1st type
//     vector<int> arr;

// //    int ans=(sizeof(arr)/sizeof(int));
// //    cout<<ans<<endl;

//     cout<<arr.size()<<endl;;  //default size 0
//     cout<<arr.capacity()<<endl;  //default capacity 0 

//     //insert
//     arr.push_back(11);
//     arr.push_back(21);
//     arr.push_back(51);

//     for(int i=0;i<arr.size();i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
    
//     //remove /delete
//     arr.pop_back();
//     for(int i=0;i<arr.size();i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;

//     int n;
//     cout<<"Enter value of n"<<endl;
//     cin>>n;

//   //second type
//     vector<int> brr(n,-1); //-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
//     cout<<brr.size()<<endl;;  //
//     cout<<brr.capacity()<<endl;   //
//     for(int i=0;i<brr.size();i++)
//     {
//         cout<<brr[i]<<" ";
//     }
//     cout<<endl;
    

//     //3rd type sometimes use rare
//     cout<<"Prrnting crr"<<endl;
//     vector<int> crr{11,22,33,44,55};
//     for(int i=0;i<crr.size();i++)
//     {
//         cout<<crr[i]<<" ";
//     }
//     cout<<endl;

//     cout<<"Vector crr is empty or not "<<crr.empty()<<endl;;

//     vector<int> drr;
//      cout<<"Vector drr is empty or not "<<drr.empty()<<endl;;


//////////////////////////////////////////////////////////////////////////////////////
//Problem Solving on vectors

//1 find UNIQE  element  very important  //by using XOR ^ operaor cause xor of same element is zero
// int n;
// cout<<"Enter the size of array"<<endl;
// cin>>n;

// vector<int> arr(n);
// cout<<"Enter the elements"<<endl;
// for(int i=0;i<arr.size();i++)
// {
//     cin>>arr[i];
// }

// int uniqueElement=findUnique(arr);
// cout<<"Unique element is "<<uniqueElement<<endl;



//2 UNION of 2 arrays  
//here just use map to avoid the duplicates number after union of two arrays
//create an answer vector
//put all elements of a[] into ans vector
//put all elements of b[] into ans vector here first assuming no duplicates

// // union of array
// int arr[]={1,2,3,4,5};
// int sizea=5;
// int brr[]={6,7,8,9};
// int sizeb=4;
// vector<int> ans;

// //push all elements 
// for(int i=0;i<sizea;i++)
// {
//     ans.push_back(arr[i]);
// }

// for(int i=0;i<sizeb;i++)
// {
//     ans.push_back(brr[i]);
// }

// //print ans;
// // Printing the vector
// // 1 2 3 4 5 6 7 8 9
// cout<<"Printing the vector"<<endl;
// for(int i=0;i<ans.size();i++)
// {
//     cout<<ans[i]<<" ";
// }


// //3 INTERSECTION of 2 arrays                                                                                                                                                                                                                                                         

// vector<int> arr{1,2,3,3,4,4,5,6};    
// vector<int> brr{3,4,9};
 
// vector<int> ans;

// //outer loop on arr vector
// for(int i=0;i<arr.size();i++)
// {
//     int element =arr[i];
//     //for every element in brr
//     for(int j=0;j<brr.size();j++)
//     {
//         if(element==brr[j]) 
//         {
//             //mark
//            
//             ans.push_back(element);
//         }
//     }
// }


// //print ans
// for(auto value: ans)
// {
//     cout<<value<<" ";
// }
// cout<<endl;


// 4 PAIR SUM 

// pair found (20,60)
// pair found (40,40)
// vector<int> arr{10,20,40,60,80};
// int sum=80;
// //print all pairs
// //outer loop will travserse for each element
// for(int i=0;i<arr.size();i++)
// {   
//     //cout<<"we are at element "<<arr[i];
//     int element=arr[i];

//     //for every element will traverse on aage wale elements
//     for(int j=i+1;j<arr.size();j++)
//     {
//         // cout<<"pair"<<element<<"with"<<arr[j]<<" ";
//         // cout<<"("<<element<<","<<arr[j]<<")"<<" ";
//         if(element+arr[j]==sum)
//         {
//             cout<<"pair found "<<"("<<element<<","<<arr[j]<<")"<<endl;
//         }
//     }
// }



//5 TRIPLET SUM

// vector<int> arr{10,20,30};
// int sum=60;
// for(int i=0;i<arr.size();i++)
// {
//     int element1=arr[i];
//     for(int j=i+1;j<arr.size();j++)
//     {
//         int element2=arr[j];
//         for(int k=j+1;k<arr.size();k++)
//     {
//         int element3=arr[k];
      
//        if(element1+element2+element3==sum)
//        {
//         cout<<element1<<","<<element2<<","<<element3<<endl;
//        }

//     }
//     }
// }


//6 QUADRLET SUM 4
//10,20,30,10
// vector<int> arr{10,20,30,10,50,40};
// int sum=70;
// for(int i=0;i<arr.size();i++)
// {
//     int element1=arr[i];
//     for(int j=i+1;j<arr.size();j++)
//     {
//         int element2=arr[j];
//         for(int k=j+1;k<arr.size();k++)
//     {
//         int element3=arr[k];
//         for(int l=k+1;j<arr.size();l++)
//         {
//            int element4=arr[l];

//        if(element1+element2+element3+element4==sum)
//        {
//         cout<<element1<<","<<element2<<","<<element3<<","<<element4<<endl;
//        }
//         }

//     }
//     }
// }

// 7  SORT 0s AND 1s
//m1   sort method
//m2    cnt 0 and 1 and then insert  in the array
//m3  also you can do it with start  and end pointer approach

//m3 more optimized
vector<int> arr{1,0,0,0,1,1,0,0,1,1,0,1,1};
//0 0 0 0 0 0 1 1 1 1 1 1 1

int start=0;
int end=arr.size()-1;
int i=0;

while(i!=end)
{
    if(arr[i]==0)
    {
        //swap from left
        swap(arr[start],arr[i]);
        i++;
        start++;
    }
    else
    {
        //swap from right
        swap(arr[i],arr[end]);
        end--;
    }
}

 for(auto value: arr)
 {
     cout<<value<<" ";
 }


//homework
// union wala duplicates avoid code  ..............use map to store that values cause map does not allow duplicates inside it

    return 0;
}