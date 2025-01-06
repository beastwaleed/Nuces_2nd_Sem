// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class dateType{
  public:
  int dMonth;
  int dDay;
  int dYear;
    
  public:
 
 dateType(){
     dMonth=1;
     dDay=1;
     dYear=1900;
 }
 
dateType(int month, int day, int year):dMonth(month),dDay(day),dYear(year){}

    void setDate(int day, int month, int year){
        dMonth=month;
        dDay=day;
        dYear=year;
    } 
    
    int getDay(){
        return dDay;
    }
    
    int getMonth(){
        return dMonth;
    }
    
    int getYear(){
        return dYear;
    }
    
    void printDate(){
        cout<<"Date is: "<<dDay<<"/"<<dMonth<<"/"<<dYear<<endl;
    }
  
};

class PersonType{
    public:
  string firstname;
  string lastname;

  PersonType(){}
  
  PersonType(string fname, string lname):firstname(fname),lastname(lname){}
  
  void setName(string fname, string lname){
      firstname=fname;
      lastname=lname;
  }
  
  string getFirst(){
      return firstname;
  }
  
  string getLast(){
      return lastname;
  }
  
  void printName(){
      cout<<"First Name: "<<firstname<<endl
          <<"Last Name: "<<lastname<<endl;
  }
    
};

class PersonalInfo{
    PersonType Name;
    dateType bday;
    int Id;
    
    public:

    PersonalInfo(string fname, string lname,int day, int month, int year){
        Name.firstname=fname;
        Name.lastname=lname;
        bday.dDay=day;
        bday.dMonth=month;
        bday.dYear=year;
    }
    
    void printPersonalInfo(){
        cout<<"Name: "<<Name.firstname<<" "<<Name.lastname<<endl;
        cout<<"DOB: ";
        bday.printDate();
    }
    
};

int main() {

    PersonalInfo P1("Waleed", "Afzal", 28,04,2004);
    P1.printPersonalInfo();
    

    return 0;
}