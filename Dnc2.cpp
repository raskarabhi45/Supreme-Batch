// Quick sort and BackTracking
//Sunday 19/3/2023
#include<iostream>
using namespace std;

//ek number ko apne correct jgh pr pohcha do
//baki recursion kr dega for sure 

int partition(int arr[],int s,int e)
{
    //step1: choose pivot element
    int pivotIndex=s;
    int pivotElement=arr[s];

    //step2 : find right position for pivot element and place it there
    int cnt=0;
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<=pivotElement)
        {
            cnt++;
        }
    }

    //jab me loop se bahr aaya toh mere paas pivot ki right position ka index ready hai
    int rightIndex=s+cnt;
    swap(arr[pivotIndex],arr[rightIndex]);
    pivotIndex=rightIndex;

    //step3 :left me chote and right me bde element
    int i=s;
    int j=e;

 //counting wrong elements 
    while(i<pivotIndex && j> pivotIndex)
    {
        //here all the elements are correctly placed
        while(arr[i]<=pivotElement)
        {
            i++;
        }

        while(arr[j]>pivotElement)
        {
            j--;
        }
    }
    //here we have to place right elements
    // 2 case ho skte hai
    //case 1 : you found the elements to swap
    //case 2 : no need to swap
    if(i<pivotIndex && j> pivotIndex)
    {
        swap(arr[i],arr[j]);
    }

    return pivotIndex;

}

void quickSort(int arr[],int s,int e)
{
    //base case
    if(s>=e)
    {
        return;
    }

    //partition logic returns pivot index
   int p= partition(arr,s,e);
    //recursion calls
    //pivot element ->left
    quickSort(arr,s,p-1);     

    //pivot element->right
    quickSort(arr,p+1,e);
}


/////////////////////////////////////// 
//backtracking start 1.30 pm 
//gold coin glass ke niche example
//specific form  of recursion
//we are exploring all possible solutions  
//problem solving technique entirely based on recursion
// problem rat in a maze, password, escape puzzle
//bahut ghtiya time complexity ke solutions tum backtracking se krte hai

// question important
// 1 permutaion of a string
//op is abc acb bac bca cba cab 
void printPermutation(string &str,int i)
{
    // base case             
    if(i>=str.length())
    {
        cout<<str<<" ";
        return;
    }

    //swapping
    for(int j=i;j<str.length();j++)
    {
        //swap
        swap(str[i],str[j]);

        //recursion call
        printPermutation(str,i+1);

        // backtracking
        swap(str[i],str[j]);


    }

}

int main()
{
    //1
    // int arr[]={8,1,3,4,20,50,30,3,3,3,55,66,77,2,11,11,11,4,3,55};
    // int n=20;
    // int s=0;
    // int e=n-1;
    // quickSort(arr,s,e);

    // for(int i=0;i<n;i++) 
    // {
    //     cout<<arr[i]<<" ";
    // }

    //2

    string str="abc";
    int i=0;
    printPermutation(str,i);

    return 0;
}