#include<iostream>
using namespace std;

class rectangle{
    int length;
    int width;

    public:

    rectangle(int l, int w):length(l),width(w){}

    rectangle operator +(rectangle &rec){
        length=this->length+rec.length;
        width=this->width+rec.width;
        return *this;
    }

    void display(){
        cout<<"Length is: "<<length<<endl;
        cout<<"Width is: "<<width<<endl;
    }

};

int main(){
    rectangle R1(5,6), R2(4,6);
    rectangle R3=R1+R2;
    R3.display();
}