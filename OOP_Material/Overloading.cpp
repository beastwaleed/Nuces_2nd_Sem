//Adding two objects with / operator
#include<iostream>
using namespace std;

class Divide{
    private:
    float x;

    public:
    Divide(int n): x(n){}; 

    int getValueOfx(){
        return x;
    }

    Divide operator /(Divide &Other){
        return this->x/Other.x;
    }
};

int main(){

    Divide A1(10), A2(5);
    Divide A3=A1/A2;
    cout<<A3.getValueOfx();
    
}