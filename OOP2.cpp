//Doneeeeeeeeeeeeeeeeeeeeeeeeeeeee
//Sunday
//2/4/2023
#include<iostream>
using namespace std;

//subkuch abstraction hai 

//4 pillars of OOP reusability in all OOPs concepts
// abstrcation  ex girlfriend thappd  wo nhi btayegi thappad q mari sirf mar ke chli jayegi
// isme hm implementation hide krte hai
// encapsulation inheritance polymorphism abstraction
// sbke pitaji abstracion is pr base hai sare OOP concepts

// 1 encapulation    (data hiding)
// class capsule jaisa work kr rhi hai
// binding characters and behiviours together inside the class (data members and memeber functions)
// data hiding increase security
// perfect encapulation : private sara hide  access through getters and setters
// we achieve this through access modifires public private protected


//2 Inheritance  reusability
// we inherit the properties from parent class to child class
// super class / base class / parent class 
// child class / sub class  / derived class
// mode of inheritance public private protected :

//polymorphism 
//compile time and run time
//in compile time 1) funciton overloading and 2) operator overloading



// //encapulation
// class Animal
// {
//     public:   //full encapsulation
//     int age;
//     int weight;

//     void eat()
//     {
//         cout<<"Eating"<<endl;
//     }

//     void sleep()
//     {
//         cout<<"sleeping"<<endl;
//     }

//     int getAge() //getter
//     {
//         return this->age;
//     }

//     void setAge(int age) //setter
//     {
//         this->age=age;
//     }

// };


// class Dog: private Animal
// {
//     public:
//     void print()
//     {
//         cout<<this->age<<endl;
//     }

// };


//example of operator overloading

class Param
{
    public:
    int val;

    void operator+(Param &obj2)
    {
        int value1=this->val;
        int value2=obj2.val;
        cout<<value2-value1<<endl;

    }
};

// obj1.add(obj2)
// here of obj1+obj2 
//obj1 current object ki trh treet hoga and 
// + function call 
// obj2 input parametter 





int main()
 {
//     Dog d1;
//    // d1.eat();
//     d1.print(); 
    //cout<<d1.age;

    Param obj1,obj2;
    obj1.val=7;
    obj2.val=2;
    //this should print the difference between them
    obj1+obj2;

    return 0;
}