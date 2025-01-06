#include<iostream>
using namespace std;

class Subject{
    protected:
    string subName;
    public:

    Subject(string sName):subName(sName){}

    string getSubject(){
        return subName;
    }
};

class Teacher{

    protected:
    string teacherName;
    Subject *SubPtr;

    public:
    Teacher(string tName, Subject *subjName):teacherName(tName),SubPtr(subjName){}

    void displaySubject(){
        cout<<"Teacher Name: "<<teacherName<<endl;
        cout<<"Subject: "<<SubPtr->getSubject()<<endl;
    }
};

int main(){

    Subject *sPtr= new Subject("OOP");
    Teacher Teach("Waleed",sPtr);

    Teach.displaySubject(); 

}
