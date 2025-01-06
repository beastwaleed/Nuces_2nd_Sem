//Adding two objects with - operator
#include<iostream>
using namespace std;

class Subtract{
    private:
    int x;

    public:
    Subtract(int n): x(n){}; 

    int getValueOfx(){
        return x;
    }

    Subtract operator -(Subtract &Other){
        return this->x-Other.x;
    }
};

int main(){
    Subtract A1(10), A2(5);
    Subtract A3=A1-A2;
    cout<<A3.getValueOfx();

}