//Pointers day2 
//04/03/2023 saturday
#include<iostream>
using namespace std;

void solve(int arr[])
{            
    cout<<"Size inside solve function "<<sizeof(arr)<<endl;
}

int main()
{
    // int arr[10]={1,2,3,4,5,6,7,8,9,1};  arr[2]  2[arr] *(arr+2) *(2+arr) same
    // cout<<"This all are same "<<endl;
    // cout<<2[arr]<<endl;
    // cout<<arr[2]<<endl;
    // cout<<*(arr+2)<<endl;
    // cout<<*(2+arr)<<endl;
    // cout<<"Output of all is same "<<endl;

// for character array
    // char ch[10]={"babbar"};
    // char* c=ch;
    // cout<<ch<<endl;
    // cout<<c<<endl; //here we get name not address coz implemenataion of cout is diff
    // cout<<&ch<<endl;
    // cout<<ch[0]<<endl;
    // cout<<&c<<endl;
    // cout<<*c<<endl;

    // char name[10]="SherBano";
    // char* c=&name[0];
    // cout<<name<<endl;  //SherBano
    // cout<<&name<<endl;  //0x60ff06
    // cout<<*(name+3)<<endl;  //r
    // cout<<c<<endl;    //SherBano
    // cout<<&c<<endl;   //0x60ff00
    // cout<<*(c+3)<<endl;   ///r
    // cout<<c+2<<endl;   //erBano
    // cout<<*c<<endl;//s
    // cout<<c+8<<endl;

    // char ch='k';
    // char* c=&ch;
    // cout<<c<<endl;  //k and garbage values

    // char name[10]="babbar";
    // cout<<name<<endl;
    // //bad practice temporary storage   so dont use it
    // char* c="babbar";
    // cout<<c<<endl;

    //Pointers with functions
    int arr[10]={1,2,3,4,5};
    cout<<"size inside main function : "<<sizeof(arr)<<endl;
    solve(arr);
    // size inside main function : 40
    // Size inside solve function 4

    
    return 0;
}