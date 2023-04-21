//***************************************************************
//REMAINING
#include<iostream>
#include<cmath>
using namespace std;

//NEED TO REVICE AGAIN AND AGAIN 


int decimalToBinaryMethod1(int n)
{
    //Division method
    int binaryno=0;
    int i=0;
    while(n>0)
    {
        int bit=n%2;
        binaryno =bit*pow(10,i++)+binaryno;
        n=n/2;
    }
    return binaryno;
}


//some mistake
int decimalToBinaryMethod2(int n)
{
    //Bitwise method
    int binaryno=0;
    int i=0;
    while(n>0)
    {
        int bit=(n & 1);
        binaryno =bit*pow(10,i++)+binaryno;
        n = n >> 1;
    }
    return binaryno;
}

int binaryToDecimal(int n)
{
    int decimal=0;
    int i=0;
    while(n)
    {
        int bit=n%10;
        decimal=decimal+bit*pow(2,i++);
        n=n/10;
    }

    return decimal;
}

int main()
{
    cout<<"Enter number"<<endl;
    int n;
    cin>>n;

    // int binary=decimalToBinaryMethod2(n);
    // cout<<binary<<endl;
    
    cout<<binaryToDecimal(n);
    return 0;
}