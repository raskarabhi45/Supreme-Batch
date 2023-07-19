//Doneeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee 
//##############just need to look at char arr[]  pointer there is  change
// pointers 3
// sunday 05//3/2023

#include <iostream>
using namespace std;

void util(int* p)
{
    p=p+1;
    *p=*p+1;
}

void solve(int** ffptr)
{
    // ptr=ptr+1;
    **ptr=**ptr+1;

}

int main()
{
    // int a = 5;
    // int *p = &a;
    // int **q = &p;

    // cout << a << endl;
    // cout << &a << endl;
    // cout << p << endl;
    // cout << &p << endl;
    // cout << *p << endl;
    // cout << q << endl;
    // cout << &q << endl;
    // cout << *q << endl;
    // cout << **q << endl;
    // cout << a << endl;
   
    // int a = 5;
    // int *p = &a;
    // cout<<a<<endl;
    // cout<<p<<endl;
    // cout<<*p<<endl;
    
    // util(p);

    // cout<<a<<endl;
    // cout<<p<<endl;
    // cout<<*p<<endl;

    int x=12;
    int *p=&x;
    int**q=&p;
    
    cout<<x<<endl;
    solve(q);
     cout<<x<<endl;
    

    return 0;
}