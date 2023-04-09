// 10/03/2023 friday
// Recursion 
//magical line
//1 case solve kdro baki recursion sambhal lega
//recursion pe sandeh nhi krna hai kbhi bhi
//recursion kbhi dga nhi deta so be boss of recursion

// bigger problem -> choti problem 
//base condition
//recursive relation
//processing

//recursive callstack

//head recursion
//tail recursion

#include<iostream>
using namespace std;

//1 factorial of number by factorial
int fact(int no)
{
    cout<<"function is called for n : "<<no<<endl;
    //base case
    if(no==1)
    {
        return 1;
    }
    int ans=no*fact(no-1);
    return ans;

}


//print counting
void printCounting(int n) 
{
    //base case
    if(n==0)
    {
        return;
    }
    //printCounting(n-1)  // head recursion
    //yha 1 2 3 4 5 print ho rha hai
    //processing
    cout<<n<<endl;
    //recursive relation
    printCounting(n-1);   //tail recursion  5 4 3 2 1 
}


//fibonacii series
int fib(int n)
{
    if(n==1)
    {  //first term 
        return 0;
    }
    if(n==2)
    {  //secon term
        return 1;
    }
    //f(n)=f(n-1)+f(n-2)
    int ans=fib(n-1)+fib(n-2);

    return ans;
}

int main()
{
    int n;
    cout<<"Enter number"<<endl;
    cin>>n;
    // int ans=fact(n);
    // cout<<ans<<endl;;
    // printCounting(n);
    int ans=fib(n);
    cout<<n<<"th term is : "<<ans<<endl;

    return 0;
}
