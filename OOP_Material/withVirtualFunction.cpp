#include<iostream>
using namespace std;

class A{
    private:
    int x;
    public:
    virtual void hello(){
        cout<<"Parent class A...."<<endl ;
    }

};

class B: public A{
    public:
    void hello(){
        cout<<"Child B Hello...."<<endl;
    }
};

class C: public A{
    public:
    void hello(){
        cout<<"Child C Hello...."<<endl;
    }
};

int main(){
    A *ptr;
    B Bobj;
    C Cobj;

    Bobj.hello(); //call the Base class B Constructor using Multiple Diagram
    Cobj.hello(); //call the Base Class C Constructor using Multiple Diagram
    
    cout<<"--------------------------\n";
    ptr=&Bobj; //store the address of B class Object
    ptr->hello(); //as per our logic it look like that it will print B class hello function but it will call Parent class hello Function

    ptr=&Cobj; //store the address of C class Object
    ptr->hello(); //as per our logic it look like that it will print C class hello function but it will call Parent class hello Function

    return 0;
}

/*
if we want to display the hello functions of specific base classes 
then we have to use virtual function, without virtual it will 
only call the member functions of the class of which 
Pointer Object is made of.

without virtual function example code is in 'withoutVirtual.cpp' File 
*/