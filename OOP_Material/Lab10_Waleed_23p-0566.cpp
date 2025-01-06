#include<iostream>
using namespace std;

class DOB{ //Dateof Birth Class
    int day;
    int month;
    int year;

    public:
    DOB(){ //default constructor
        day=0;
        month=0;
        year=0;
    }
    // DOB(int d, int m, int y):day(d),month(m),year(y){}

    void inputDOB(){ //Input Function for Date of Birht
        cout<<"--Date of Birth Information--\n";
        cout<<"Enter Date: ";
        cin>>day;
        cout<<"Enter Month: ";
        cin>>month;
        cout<<"Enter Year: ";
        cin>>year;
    }

    void displayDOB(){ //Display function of Date of Birth
        cout<<"Date of Birth: "<<day<<"/"<<month<<"/"<<year<<endl;
    }

};

class Contact { //Contact Class
    string contactName; 
    int contactNumber;
    string contactEmail;
    DOB D; //Object of DOB class to use it data member and Functions (Compostion)

public:
    static int count; //static count variable for counting contacts created
    static void Count(){ //static function for incrementing count
        count++;
    }
    Contact(){ //default constructor of Contact
        contactName=" ";
        contactNumber=0;
        contactEmail=" ";
    }
    // Contact(string n, int cn, string email, DOB d) : contactName(n), contactNumber(cn), contactEmail(email), D(d) {}
    
    void InputContact(){ //Input Fucntion for Contact Class
        cout<<"Enter Contact Name: ";
        cin.ignore();
        getline(cin,contactName);
        cout<<"Enter Contact Number: ";
        cin>>contactNumber;
        cout<<"Enter Contact Email: ";
        cin.ignore();
        getline(cin,contactEmail);
        D.inputDOB();
        Count(); //Count increments whenever object is created
    }

void displayContact(){ //display function for Contact Class
    cout<<"Contact Name: "<<contactName<<endl;
    cout<<"Contact Number: "<<contactNumber<<endl;
    cout<<"Contact Email: "<<contactEmail<<endl;
    D.displayDOB(); //calling DOB display function with its object (Used because of Composition)
}

};
int Contact::count=0; //setting static variable to zero

class ContactBook{ //Contact Book Class
    private:
    int size; //size variable for array
    Contact *contacts; //pointer object of Contact Class for using Dynamic Memory
public:
    ContactBook(int n):size(n),contacts(new Contact[n]) {} //Parameterized Constructor of ContactBook
    
    
    void InputCB(){ //Input function for Contact Function
        cout<<"\n====Enter Contacts Informations===="<<endl;
        for(int i=0;i<size;i++){ //Loop upto Size 
            cout<<"Contact No: "<<i+1<<endl;
            contacts[i].InputContact(); //calling Input function from Contact Class for every contact 
        }
    }
    
    void DisplayAll(){ //Display function of ContactBook
        cout<<"\n\n====Displaying All Contacts====\n\n";
        for(int i=0;i<Contact::count;i++){ //Loop upto Count of Object Created 
             cout<<"Contact No: "<<i+1<<endl;
            contacts[i].displayContact(); //Calling display function of contacts created
            cout<<endl;
        }
    }
    
    ~ContactBook(){ //Destructor
        delete[] contacts; //deleting dynamic array otherwise it will cause memory leak
    }
};


int main()
{
    int contactSize; //variable for taking size of array
    cout<<"\n~~~~Welcome to Contact Management Software~~~~\n\n";
cout<<"Enter Number of Contacts you want to Add: ";
cin>>contactSize;

ContactBook C(contactSize); //Object of ContactBook passing the value for size of array
C.InputCB(); //calling Input function from ContactBook with the help of Object
C.DisplayAll(); //calling Input function from ContactBook with the help of Object

    return 0;

}

