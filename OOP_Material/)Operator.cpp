//////// Operating / Divide Operator for Objects /////////

#include<iostream>
using namespace std;

class count{

    private:
    int n;

    public:
    count(){
        n=10;
    }

    void operator / (int obj){ 
        n=n/obj;
    }

    void show(){
        cout<<"N = " <<n<<endl;
    }
};

int main(){
    count obj;
    obj.show();
    obj/2;
    cout<<"After (/2) Operator Overloading\n";
    obj.show();

}