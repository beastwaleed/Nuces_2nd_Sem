//////// Operating * Multiplication Operator for Objects /////////

#include<iostream>
using namespace std;

class count{

    private:
    int n;

    public:
    count(){
        n=2;
    }

    void operator * (int obj){ 
        n=n*obj;
    }

    void show(){
        cout<<"N = " <<n<<endl;
    }
};

int main(){
    count obj;
    obj.show();
    obj*5;
    cout<<"After (*5) Operator Overloading\n";
    obj.show();

}