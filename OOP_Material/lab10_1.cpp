#include<iostream>
using namespace std;

class DOB{
    int day;
    int month;
    int year;

    public:
    DOB(int d, int m, int y):day(d),month(m),year(y){}

    void display(){
        cout<<"Date of Birth: "<<day<<"/"<<month<<"/"<<year<<endl;

    }

};

class Contact {
    string contactName; 
    int contactNumber;
    string contactEmail;
    DOB dobj;

public:
    Contact(string n, int cn, string email, DOB d) : contactName(n), contactNumber(cn), contactEmail(email), C1(d) {}

void display(){
    cout<<"Contact Name: "<<contactName<<endl;
    cout<<"Contact Number: "<<contactNumber<<endl;
    cout<<"Contact Email: "<<contactEmail<<endl;
    dobj.display();
}

};

class ContactBook{
public:
};


int main()
{

    return 0;
}

