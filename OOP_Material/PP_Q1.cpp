#include<iostream>
#include<string>
using namespace std;

class Car{
    protected:
    int speed;
    double regPrice;
    string color;

    public:
    Car(int speed, double regPrice, string color){
        this->speed=speed;
        this->regPrice=regPrice;
        this->color=color;
    }

    virtual double getSalePrice()=0;

};

class Truck: public Car{
    protected:
    int weight;

    public:
    
    Truck(int weight, int speed, double regPrice, string color):weight(weight), Car(speed, regPrice, color){}

    double getSalePrice(){
        if(weight>2000){
           return regPrice*0.1;
        }
        else{
           return regPrice*0.2;
        }
    }
};

class Ford : public Car{
    private:
    int year;
    int manufacturerDiscount;

    public:

    Ford(int year, int manufacturer, int speed, double Price, string color): year(year), manufacturerDiscount(manufacturer), Car(speed,Price,color){}

    double getSalePrice(){
        return regPrice-manufacturerDiscount;
    }

};

class Sedan: public Car{
    private:
    int length;

    public:

    Sedan(int length, int speed, double Price, string color): length(length), Car(speed, Price, color){}

    double getSalePrice(){
        if(length>20){
           return regPrice*0.05;
        }

        else{
            return regPrice*0.1;
        }
    }

};

class MyOwnAutoShop{

    public:

    void main(){
        Sedan S1(40,300,550000,"Black");
        Ford F1(2003,2000,240,480000,"White");
        Ford F2(2013,5000,280,753333,"Grey");

    cout<<"The Price for Sedan Car is: "<< S1.getSalePrice()<<endl;
    cout<<"The Price for Ford Car 1 is: "<< F1.getSalePrice()<<endl;
    cout<<"The Price for Ford Car 1 is: "<<   F2.getSalePrice()<<endl;
    }

};

int main(){
    MyOwnAutoShop Shop;
    Shop.main();
}