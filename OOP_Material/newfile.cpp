#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    string id;
    int numofcourses;
    double* grades;

public:
    Student(string n, string ID, int nfc) : name(n), id(ID), numofcourses(nfc) {
        grades = new double[numofcourses];
    }

    virtual ~Student(){
        delete[] grades;
    }

    void setGrades(){
        cout << "Enter grades for " << name << ":\n";
        for(int i = 0; i < numofcourses; ++i){
            cout<<"Course "<< i + 1 << ": ";
            cin>>grades[i];
        }
    }

    friend double calculateGPA(const Student& student);
};

class Undergraduate : public Student{
public:
    Undergraduate(string _name, string _id, int _numCourses) : Student(_name, _id, _numCourses) {}

    ~Undergraduate(){}//destructor
};

class Graduate : public Student {
private:
    string researchArea;

public:
    Graduate(string _name, string _id, int _numCourses, string _researchArea) : Student(_name, _id, _numCourses), researchArea(_researchArea) {}

    ~Graduate() {}
};

double calculateGPA(const Student& student) {
    double totalGrade = 0;
    for (int i = 0; i<student.numofcourses; ++i) {
        totalGrade +=student.grades[i];
    }
    return totalGrade / student.numofcourses;
}

int main() {
    string name, researchArea,id;
    int numCourses;

    cout<<"Enter undergraduate student's name: ";
    cin>>name;
    cout<<"Enter undergraduate student's ID: ";
    cin>>id;
    cout<<"Enter number of courses for undergraduate student: ";
    cin>>numCourses;
    Undergraduate undergrad(name, id, numCourses);
    undergrad.setGrades();

    cout<<"Enter graduate student's name: ";
    cin>>name;
    cout<<"Enter graduate student's ID: ";
    cin>>id;
    cout<<"Enter number of courses for graduate student: ";
    cin>>numCourses;
    cout<<"Enter research area for graduate student: ";
    cin>>researchArea;
    Graduate grad(name, id, numCourses, researchArea);
    grad.setGrades();

    cout<<"Undergraduate GPA: " << calculateGPA(undergrad) << endl;
    cout<<"Graduate GPA: " << calculateGPA(grad) << endl;

    return 0;
}
