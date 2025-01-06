#include<iostream>
using namespace std;

class Complex{ //class for complex number
private:
float realPart;
float imagPart;
public:
    
    
    Complex(){//default constructor
        realPart=0.0;
        imagPart=0.0;
    }
    
    Complex(float r,float c){ //parametrized constructor
        realPart=r;
        imagPart=c; 
    }
    
    friend Complex addComplex(Complex C1, Complex C2);//prototype of friend function 
    
     void display(Complex addComplex){ //display function to display sum
        cout<<addComplex.realPart<<" + "<<addComplex.imagPart<<"i"<<endl;
    }
};


Complex addComplex(Complex C1, Complex C2){ //friend function definition
    Complex C3;
    C3.realPart=C1.realPart+C2.realPart; //adding real parts with the help of new C3 object
    C3.imagPart=C1.imagPart+C2.imagPart; //adding imaginary parts with the help of new C3 object
    C3.display(C3); //calling display function of Complex Class
    return C3;
}


int main()
{
    Complex Obj1(2.5,3.1); //Making First Object
    Complex Obj2(4.4, 1.3); //Making 2nd Object
    addComplex(Obj1,Obj2); //calling friend function;
    return 0;
}