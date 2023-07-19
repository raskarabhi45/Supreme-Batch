// PATTERN PRINTING JUST TO BUILD YOUR LOGIC
// Just remember formula

// ################################### 
//Line 300 Hollow diamond and down flipped diamond
//and 16 17 problem thats it
//######################################

#include<iostream>
using namespace std;

int main()
{
    int row,col;
    // 1) Printing Solid rectangle
/*
* * * * * 
* * * * * 
* * * * * 
*/
    //outer loop = row observe
    // for(row=0;row<3;row++)
    // {
    //     //inner loop= column observe
    //     for(col=0;col<5;col++)
    //     {
    //         cout<<"* ";
    //     }
    //     cout<<endl; 
    // }

    // 2) solid  Square
/*
* * * * * 
* * * * * 
* * * * * 
* * * * * 
* * * * * 
*/
    // int n;    
    // cin>>n;
    // for(row=0;row<n;row++)
    // {
    //     for(col=0;col<n;col++)
    //     {
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // 3)  Hollow Rectangle pattern 
/*
*****
*   *
*****
*/

    // for(row=0;row<3;row++)
    // {
    //     for(col=0;col<5;col++)
    //     {
    //         if(row==0 || row==row-1 ||col==0 || col==col-1)
    //         {
    //             cout<<"*";
    //         }
    //         else
    //         {
    //             cout<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }
    
    //or
    //
/*
*********
*       *
*       *
*       *
*       *
**********/
    // int rowcnt,colcnt;                                  
    // cin>>rowcnt>>colcnt;
    // for(row=0;row<rowcnt;row++)
    // {
    //     if(row==0 ||row==rowcnt-1)
    //     {
    //     for(col=0;col<colcnt;col++)
    //     {
    //         cout<<"*";
    //     }
    //     }
    //     else 
    //     {
    //         cout<<"*";
    //         for(col=2;col<colcnt;col++)
    //         {
    //             cout<<" ";
    //         }
    //         cout<<"*";
    //     }
    //     cout<<endl;
       
    // }

    
    //4) half Pyramid pattern                    
/*
*                         
*       *
*       *       *
*       *       *       *
*       *       *       *       *
*/
    // int n;
    // cin>>n;
    // for(row=0;row<n;row++)
    // {
    //     for(col=0;col<row+1;col++)
    //     {
    //         cout<<"*\t";
    //     }
    //     cout<<endl;
    // }

    //5) Inverted half pyramid
/*
******
*****
****
***
**
*
*/
    // int n;
    // cin>>n;
    // for(row=0;row<n;row++)
    // {
    //     for(col=0;col<n-row;col++)
    //     {
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    
    //6) Numeric half pyramid
/*
1
12
123
1234
12345*/
    // int n;
    // cin>>n;
    // for(int row=0;row<n;row++)
    // {
    //     for(int col=0;col<row+1;col++)
    //     {
    //         cout<<col+1;
    //     }
    //     cout<<endl;
    // }

    //7) Inverted Numeric half pyramid
/*
12345
1234
123
12
1*/
    // int n;
    // cin>>n;
    // for(int row=0;row<n;row++)
    // {
    //     for(int col=0;col<n-row;col++)
    //     {
    //         cout<<col+1;
    //     }
    //     cout<<endl;
    // }
    
    //Homework   

    // 8)  Full Pyramid
    /*
6
     *
    * *
   * * *
  * * * *
 * * * * *
* * * * * *
*/
    // int n;
    // cin>>n;
    // for(row=0;row<n;row++)
    // {
    //     //space
    //      for(col=0;col<n-row-1;col++)
    //     {
    //         cout<<" ";
    //     }
    //    //stars
    //     for(col=0;col<row+1;col++)
    //     {
    //         cout<<"* ";
    //     }
        
    //     cout<<endl;
    // }
   

    // 9) Inverted Full Pyramid
    /*
6    
* * * * * *
 * * * * *
  * * * *
   * * *
    * *
     *
     */
    // int n; 
    // cin>>n;
    // for(int row=0;row<n;row++)
    // {
    //     for(col=0;col<row;col++)
    //     {
    //         cout<<" ";
    //     }

    //     for(col=0;col<n-row; col++)
    //     {
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    //10 Solid Diamond pattern      
    /*
5
    *
   * *
  * * *
 * * * *
* * * * *
* * * * *
 * * * *
  * * *
   * *
    *
    * */
    // int n;
    // cin>>n;
    // for(row=0;row<n;row++)
    // {
    //     //space
    //      for(col=0;col<n-row-1;col++)
    //     {
    //         cout<<" ";
    //     }
    //    //stars
    //     for(col=0;col<row+1;col++)
    //     {
    //         cout<<"* ";
    //     }
        
    //     cout<<endl;
    // }
//inverted
    // for(int row=0;row<n;row++)
    // {
    //     for(col=0;col<row;col++)
    //     {
    //         cout<<" ";
    //     }

    //     for(col=0;col<n-row; col++)
    //     {
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    //11 Hollow Diamond
    /*
6
     *
    * *
   *   *
  *     *
 *       *
*         *
*         *
 *       *
  *     *
   *   *
    * *
     **/
    // int n;
    // cin>>n;

    // for(row=0;row<n;row++)
    // {
    //     //spaces
    //     for(col=0;col<n-row-1;col++)
    //     {
    //         cout<<" ";
    //     }
    //     //stars
    //     for(col=0;col<2*row+1;col++)
    //     {
    //         if(col==0 || col==2*row)
    //         //first character or last character
    //         {
    //             cout<<"*";
    //         }
            
    //         else
    //         {
    //             //spaces
    //             cout<<" ";
    //         }

    //     }
    //     cout<<endl;
    // }

    // for(row=0;row<n;row++)
    // {
    //     for(col=0;col<row;col++)
    //     {
    //         //spaces
    //         cout<<" ";
    //     }
    //     //star
    //     for(col=0;col<2*n-2*row-1;col++)
    //     {
    //         //for first and last character
    //         if(col==0 || col==2*n-2*row-2)
    //         {
    //             cout<<"*";
    //         }
    //         else
    //         {
    //             cout<<" ";
    //         }
           
    //     }
    //      cout<<endl;

    // }

    //12 Flipped solid diamond do again
    /*
5
***** *****
****   ****
***     ***
**       **
*         *
*         *
**       **
***     ***
****   ****
***** ***** 
*/
    // int n;
    // cin>>n;
    //upper diamond
    // for(row=0;row<n;row++)
    // {
    //     // half pyramid
    //     for(col=0;col<n-row;col++)
    //     {
    //         cout<<"*";
    //     }
    //     //space wala full pyramid
    //     for(col=0;col<2*row+1;col++)
    //     {
    //         cout<<" ";
    //     }
    //     //half pyramid
    //     for(col=0;col<n-row;col++)
    //     {
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
        
    //lower diamond
    //     // half pyramid
    //     for(row=0;row<n;row++)
    //     {
    //     for(col=0;col<row+1;col++)
    //     {
    //         cout<<"*";
    //     }
    //     //space wala full pyramid
    //     for(col=0;col<2*n-2*row-1;col++)
    //     {
    //         cout<<" ";
    //     }
    //     //half pyramid
    //     for(col=0;col<row+1;col++)
    //     {
    //         cout<<"*";
    //     }
    //     cout<<endl;
    //     }
       


    //13 fancy pattern #2
    /*
5
1
2*2
3*3*3
4*4*4*4
5*5*5*5*5
4*4*4*4
3*3*3
2*2
1
*/
    // int n;
    // cin>>n;
    // for(row=0;row<n;row++)
    // {
    //     for(col=0;col<row+1;col++)
    //     {
    //         cout<<row+1;
    //         if(col!=row )  //
    //         {
    //             cout<<"*";
    //         }
    //     }
    //     cout<<endl;
    // }

    // for(row=0;row<n;row++)
    // {
    //     for(col=0;col<n-row-1;col++)
    //     {
    //         cout<<n-row-1;
    //          if(col!=n-row-2)
    //         {
    //             cout<<"*";
    //         }
    //     }
    //     cout<<endl;
    // }

    //14 Numeric palindrome Pyramid
    /*
5
1
121
12321
1234321
123454321*/
    // int n;
    // cin>>n;
    // for(row=0;row<n;row++)
    // {
    //     for(col=0;col<row+1;col++)
    //     {
    //         cout<<col+1;
    //     }
    //     //col=col-1;

    //     //reverse counting
    //     for(col=row;col>=1;col--)
    //     {
    //         cout<<col;
    //     }
    //     cout<<endl;
    // }

    //15 Alphabet palindrome Pyramid
    /*
5
A
ABA
ABCBA
ABCDCBA
ABCDEDCBA
*/

    // int n;
    // cin>>n;
    // for(row=0;row<n;row++)
    // {
    //     for(col=0;col<row+1;col++)
    //     {
    //         int ans=col+1;
    //         char ch=ans+'A'-1;
    //         cout<<ch;
    //     }
    //     //col=col-1;

    //     //reverse counting
    //     for(col=row;col>=1;col--)
    //     {
    //         int ans=col;
    //         char ch=ans+'A'-1;
    //         cout<<ch;
    //     }
    //     cout<<endl;
    // }

    //Homework 3/2/23  friday
    
    //solid square
    //hollow square
    //hollow inverted half pyramid
    //hollow full pyramid
    //numeric hollow half pyramid
    //numeric hollow inverted half pyramid
    //Numeric palindrome equilateral pyramid
    //fancy pattern #1
    //solid half diamond
    //fancy pattern #3
    //floyds traingle
    //pascals traingle 
    //butterfly pattern

    // pattern 16 Numeric Full Pyramid
    /*

    1
   232
  34543
 4567654
567898765*/
    // int n;
    // cin>>n;
    // for(row=0;row<n;row++)
    // {
    //     //spaces 
    //     for(col=0;col<n-row-1;col++)
    //     {
    //         cout<<" ";
    //     }

    //     //numbers
    //     for(col=0;col<row+1;col++)
    //     {
    //         cout<<row+col+1;
    //     }
        

    //     //reverse counting
    //     int start=2*row;
    //     for(col=0;col<row;col++)
    //     {
    //         cout<<start;
    //         start--;

    //     }

    //     cout<<endl;
    // }

    //or
    // for(row=0;row<n;row++)
    // {
    //     //row+1 elements print krne wala hai
    //     // int start=row+1;
    //     for(col=0;col<row+1;col++)
    //     {
    //         // cout<<start<<" ";
    //         // start=start+1;
    //         cout<<col+row+1;
    //     }
    //     cout<<endl;
    // }

    

    // 17) Numeric Hollow Full pyramid
/*
5
    1
   1 2
  1   3
 1     4
1 2 3 4 5
*/
    // int n;
    // cin>>n;
    // for(row=0;row<n;row++)
    // {
    //     //spaces
    //     for(col=0;col<n-row-1;col++)
    //     {
    //         cout<<" ";
    //     }

    //     //numbers with space in between
    //     int start=1;
    //     for(col=0;col<2*row+1;col++)
    //     {
    //         //first row or last 
    //         if(row==0 || row==n-1)
    //         {
    //             if(col%2==0)
    //             {
    //                 //even
    //                 cout<<start;
    //                 start++;
    //             }
    //             else
    //             {
    //                 //odd
    //                 cout<<" ";
    //             }
    //         }
    //         else
    //         {
    //             //first col
    //             if(col==0)
    //             {
    //                 cout<<1;
    //             }
    //             else if(col==2*row)
    //             {
    //                 cout<<row+1;
    //             }
    //             else
    //             {
    //                 cout<<" ";
    //             }
    //         }
    //     }
    //     cout<<endl;
    // }


return 0;
}
