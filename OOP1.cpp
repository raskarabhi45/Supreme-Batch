//1/4/2023
//saturday
//programming technique
//object is an entity which contains state and behaviours


#include<iostream>
using namespace std;

// class Animal
// {

// };

class Animal
{
    //state or properties
    private:
    int weight;

    public:
    int age;
    string type;

    //1 default constructor
    Animal()
    {
        //initialization 
        this->weight=0;
        this->age=0;
        this->type="";
        cout<<"Constructor Called"<<endl;
    }  

    //2 parametrarized constructor
    Animal(int weight,int age,string type)  //you can also pass one or two or three values
    {
        cout<<"Parametrized constructor called"<<endl;
        this->weight=weight;
        this->age=age;
        this->type=type;
    } 


    //copy constructor  for deep copy
    Animal(Animal &obj) //pass by reference
    {
        cout<<"I am copy constructor";
        this->age=obj.age;
        this->weight=obj.weight;
        this->type=obj.type;
    }


    //behaviors
    void eat()
    {
        cout<<"eating"<<endl;

    }

    void sleep()
    {
        cout<<"sleeping"<<endl;

    }

    //setter and getter to access private members outside of class

    int getWeight()
    {
        return weight;
    }

    void setWeight(int weight)
    {
        this->weight=weight;  ////this is pointer to current object
        //*this.weight=weight 
    }


    void print()
    {
        cout<<this->age<<" "<<this->weight<<endl;
        cout<<this->type<<" "<<" ";
    }
    

    //destructor atomically call for static object
    //bt for dynamic we need to deallallocate
    ~Animal()
    {
        cout<<"Inside desctructor"<<endl;
    }

};

int main()
{
    //cout<<"size of empty class is "<<sizeof(Animal)<<endl;  //size 1

    //object creation
    //static 
    Animal obj;
    obj.age=12;
    obj.type="Lion";
    cout<<"age is "<<obj.age<<endl;
    cout<<"type is "<<obj.type<<endl;
    //cout<<obj.weight; //error cause private member
    //to access private outside of class use getter and setter

    obj.eat();
    obj.sleep();

    obj.setWeight(11);
    cout<<obj.getWeight()<<endl;

    //dynamic
    //int *ptr=new int[5];
    //here ptr in store in the stack memory and array is in the heap memory
    //heap cannot atomatically clean we need to deallocate using delete keyword
    //stack can be clean

     //dynamic
     Animal* obj1=new Animal;

     //this  using dereference
     (*obj1).age=11;
    (*obj1).type="Tiger";
    //or this using 
     obj1->age=11;
     obj1->type="Tiger";

    //  Animal a;
    //  Animal b=a; //
    //  Animal c(b); //copy constructor

    Animal a;
    a.age=20;
    a.setWeight(10);
    a.type="Babbar";

    Animal b=a;  
    a.print();
    b.print();

    Animal* d=new Animal();
    //manually
    // delete b;

     //

    return 0;
}
//homework
//padding and greedy algorithm
//memory leak
//garbage collection