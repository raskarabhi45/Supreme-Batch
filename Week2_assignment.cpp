#include<iostream>
using namespace std;

//#########################################
//Some fancy patterns are little bit difficult from this
//#########################################

// //check prime printing
// 1 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
// bool checkPrime(int n)
// {
//   for(int i=2;i<n;i++)
//   {
//     if(n%i==0)
//     {
//       return false;
//     }
//   }
//   return true;
// }

//reverse integer leetcode 
//set the kth bit
//conver the temperature


int main()
{
int n;
cin>>n;
for(int i=1;i<=n;i++)
{
  bool isprime=checkPrime(i);
  if(isprime)
  {
    cout<<i<<" ";
  }
}


    // int n;
    // cout<<"Enter row \n";
    // cin>>n;

//     //1 numeric Hollow half pyramid
//     /*
//     Enter row5
// 1
// 12
// 1 3
// 1  4
// 12345
// */  
//     for(int row=0;row<n;row++)
//     {
//         for(int col=0;col<row+1;col++)
//         {
//             if(col==0 || col==row || row==n-1)
//             {
//             cout<<col+1;
//             }
//             else
//             {
//                 cout<<" ";
//             }
//         }

//         cout<<endl;
//     }

//  2 numeric hollow inverted half pyramid
/*
12345
2  5
3 5
45
5
*/

// for(int row=0;row<n;row++)
// {
//     for(int col=row+1;col<=n;col++)
//     {
//       if(col==row+1 || col==n || row==0)
//       {
//          cout<<col;
//       }
//       else
//       {
//         cout<<" ";
//       }
//     }
//     cout<<endl;
// }


//3 Numeric Palindrone equilaterak pyramid
//     1
//    121
//   12321
//  1234321
// 123454321

// int k=n;
// for(int i=0;i<n;i++)
// {
//   int c=1;
//   for(int j=0;j<k;j++)
//   {
//     if(j<n-i-1)
//     {
//       cout<<" ";
//     }
//     else if(j<=n-1)
//     {
//       cout<<c++;
//     }
//      else if(j==n)
//     {
//       c=c-2;
//       cout<<c;
//       c--;
//     }
//     else
//     {
//       cout<<c;
//       c--;
//     }

//   }
//   k++;
//   cout<<endl;
// }


//4 Solid half diamond
// Enter row
// 5
// *
// **
// ***
// ****
// *****
// ****
// ***
// **
// *

// for(int i=0;i<2*n-1;i++)
// {
//   int cond=i<n?i:n-(i%n)-2;
  
//   for(int j=0;j<cond;j++)
//   {
//   cout<<"*";
//   }
//   cout<<endl;
// }

//5 fancy pattern 1
//6 fancy pattern 2
//7 fancy pattern 3

//8 Floyds Triangle Pattern
// Enter row
// 7
// 1
// 23
// 456
// 78910
// 1112131415
// 161718192021
// 22232425262728

// int c=1;
// for(int i=0;i<n;i++)
// {
//   for(int j=0;j<i;j++)
//   {
//     cout<<c++;
//   }
//   cout<<endl;
// }

//9 Pascal Traingle Pattern

//binomial coefficient c=c*(i-j)/j
//formula based
// Enter row
// 7
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// 1 5 10 10 5 1
// 1 6 15 20 15 6 1
// for(int i=1;i<=n;i++)
// {
//   int c=1;
//   for(int j=1;j<=i;j++)
//   {
//     cout<<c<<" ";
//     c=c*(i-j)/j;
//   }
//   cout<<endl;
// }

//10 Butterfly Pattern important

// Enter row
// 5
// *        *
// **      **
// ***    ***
// ****  ****
// **********
// **********
// ****  ****
// ***    ***
// **      **
// *        *

// for(int i=0;i<2*n;i++)
// {
//   int cond=i<n?i:n+(n-i-1);
//   int space_count=i<n?2*(n-cond-1):i-cond-1;

//   for(int j=0;j<2*n;j++)
//   {
//   if(j<=cond)
//   {
//   cout<<"*";
//   }
//   else if(space_count>0)
//   {
//     cout<<" ";
//     space_count--;
//   }
//   else
//   {
//     cout<<"*";
//   }
  
// }
// cout<<endl;
// }


// #########################################
//Remaining questions

//fancy patter #1

//fancy patter #2

//fancy patter #3

//Butterfly pattern






    return 0;
}