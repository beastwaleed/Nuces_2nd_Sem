#include<iostream>
using namespace std;

class Student{
    private:
    string name;
    int marks[3];

    public:
    Student(string n,int m1,int m2,int m3){
        name = n;
        marks[0]=m1;
        marks[1]=m2;
        marks[2]=m3;
        
    }

    Student &getName(){
        cout<<"Name: "<<name<<endl;
        return *this;
    }

    Student &getMarks(){
        cout<<"Marks 1: "<<marks[0]<<endl
            <<"Marks 2: "<<marks[1]<<endl
            <<"Marks 3: "<<marks[2]<<endl;
            return *this;
    }

    Student &avgMarks(){
        cout<<"Average Marks: "
            <<(marks[0]+marks[1]+marks[2])/3;
            return *this;
    }

};

int main(){
    Student S1("Waleed",5,5,5);
    S1.getName().getMarks().avgMarks();
}