#include <iostream>
#include <string>
using namespace std;

class PersonType {
protected:
    string firstName;
    string lastName;

public:
    PersonType(string first, string last) : firstName(first), lastName(last) {}

    void setName(string first, string last) {
        firstName = first;
        lastName = last;
    }

    string getFirstName() {
        return firstName;
    }

    string getLastname() {
        return lastName;
    }

    void printName() {
        cout << firstName << " ";
        cout << lastName << endl;
    }
};

class dateType {
protected:
    int dMonth;
    int dDay;
    int dYear;

public:
    dateType() {
        dMonth = 0;
        dDay = 0;
        dYear = 0;
    }

    void setDate(int month, int day, int year) {
        dMonth = month;
        dDay = day;
        dYear = year;
    }

    int getDay() {
        return dDay;
    }

    int getMonth() {
        return dMonth;
    }

    int getYear() {
        return dYear;
    }

    void PrintDate() {
        cout << "Date is (mm-dd-yyyy): " << dMonth << "-" << dDay << "-" << dYear << endl;
    }
};

class doctorType : public PersonType {
    string docSpeciality;

public:
    doctorType(string firstname, string lastname, string Speciality) : docSpeciality(Speciality), PersonType(firstname, lastname) {}

    void setDocName(string first, string last) {
        firstName = first;
        lastName = last;
    }

    void setDocSpeciality(string docSpecial) {
        docSpeciality = docSpecial;
    }

    string getDocName() {
        return firstName + lastName;
    }

    string getDocSpeciality() {
        return docSpeciality;
    }

    void PrintDoc() {
        cout << "========Doctor Data========\n\n";
        cout << "-- Doctor Name: " << getDocName()<<endl;
        cout << "-- Doctor Speciailty " << getDocSpeciality()<<endl<<endl;
    }
};

class billType {
    int PatientId;
    float PharmacyCharges;
    float doctorFee;
    float roomCharges;

public:
    billType(int pId, float pharmacy, float doctor, float room) : PatientId(pId), PharmacyCharges(pharmacy), doctorFee(doctor), roomCharges(room) {}

    void setPatientId(int pId) {
        PatientId = pId;
    }

    void setPharmacyCharges(float pCharges) { PharmacyCharges = pCharges; }
    void setDocFee(float docFee) { doctorFee = docFee; }
    void setRoomCharges(float room) { roomCharges = room; }

    int getPatientId() {
        return PatientId;
    }

    float getPharmacyCharges() {
        return PharmacyCharges;
    }

    float getDocFee() {
        return doctorFee;
    }

    float getRoomCharges() {
        return roomCharges;
    }

    void PrintPatient() {
        cout << "=====Patient Info=====\n\n";
        cout << "--Patient Id: " << PatientId << endl;
        cout << "--Pharmacy Charges: " << PharmacyCharges << endl;
        cout << "--Doctor's Fee: " << doctorFee << endl;
        cout << "--Room Charges: " << roomCharges << endl;
    }
};

class PatientType : public PersonType {
private:
    int pId;
    int pAge;
    dateType dob;

public:
    PatientType(string first = "", string last = "", int id = 0, int age = 0, dateType dob = dateType()) : pId(id), pAge(age), dob(dob), PersonType(first, last) {}

    void setPatientId(int id) {
        pId = id;
    }

    void setAge(int age) {
        pAge = age;
    }

    void setDOB(int month, int day, int year) {
        dob.setDate(month, day, year);
    }

    int getPatientId() const {
        return pId;
    }

    int getAge() const {
        return pAge;
    }

    dateType getDOB() const {
        return dob;
    }

    void PrintPatientInfo() {
        cout << "=====Patient Info=====\n\n";
        cout << "--Patient Id: " << pId << endl;
        cout << "--Patient Name: ";
        printName();
        cout << "--Patient Age: " << pAge << endl;
        cout << "--Date of Birth: ";
        dob.PrintDate();
        cout << endl;
    }
};

int main() {
    // Testing the classes
    doctorType doctor("John ", "Doe", "Cardiology");
    doctor.PrintDoc();

    billType bill(12345, 100.0, 250.0, 500.0);
    bill.PrintPatient();

    PatientType patient("Jane", "Smith", 67890, 35);
    patient.setDOB(5, 15, 1989);
    patient.PrintPatientInfo();

    return 0;
}
