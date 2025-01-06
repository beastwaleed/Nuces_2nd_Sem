/////////// Compare (< - Less than) Operator Overloading in C++ //////////////////

#include<iostream>
using namespace std;

class compare{

    private:
    int hours;
    int minutes;

    public:

    compare(int h, int m):hours(h),minutes(m){}

    bool operator <(compare &other){
        if(this->hours<other.hours){
            return true;
        }
        else if (this->hours==other.hours){
            return minutes<other.minutes;
        }

        else{
            return false;
        }
    }
};

int main(){

    compare C1(10,30), C2(12,40);
    if(C1<C2){
        cout<<"Time of C1 is Less than Time of C2\n";
    }

}
