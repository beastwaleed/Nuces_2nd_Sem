//////// Operating -- Postfix Operator for Objects /////////
#include<iostream>
using namespace std;

class count{

    private:
    int n;

    public:
    count(){
        n=2;
    }

    void operator -- (int){ 
        n--;
    }

    void show(){
        cout<<"N = "<<n<<endl;
    }
};

int main(){
    count obj;
    obj.show();
    obj--;
    obj.show();

}