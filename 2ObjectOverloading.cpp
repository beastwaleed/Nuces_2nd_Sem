//Adding two objects with * operator
#include<iostream>
using namespace std;

class Multiply{
    private:
    int x;

    public:
    Multiply(int n): x(n){}; 

    int getValueOfx(){
        return x;
    }

    Multiply operator *(Multiply &Other){
        return this->x*Other.x;
    }
};

int main(){
    Multiply A1(5), A2(10);
    Multiply A3=A1*A2;
    cout<<A3.getValueOfx();

}