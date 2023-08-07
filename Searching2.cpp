// ##################################################
// square root find me right me ans store krna and precision step to find float ans
// Binary search 2D
// int rowindex = mid / cols;
// int colindex = mid % cols;
// ##################################################


#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 1 Find pivot element in an array
//  where order breaks
//  for example arr[]=[1,4,7,8,3,2]  here 8 is the pivot element
//  int findPivot(vector<int> arr)
//  {
//  int s=0;
//  int e=arr.size()-1;
//  int mid=s+(e-s)/2;

// while(s<=e)
// {
//     if(arr[mid+1]<arr.size() && arr[mid]>arr[mid+1])
//     {
//         return mid;
//     }
//     if(arr[mid-1] >0 && arr[mid-1]>arr[mid])
//     {
//         return mid-1;
//     }

//     if(arr[s]>arr[mid]) //TO LEFT mai hi order break  huaa hoga         REMEMBER++
//     {
//         e=mid-1;
//     }
//     else
//     {
//         s=mid+1;
//     }

//      mid=s+(e-s)/2;
// }

// return mid;

// }

// 2 square root of number using BinarySearch
// only integer part
int squareRoot(int n)
{
    int s = 0;
    int target = n;
    int e = n;
    int ans = 0;
    int mid = s + (e - s) / 2;

    while (s <= n)
    {
        if (mid * mid == target)
        {
            return mid;
        }
        if (mid * mid > target)
        {
            // left search
            e = mid - 1;
        }
        else
        {
            ans = mid;
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}

// 3 for floating part of square root
// inside the main method code is written for this
int squareRootAccurate(int n)
{
    int s = 0;
    int target = n;
    int e = n;
    int ans = 0;
    int mid = s + (e - s) / 2;

    while (s <= n)
    {
        if (mid * mid == target)
        {
            return mid;
        }
        if (mid * mid > target)
        {
            // left search
            e = mid - 1;
        }
        else
        {
            ans = mid;
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}

// 6 binary search on 2d matrix
bool binarySearch2D(int arr[][4], int rows, int cols, int target)
{
    int s = 0;
    int e = rows * cols - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        int rowindex = mid / cols;
        int colindex = mid % cols;
        int element = arr[rowindex][colindex];

        if (element == target)
        {
            return true;
        }
        if (element > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        int mid = s + (e - s) / 2;
    }
    return false;
}

int main()
{
    // vector<int> arr{3,4,5,6,7,1,2};
    // int ans=findPivot(arr);

    // cout<<"Pivot element is "<<arr[ans]<<endl;
    // int n;
    // cout<<"Enter number"<<endl;
    // cin>>n;

    // int ans=squareRootAccurate(n);
    // cout<<"Square root is "<<ans<<endl;

    // int precision;
    // cout<<"Enter number of floating digits "<<endl;
    // cin>>precision;

    //  double step=0.1;
    //  double finalans=ans;

    // for(int i=0;i<precision;i++)
    // {
    //     for(double j=ans;j*j<=n;j=j+step)
    //     {
    //         finalans=j;
    //     }
    //     step=step/2;
    // }
    // cout<<"Final ans is "<<finalans<<endl;

    // binary search in 2d array
    int arr[5][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}, {17, 18, 19, 20}};
    int row = 5;
    int col = 4;
    int target = 19;
    bool ans = binarySearch2D(arr, row, col, target);
    if (ans == true)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    return 0;
}