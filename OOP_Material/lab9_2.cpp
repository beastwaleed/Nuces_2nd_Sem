#include <iostream>
#include <string>
using namespace std;


class Boat{
    protected:
    int boatLength;
    
    public:
    Boat(int bl){
        boatLength=bl;
    }
    void swim(){
        cout<<"I am Swimming\n";
    }
};

class Plane{
    protected:
    int maxAltitude;
    
    public:
    Plane(int Alt){
        maxAltitude=Alt;
    }
    
    void fly(){
        cout<<"I am Flying\n";
    }
};

class Skimmer: protected Boat, protected Plane{
    private:
    string name;
    int numPassengers;
    
    public:
    Skimmer(string n, int bLength, int numP, int mAlt) : Boat(bLength), Plane(mAlt){
        name=n;
        numPassengers=numP;
    }
    
    void Display(){
        cout<<"Skimmer Name: "<<name<<" Length: "<<boatLength<<", Max ALtitude: "<<maxAltitude<<", Passengers : "<<numPassengers<<endl;
    }
    
    void swimAndFly(){
        swim();
        fly();
    }
};

int main(){
    
    Skimmer sObj("Swim and Fly",40,1300,2);
    sObj.Display();
    sObj.swimAndFly();

	return 0;
}
