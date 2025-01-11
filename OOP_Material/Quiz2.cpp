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
    Student(string n, string ID, int numCourses) : name(n), id(ID), numofcourses(numCourses) {
        grades = new double[numofcourses];
    }


    void setGrades(){
        cout << "Enter grades for " << name << ":\n";
        for(int i = 0; i < numofcourses; ++i){
            cout<<"Course "<< i + 1 << ": ";
            cin>>grades[i];
        }
    }

    friend double calculateGPA(const Student& student);

     ~Student(){
        delete[] grades;
    }
};

class Undergraduate : public Student{
public:
    Undergraduate(string Uname, string Uid, int UnumCourses) : Student(Uname, Uid, UnumCourses){}

    ~Undergraduate(){}//destructor
};

class Graduate : public Student {
private:
    string researchArea;

public:
    Graduate(string Gname, string Gid, int GnumCourses, string research) : Student(Gname, Gid, GnumCourses), researchArea(research){}

    ~Graduate() {}
};

    double calculateGPA(const Student& student) {

    double totalGrade = 0;
    for (int i = 0; i<student.numofcourses; i++){
        totalGrade +=student.grades[i];
    }
    return totalGrade / student.numofcourses;


//     bool operator <(const Student &other){
//     return this->calculateGPA() < other.calculateGPA();
// }

//   bool operator ==(const Student &other){
//     return this->calculateGPA() == other.calculateGPA();
// }

}

int main() {
    string name, researchArea,id;
    int numCourses;

    cout<<"Enter undergraduate student's name: ";
    cin>>name;
    cout<<"Enter Undergraduates student's ID: ";
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


    cout<<"========================================"<<endl;

    cout<<"Undergraduate Student GPA: " << calculateGPA(undergrad) << endl;
    cout<<"Graduate Student GPA: " << calculateGPA(grad) << endl;
  
    // if (undergrad < grad) {
    //     cout << "Graduate student has a higher GPA." << endl;
    // } else if (undergrad == grad) {
    //     cout << "Both students have the same GPA." << endl;
    // } else {
    //     cout << "UnderGraduate student has a higher GPA." << endl;
    // }

    return 0;
}
