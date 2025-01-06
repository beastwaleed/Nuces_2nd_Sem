#include <iostream>
#include<string>
using namespace std;

class Animal{
    public:
    string name;
    int age;
    
    Animal(string n, int a){
        name=n;
        age=a;
    }
    
    void speak(){} //Empty as mentioned in question
    
};

class Bird: private Animal{
    private:
    int wingLength;
    
    public:
    
    Bird(string bName, int bAge, int wl) : Animal(bName, bAge) {
        wingLength = wl;
    }


    
    void speak(){
        cout<<"My Name is: "<<name <<" My Age is "<<age <<" My Wing Length is "<<wingLength<<endl<<"I am a Bird and I can Sing....\n";
    }
        
};

class Reptile : private Animal {
        private:
        string habitant;
        
        public:
        Reptile(string rName,int rAge, string hab) : Animal(rName, rAge){
            habitant=hab;
        }
        
        void speak(){
            cout<<"My Name is: "<<name<< " My age is "<<age<< " My Habitant is "<< habitant<<endl<<"I am a reptile. I can Creep.....\n";
        }
        
};

int main() {
  
    Bird bObj("Parrot",2,10);
    bObj.speak();
    Reptile rObj("Crocodile",5,"Land and Water");
    rObj.speak();

    return 0;
}