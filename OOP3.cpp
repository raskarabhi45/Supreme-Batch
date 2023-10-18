//Doneeeeeeeeeeeeeeeeeeeeeeeeeee
//wednseday 5/4/2023
//Bhaiya is not well 
//just came from banglore to delhi so 
//todays class will not be there


//encapsulation is subset of abstraction

//so here we again 
// 7/4/2023      friday
// Runtime polymorphism or late binding or dynamic binding
//inheritance kiya hai and child class me hum hmari customized implemantation krte hai

//abstraction   (implementation hiding)
//access specifiers or modifiers
//public private protected
// a group of many things
//compile time and run time polymorphism
//inheritance diamond problem
////////////////////////////// END OF OOP /////////////////////////////////

#include<iostream>
using namespace std;


class Animal
{
    public:
    Animal()
    {
        cout<<"Inside animal constructor"<<endl;
    }

    virtual void speak()
    {
        cout<<"Speaking"<<endl;
    }

    ~Animal()
    {
        cout<<"Inside Animal destructor"<<endl;
    }
};



class Dog:public Animal
{
    //
    public:
    Dog()
    {
        cout<<"Inside Dog constructor"<<endl;
    }

     void speak()
    {
        cout<<"barking"<<endl;
    }

    ~Dog()
    {
        cout<<"Inside Dog destructor"<<endl;
    }
};


int main()
{
    // Dog a;
    // a.speak();

    // Animal* obj=new Animal();
    // obj->speak();    //speaking

    // Dog* a=new Dog();
    // a->speak();   //barking

    //upcasting
    // Animal* obj=new Dog();   //parent pointer  and child object
    //yha pe hmesha parent ka function call hota hai
    //pr jb hum virtual use krte hai to  child ka call hota hai
    // obj->speak();

    // Animal* a=new Dog();     //inside heap dog type memeory created

    //downcasting
    // Dog* obj2=(Dog*)new Animal();   // 
    //  obj2->speak();//





    //Dynamic memory allocation
    //int* ptr=new int[5] 1 d array
    //in stack=in heap memory

    //2d array
    //int** ar=new int*[n];   array of pointers



                                                 //initianlization 
    //vector<vector<int>> arr(row,vector<int>(col,o));
      //dynamic memory allocation
    //creating 2d array dynamically
    int row=5;
    int col=3;
    int** arr=new int*[5];

    for(int i=0;i<row;i++)
    {
        arr[i]=new int[col];
    }

    //printing
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


    //de allocate
    for(int i=0;i<row;i++)
    {
        delete []arr;
    }

    delete []arr;


    return 0;
}