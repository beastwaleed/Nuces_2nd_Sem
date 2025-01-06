//Adding two objects with + operator
#include<iostream>
using namespace std;

class Add{
    private:
    int x;

    public:
    Add(int n): x(n){}; 

    int getValueOfx(){
        return x;
    }

    Add operator +(Add &Other){
        return this->x+Other.x;
    }
};

int main(){
    Add A1(5), A2(10);
    Add A3=A1+A2;
    cout<<A3.getValueOfx();

}