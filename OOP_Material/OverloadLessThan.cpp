#include<iostream>
using namespace std;

class Height{
    int length;

    public:
    Height(int l):length(l){}

    bool operator >(Height &h1){
        if(this->length>h1.length){
            return true;
        }
        else{
            return false;
        }

    }
    
};

int main(){
    Height h1(10);
    Height(h2)(20);

    if(h1>h2){
        cout<<"Height 1 is Greater\n";
    }
    else{
        cout<<"Height 2 is Greater\n";
    }
}