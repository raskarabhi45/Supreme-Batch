//Doneeeeeeeeeeeeeeeeeeeeeeeeeeeee
//12/03/2023
//sunday
#include<iostream>
#include<vector>
using namespace std;

//1 is array sorted or not using recursion
bool checkSorted(vector<int> &arr,int &n,int i) 
{
    //base case............
    if(i==n-1)
    {
        return true;
    }
    //1 case solve krdo...........
    if(arr[i+1]<arr[i])
    {
            return false;
    }
    // baki recursion sambhal lega
    return checkSorted(arr,n,i+1);
}

//2 binary search using recursion
int binarySearch(vector<int> &v,int s,int e,int key)
{
    //base case
    //case 1 key not found...
    if(s>e)
    {
        return -1;
    }
    int mid=s+(e-s)/2;
    //case 2 key found
    if(v[mid]==key)
    {
        return mid;
    }
     //using ternary operator
    // return (v[mid]<key) ? binarySearch(v,mid+1,e,key) :binarySearch(v,s,mid-1,key);

    //ek case solve krdo
    //arr[mid]<key right me search
    if(v[mid]<key)
    {
        return binarySearch(v,mid+1,e,key);
    }
    else
    {
        //arr[mid]>key left me search
        return binarySearch(v,s,mid-1,key);
    }
    //baki recursion kr dega
}

//3 very important best problem to understand recursion tree in depth pure example            revise 
// subsequence of a string
// c b bc a ac ab abc   
void  printSubsequence(string str,string op,int i,vector<string> &v)
{
   //base case 
    if(i>=str.length())
    {
       // cout<<op<<" ";
        v.push_back(op);
        return;
    }

    //exclude
    printSubsequence(str,op,i+1,v);

    //include //concatenation of op string and ith character
     op.push_back(str[i]);   //either this line or below line
    // op=op+str[i]; either this line or above line
    printSubsequence(str,op,i+1,v);

}

int main()
{

    // vector<int>v{11,22,33,44,55};
    // int n=v.size();
    // int i=0;

    // bool isSorted=checkSorted(v,n,i);

    // if(isSorted)
    // {
    //     cout<<"Array is sorted"<<endl;
    // }
    // else{
    //      cout<<"Array is not sorted"<<endl;
    // }

    // int target=44;
    // int s=0;
    // int e=n-1;
    // int ans=binarySearch(v,s,e,target);
    // cout<<"Answer is "<<ans<<endl;

    string str="ABHI";
    string op="";
    vector<string>v;

    int i=0;
    printSubsequence(str,op,i,v);
    cout<<"printing all subsequence"<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }



    return 0;
}