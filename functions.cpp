#include<iostream>
using namespace std;

// //Uncle Babbar print kr lena 
void printName()       //function defination
{
    int n;
    cout<<"Enter value of n"<<endl;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Babbar"<<endl;
    }

}

void printNumber(int a)  //pass by value /copy create hogi yhape
{
    ++a;
    cout<<a<<endl;
}

int getSum(int a,int b)
{
    int add=a+b;
    return add;
}

int findMax(int a,int b,int c)
{
    if(a>b && a>c)
    {
        return a;
    }
    else if(b>a && b>c)
    {
        return b;
    }
    else 
    {
        return c;
    }

}

//function of student and grade problem
char getGrade(int marks)
{
    if(marks>=90 && marks<=100)
    {
        return 'A';
    }
    else if(marks>=80 && marks<=90)
    {
        return 'B';
    }
    else if(marks>=70 && marks<=80)
    {
        return 'C';
    }
    else if(marks>=60 && marks<=70)
    {
        return 'D';
    }
    else
    {
        return 'E';
    }
}

int areaofCircle(int r)
{
    float area=3.14*r*r;
    return area;
}

void EvenOdd(int no)
{
    if(no%2==0)
    {
        cout<<"Even number"<<endl;
    }
    else
    {
        cout<<"Odd number"<<endl;
    }
}

void factorial(int no)
{
    int fact=1;

    for(int i=1;i<=no;i++)
    {
        fact=fact*i;
    }
    cout<<"Factorial is "<<fact<<endl;
}

void Prime(int no)
{
    int i;
    for(i=2;i<=no/2;i++)
    {
        if(no%i==0)
        {
            break;
        }
    }
    if(i==no/2+1)
    {
        cout<<"Number is prime number"<<endl;
    }
    else
    {
        cout<<"Number is not a prime number"<<endl;
    }
}

//print all prime numbers from 1 to n    REMEMBER++
void printprime(int no)
{
    int i,j,cnt;
    for(i=2;i<no;i++)
    {
        cnt=0;
        for(j=1;j<=i;j++)
        {
            if(i%j==0)
            {
                cnt++;
            }

        }
        if(cnt==2)
        {
            cout<<i<<endl;
        }
        
    }
}





int main()
{
    //function call  or function invoke
    // printName();

   int a=11;
   int b=21;

   // cout<<"Address of a is "<<&a<<endl;
  //printNumber(a);  //pass by value /copy create krna
//   int sum=getSum(a,b);
//   cout<<"Addition result is "<<sum<<endl;
//   int no1,no2,no3;
//   cin>>no1>>no2>>no3;

//   int max=findMax(no1,no2,no3);
//   cout<<"Maximum number is "<<max<<endl;
// int marks;
// cout<<"Enter marks"<<endl;
// cin>>marks;
// char finalgrade=getGrade(marks);
// cout<<"Final grade is "<<finalgrade

//   int r;
//   cout<<"Enter radius"<<endl;
//   cin>>r;
//   int ans=areaofCircle(r);
//   cout<<"Area of circle is "<<ans;

int no;
cout<<"Enter number"<<endl;
cin>>no;
// EvenOdd(no);
// factorial(no);
// Prime(no);
printprime(no);

    
    

    return 0;
}