//Connect 2  08/02/ 2023 WEDNESDAY

#include<iostream>
using namespace std;

int main()
{
    int no,digit,rev=0;
    no=1234;
    int temp=no;

 //1) find digits 
    while(no!=0)
    {
        digit=no%10;
        cout<<digit<<endl;
        no=no/10;         
    }

//and 2) reverse number
    no=temp;
    while(no!=0)
    {
        digit=no%10;
        rev=rev*10+digit;
        no=no/10;
    }
    cout<<rev<<endl;

    // 3rd problem from  
    // 2 5,8 make it 258
  //create an array
    int digits[]={8,2,3,7};
    int ans=0;
    for(int i=0;i<4;i++)
    {
        ans=ans*10+digits[i];
    }
    cout<<ans<<endl; //8237

    //4 count number of set bits
    int n=15; //binary representation 1111
    int ans1=0;
    
    while(n!=0)
    {
        if(n & 1)
        {
            //found one set bit
            ans1++;
        }
        //right shift
        n=n>>1;
    }
    cout<<"Number of set bits "<<ans1<<endl;

    //5 convert km to miles   1mile=1/1.6km
    int km;
    cout<<"ENter km"<<endl;
    cin>>km;
    float ans2=(1/1.609)*km;
    cout<<ans2<<endl;



    return 0;
}