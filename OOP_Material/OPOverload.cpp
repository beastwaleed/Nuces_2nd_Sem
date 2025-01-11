#include<iostream>
using namespace std;

class rectangle{
    int length;
    int width;

    public:
    rectangle(int l, int w):length(l),width(w){}

    rectangle operator <(rectangle &rec){
        if(this->length<rec.length && this->width<rec.width){
            return *this;
        }
        else{
            return rec;
        }
    }

    void display(){
        cout<<" ==== Smaller Rectangle is === "<<endl;
        cout<<"Length = "<<length<<endl;
        cout<<"Width = "<<width<<endl;
    }
};


int main(){ 

    rectangle R1(4,1), R2(6,8);
    rectangle R3= R1<R2;
   
    R3.display();

}