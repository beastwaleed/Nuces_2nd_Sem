#include<iostream>
#include<string>
using namespace std;

class Book{ //Book Class 
    private:
    //data members
    string title; 
    string author;
    string genre;
    bool availability_status; //bool for 1/0 (yes/no)

    public:
    Book(){ //default constructor
        title=" ";
        author=" ";
        genre=" ";
        availability_status=0;
    }
        //parametrized constructor
    Book(string &title, string &author, string &genre, bool availability){
        this->title=title; 
        this->author=author;
        this->genre=genre;
        this->availability_status=availability;
    }

        //setters
   void setTitle(string title){
    this->title=title;
   }

    void setAuthor(string author){
        this->author=author;
    }

    void setGenre(string genre){
        this->genre=genre;
    }

    void setAvailability(bool Available){
        availability_status=Available;
    }

        //getters
    string getTitle(){
        return title;
    }

    string getAuthor(){
        return author;
    }

    string getGenre(){
        return genre;
    }

    bool getAvailability(){
        return availability_status;
    }

};

class Library{ //Library Class
    private:
    //data members
    int size; //size of the array
    Book **books; //making dynamic 2d array of pointer for books 

    public:
     static int countBook; 
     static void Count(){
        countBook++;
    }

    Library(int n):size(n),books(new Book*[n]) {} //intializing dynamic array using constructor

    ~Library(){ //destructor
        for(int i=0;i<countBook;i++){ 
            delete books[i]; //deleting dynamic array of books one by one
        }
        delete[] books; //now deleting the book object 
    }

        //function to add books in library
    void InputBooks(string bTitle, string bAuthor, string bGenre, bool bAvaialble){
       
       if(countBook>=size){ //checking if the library limit is reached or not
        cout<<"Library Capacity Reached, You cannot add More Books"<<endl;
        return; //exiting from the function
       }

        else{ //if limit is not reached
        //adding a new book object to the array dynamically
            books[countBook++]= new Book(bTitle,bAuthor, bGenre,bAvaialble); 
            cout<<"Book is Added in Library Succesfully"<<endl;
        }
    }

        // function to display all book of specific genre 
    void displayAllBookGenre(string userGenre){ //taking genre as parameter
        int availableCounter=0; //setting a counter for avaialbe book as zero
        for(int i=0;i<countBook;i++){ //loop till total books added

    //checking if genre user searched is available and if the book is avaiable for calling getter functions
            if(books[i]->getGenre()== userGenre && books[i]->getAvailability()){        
                cout<<"\nAvaiable Books in Genre : "<<userGenre<<" are"<<endl;
                cout<<"-------------------\nTitle: "<<books[i]->getTitle()<<endl;
                cout<<"Author: "<<books[i]->getAuthor()<<endl;
                availableCounter++; //incrementing counter for if else conditions
                cout<<"--------------------------------"<<endl;
            }
        }

        if(availableCounter==0){ //if counter =0 means book is not avaialble
            cout<<"Sorry No Books Available in this Genre: "<<userGenre<<endl;
            cout<<"-------------------------------------------------"<<endl;

        }
    }

};

int Library::countBook=0; //static variable

int main()
{
    Library Lib(50); //creating library object with 50 size
    string userTitle, userAuthor, userGenre, searchingGenre; //variables for user inputs
    bool userAvailability; //variable for availability
    char choice; 

    do{ //loop for adding books
    cout<<"Enter Title: ";
    getline(cin,userTitle);
    // cin.ignore();
    cout<< "Enter Author: ";
    getline(cin,userAuthor);
    cout<<"Enter Genre: ";
    getline(cin,userGenre);
    cout<<"Is book avaialble (1 for yes/0 for no): ";
    cin>>userAvailability;

//adding book to library, passing parameters to library inputBook function
    Lib.InputBooks(userTitle,userAuthor,userGenre,userAvailability); 
        
    cout<<"Do you want to add another book(y/n): ";
    cin>>choice;
    cin.ignore(); //function to ignore new line , otherwise will cause errors in input for adding more than one book
    }   //while loop until choice is 'n'
    while(choice!='n');
        
        //asking user to enter genre to search its available books
    cout<<"Enter the Genre to Display Available Books : "; 
    getline(cin,searchingGenre);
    
   //passing genre parameter to "displayAllBookGenre" function of library class
    Lib.displayAllBookGenre(searchingGenre); 
    return 0;
}