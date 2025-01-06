#include<iostream>
#include<string>
using namespace std;

const int size=50; //global variable size for using in Arrays
const int booksLimit=10; //global variable for using in Books Arrays/loops

class Book{  //Book class
protected:
string title; //data members
string author;
string ISBN;
int bookID;
bool availabilityStatus;
int day;
int month;
int year;

public:
    Book(){ //default constructor
        title=" ";
        author=" ";
        ISBN= " ";
        availabilityStatus=0;
        bookID=-1;
        day=0;
        month=0;
        year=0;
    }

    //parametrized constructor
    Book(string title,string author, string ISBN, bool avalibilty,int Id, int day, int month, int year){
        this->title=title;
        this->author=author;
        this->ISBN=ISBN;
        availabilityStatus=avalibilty;
        this->day=day;
        this->month=month;
        this->year=year;
        bookID=Id;
    }

    //setters
    void setTitle(){
        cout<<"===> Title: ";
        cin.ignore();
        getline(cin,title);
    }

    void setAuthor(){
        cout<<"====> Author: ";
       // cin.ignore();
        getline(cin,author);
    }

    void setISBN(){
        cout<<"====> ISBN: ";
        cin.ignore();
        getline(cin,ISBN);
    }

    void setBookID(){
        cout<<"====> Book ID: ";
        cin>>bookID;
    }

    void setAvailability(){
        cout<<"Is this Book Available (1 for yes/0 for no): ";
        cin>>availabilityStatus; 
    }

    void setDate(){ //setter for date
        cout<<"--Due Date--"<<endl;
        do{
            cout<<"====> Enter Day (1-31): ";
            cin>>day;

            if(day<1 || day > 31){ //logic for handling invalid inputs
                cout<<"Invalid Input for Date "<<endl;
            }
        }

        while(day<1 || day>31);

        do{
            cout<<"====> Enter Month: (1-12): ";
            cin>>month;

            if(month<1 || month >12){ //logic for handling invalid inputs
                cout<<"Invalid Input for Month "<<endl;
            }

        }  

        while(month<1 || month>12);     

        do{
            cout<<"====> Enter Year: ";
            cin>>year;

            if(year<2024){ //logic for handling invalid inputs
                cout<<"Invalid Input"<<endl;
            }
        }
        while(year<2024); 
    }

    //getters
    string getTitle(){
        return title;
    }

    string getAuthor(){
        return author;
    }

    string getISBN(){
        return ISBN;
    }

    int getBookId(){
        return bookID;
    }

    bool getAvalability(){
        return availabilityStatus;
    }

    int getDay(){
        return day;
    }

    int getMonth(){
        return month;
    }

    int getYear(){
        return year;
    }

    ~Book(){
        //Destructor
    }

    void displayBook(){ //display function for book info
        cout<<"\n=====> Book Information <====="<<endl<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"ISBN: "<<ISBN<<endl;
        cout<<"Book ID: "<<bookID<<endl;
        cout<<"Availability: "<<availabilityStatus<<endl;
        cout<<"Due Date: "<<day<<"/"<<month<<"/"<<year<<endl;
        cout<<"----------------------------\n\n";
    }

};

class Author{ //Author Class
    protected:
        string authorName;
        int authorBooks;
        string writtenBooks[booksLimit]; //array for books written by author

    public:
        Author(){ //default constructor
            authorName=" ";
            authorBooks=0;
        }
        Author(string name, int books){ //parametrizd constructor
            authorName=name;
            authorBooks=books;
        }

        //setters
        void setAuthorName(){
          cout<<"====> Enter Author Name: ";
          cin.ignore(); //ignore input buffer
          getline(cin,authorName);
        }

        void setWrittenBooks(){
            cin.ignore();
            char choiceMore;

            for(int i=0;i<booksLimit;i++){ //loop for adding books written by specific author
                cout<<"\n--Book No: "<<i+1<<endl;
                cout<<"-->Enter Title: ";
                getline(cin,writtenBooks[i]);
            
            }

            do{ //asking if want to add more book of same author
                cout<<"DO You want to Add more Book [y/n]: ";
                cin>>choiceMore;

                if(choiceMore!='n' && choiceMore!='N' && choiceMore!= 'y' && choiceMore !='Y'){
                    cout<<"Invalid Input Enter [y for yes/n for no]\n";
                }

            }
            while(choiceMore!='n' || choiceMore!='N');
        }

        //getters;
        string getAuthorName(){
            return authorName;
        }

        string getWrittenBooks(){ //
            return *writtenBooks;
        }

        // void AuthorBooks(Book book,int index){
        //     if(index>=0 && index<size){
        //         writtenBooks[index]=book;
        //     }
        // }

        void displayAuthorBooks(){
            cout<<"Books written by "<<authorName<<":"<<endl;
            for(int i=0;i<booksLimit;i++){
                cout<<"Book"<<i+1<<"."<<writtenBooks[i]<<endl;
            }
        }
        ~Author(){
           //Destructor of Author Class
        }
};

class LibraryMember{
    protected:
    string memberName;
   string borrowedBooks[booksLimit];
    int lateFees;
    
    public:
    LibraryMember(){ //default constructor
        memberName=" ";
      //  borrowedBooks[size]={0};
        lateFees=0;
    }

    // LibraryMember(string name, int fee){ //borrowed books to be set
    //     string memberName=name;
    //     for(int i=0;i<size;i++){
    //         borrowedBooks[i]=-1;
    //     }
    //     lateFees=fee;
    // }

    //setter
    void setMemberName(){
        cout<<"====> Enter Member Name: ";
        cin.ignore();
        getline(cin,memberName);
    }

    void setLateFees(){
        cout<<"====> Enter Late Fee: ";
        cin>>lateFees;
    }

    //getter
    string getMemberName(){
        return memberName;
    }


    int getFee(){
        return lateFees;
    }

    string getBorrowedBooks(){
        return *borrowedBooks;
    }

     
    /*
     void borrowBooks(Book &book, int bookID){
        if(book.getAvalability()==true && bookID==book.getBookId()){
             int index=0;
             while(borrowedBooks[index]!=-1 && index < size){
                 index++;
             }
            if(index>size){
         borrowedBooks[index]=bookID;
        
                 book.setAvailability()=false;
                 cout<<"Book Borrowed Succesfully. "<<endl;
             }
             else{
                 cout<<"Maximum Limit Reached for Borrowing"<<endl;
             }
         }
         else{
             cout<<"Book is not Available for Borrowing "<<endl;
         }
     }*/


};

class Librarian{
    protected:
    string librarianName;
    bool adminAccess;


    public:
        Librarian(){
            librarianName=" ";
            adminAccess=false; //by default it is set to false
        }

    //setters
    void setLibrarianName(){
       cout<<"====> Enter Librarian Name: ";
       cin>>librarianName;
    }

    void setAdminAccess(){
        cout<<"====> Is Librarian Allow to Access: ";
        cin>>adminAccess;
    }

    //getters
    string getLibraryName(){
        return librarianName;
    }

    bool getAdminAccess(){
        return adminAccess;
    }

    void displayLibrarianInfo(){
        cout<<"Librarian Name: "<<librarianName<<endl;
        cout<<"Admin Access: "<<adminAccess<<endl;
    }
};

class Library{

    //Compostion
    Librarian administrator;
    
    //Aggregation
    Book *books;
    Author *authors;
    LibraryMember *members;


    int const spaceInLibrary=60;
    int bookCounts;
    int memberCounts;
    int authorCounts;
    friend void returnBooks(Library &); //Declaring friend function to retturn books
    friend void borrowBooks(Library &);// Declaring friend functoin to borrow books
   
    public:

    Library(){ //default constructor
        bookCounts=0;
        authorCounts=0;
        memberCounts=0;
        books= new Book[spaceInLibrary];
        authors= new Author[spaceInLibrary];
        members= new LibraryMember [spaceInLibrary];
    }

    //function for adding book in the library
    void addBook(){
    //Checking emplty element in array after removing book from that element
        for(int i=0;i<spaceInLibrary;i++){
            if(books[i].getTitle()==" "){//setting book title to empty
                bookCounts=i;
                break;
            }
        }

        cout<<"\n================\n";
        cout<<" ====> Book "<<bookCounts +1 <<"<===="<<endl;
        cout<<"================\n";

        //taking all information of book from librarian;
        books[bookCounts].setTitle();
        books[bookCounts].setAuthor();
        books[bookCounts].setBookID();
        books[bookCounts].setISBN();
        books[bookCounts].setAvailability();
        books[bookCounts].setDate();

        bookCounts++; //incrementing book count for every time this book function is used

    }

    //function to add author in the library
    void addAuthor(){
        for(int i=0; i< spaceInLibrary;i++){
            if(authors[i].getAuthorName()==" "); //setting all author to be default and free space
            authorCounts=i;
            break;
        }

        cout<<"\n================\n";
        cout<<" ====> Author "<<authorCounts +1 <<"<===="<<endl;
        cout<<"================\n";

        //taking all information of author from librarian
        authors[authorCounts].setAuthorName(); 
        authors[authorCounts].setWrittenBooks();
        authorCounts++; //inrementing authorcount to add new author
    }

    //function for adding new member for library
    void newMemberAdd(){
        for(int i=0;i<spaceInLibrary;i++){
            if(members[i].getMemberName()==" "){ //setting all array to be free/deleting garbage value
            memberCounts=i;
            break; //breakk the loop
            }
        }

        cout<<"\n================\n";
        cout<<" ====> Member "<<memberCounts +1 <<"<===="<<endl;
        cout<<"================\n";

        //taking information about member from librarian 
        members[memberCounts].setMemberName();
        memberCounts++;
    }

    //function for displying all books
    void displayAllBooks(){
        cout<<"\n=== Displaying All Books ===\n";
       
        for(int i=0;i<bookCounts;i++){ //loop for books
       
        books[i].displayBook(); //calling the display function from book class
       
        }
        cout<< "===========================\n\n";
    }

    //function for displaying all authors
    void displayAllAuthors(){
        cout<< "\n=== Displaying All Authors ===\n";
        for(int i=0;i<authorCounts;i++){//loop till authorcount
       
        cout<<"===> Author Name: "<<authors[i].getAuthorName() << endl; //calling author name function
            authors[i].displayAuthorBooks(); //calling author dispplay book function from author class
       
        }
       
        cout << "=============================\n\n";
    }

    //function for displaying all library members
    void displayAllMembers() {
        cout<< "\n=== Displaying All Library Members ===\n";
       
        for(int i=0;i<memberCounts;i++){//loop till member count
            cout<<"Member Name: "<<members[i].getMemberName()<<endl; //calling getter for name of librarymember class
        }
       
        cout<<"======================================\n\n";
    }

        //function for removing book
    void removeBooks(int bookID){//taking book Id as a parameter
       
        for(int i=0;i<bookCounts;i++){
        if(books[i].getBookId()==bookID){
            // Shift books to fill the gap
            
            for(int j=i;j<bookCounts-1;j++) {
                books[j]=books[j+1];
            }

            bookCounts--;
            cout << "Book removed succeessfully\n";
            return;
        }
    }
    }

    void returnBook(int bookID){
        for(int i=0;i<bookCounts;i++){
        if(books[i].getBookId() == bookID){
            // Shift books to fill the gap
            
            for(int j=i;j<bookCounts-1;j++) {
                books[j]=books[j+1];
            }

            bookCounts--;
            cout<<"Book Returned succeessfully\n";
            return;
        }

    }
    //else book not found for that ID
    cout<<"Book not found\n";
}

        //function for removing author
    void RemoveAuthors(string &authorName){ //passing address of authorname from main
        for (int i=0;i<authorCounts;i++){
        if (authors[i].getAuthorName()== authorName){//searching author with that name
            
            for (int j=i;j<authorCounts-1;j++){
                authors[j]= authors[j+1];// Shift authors to fill the gap and make space
            }

            authorCounts--; //decremment the count for removing author
            cout<< "Author removed successfully\n";
            return;
        }
    }
    //else author not found with that name
    cout << "Author not found\n";
    }

    //function for displaying member late fees
    void viewLateFeeOfMembers(){
       cout << "\n=== Viewing Late Fee of Library Members ===\n";
        
        for(int i=0;i<memberCounts; i++){ //loop till total members
        cout<<"Member Name: "<<members[i].getMemberName()<<endl; //calling member name through getter
        cout<<"Late Fee: $" <<members[i].getFee()<<endl; //calling member late fee through getter
    }
    
    cout << "==========================================\n\n";

    }

        //function for displaying books with searching title
    void searchBooksByTitle(string title){ //passing title as a parameter
        cout << "\n=== Searching Books by Title ===\n";
        bool found = false; //be default setting found to false
        for (int i=0;i<bookCounts;i++){ //loop till total books added
            if (books[i].getTitle()==title){ //checking if title matches with any of the stored book
                books[i].displayBook(); //if yes then printing the book info through display fucntion
                found=true; //setting found = true
            }
        }
        if(found==false){ //if found = false then
            cout << "--> Book with Title \""<<title<<"\" not found.\n";
        }

        cout << "==============================\n\n";
    }

    //function for displaying book by author name
    void searchBooksByAuthor(string author){ //passing author name as parramter
        cout<<"\n=== Searching Books by Author ===\n";

        bool found=false; //by deafault set to false
        
        for(int i=0;i<bookCounts;i++){//loop till books added
        
            if (books[i].getAuthor()==author){//checking if passed author name matches with any of the author name
                books[i].displayBook(); //if yes then displaying that book
                found=true;//setting found = true;
            }
        
        }
        
        if(found==false){ //else condition
            cout<<"--> No books found for Author \"" <<author<<"\".\n";
        }
        cout<<"===============================\n\n";
    }

        //destructor
        ~Library(){
            //deleting all array to free the run time memory  
            delete[] books, members, authors;
        }

};

//friend function defintion of borrowing book
void borrowBooks(Library &borrowbook){ //passing object address as parameter
    int bookID; //varibale for storing book Id
    cout<<"Enter the Book ID to borrow: ";
    cin>>bookID;

    bool found=false; //by default set to false
    for (int i=0;i<borrowbook.bookCounts;i++){//loop till total book added, through object 

//if object's given book id matches to any book in the array and is available to borrow
        if(borrowbook.books[i].getBookId()==bookID && borrowbook.books[i].getAvalability()){
          
          borrowbook.books[i].setAvailability(); //checking if book is available
          borrowbook.members[0].getBorrowedBooks()=borrowbook.books[i].getTitle(); // Assign borrowed book to member
            
            found=true;//making found = true
            cout<<"Book borrowed successfully\n";
            
            break;
        }
    }
    if(found==false){ //else condition
        cout<<"Book not available for borrowing or Book ID not found\n";
    }
}

//definition of friend function ReturnBooks
void returnBooks(Library &returnBooks){ //passing object of Library class as arguments
    int bookID;
    cout<<"Enter the Book ID to return: ";
    cin>>bookID;
  
  returnBooks.returnBook(bookID);//calling the returnbook function from library class for returning book
   
}

int main(){

        //objects 
    Library FastUni;
    int day,month,year;
    char menu,option;
    int adminMenu,memberMenu;
    string searchTitle;
    string searchAuthor;
    string removeAuthor;

    cout<<"===== Library Management ==== \n"<<endl;

    do{ //do-while loop for menu 
            //Main Menu
        cout<<"~~~~~MENU~~~~~"<<endl;
        cout<<"1. Administrator"<<endl;
        cout<<"2. Member"<<endl;
        cout<<"3. Exit "<<endl;
        cout<<" Enter Your Choice: ";
        cin>>menu;

        switch(menu){
            case '1': //Option1 
            cout<<"----ADMINISTRATION SECTION----\n"<<endl;
            cout<<"\n1. Add a Book" 
            <<"\n2. Add an Author"
            <<"\n3. Register New Library Member"
            <<"\n4. Display All Books"
            <<"\n5. Display all Auhthors"
            <<"\n6. Dispay all Library Members"
            <<"\n7. Remove Books from Library"
            <<"\n8. Remove Authors from Library"
            <<"\n9. Register New Library Members"
            <<"\n10. View Late Fee of Library Members"
            <<"\n11. Back to Main Menu\n"; 
            cin>>adminMenu;
            switch(adminMenu){
            case 1:
            FastUni.addBook(); //calling addbook function from library class
                break;
            case 2:
            FastUni.addAuthor(); //calling add author function from library class
            break;

            case 3:
            FastUni.newMemberAdd(); //calling new member add function from library class
            break;

            case 4:
            FastUni.displayAllBooks(); //calling display all books function from library class
            break;

            case 5:
            FastUni.displayAllAuthors(); //calling display all authors function from library class

            case 6:
            FastUni.displayAllMembers(); //calling display all library member function from library class
            break;

            case 7:
            int removeBook;
            cout<<"Enter Book ID to remove: ";
            cin>>removeBook;
            FastUni.removeBooks(removeBook); //calling removebook function with passing argument of bookID
            break;

            case 8:
            cout<<"Enter Author to Remove: ";
            cin.ignore();
            getline(cin,removeAuthor);
           FastUni.RemoveAuthors(removeAuthor); //calling rmoveauthor function with passing argument of author name
                break;

    
            case 9:
            FastUni.newMemberAdd(); //calling new member add function from library class
            break;

            case 10:
            FastUni.viewLateFeeOfMembers(); //calling late fee function from library class
            break;

            case 11: //exit Administration menu
            cout<<"======Exiting Administration Section======\n"; 
            break;
        
            default:
            cout<<"Invalid Input\n";
                break;
            }

            break;

        //case 2 of main menu start here
        case '2': //Option2
            cout<<"------MEMBERS SECTIONS------\n";
            cout<<"\n12. Search for Books by Title"
            <<"\n13. Search books by Author"
            <<"\n14. Allow a library member to borrow a book"
            <<"\n15. Alow a library member to return a book"
            <<"\n16. Exit the Members Section ";
            cout<<"Enter Your Choice: ";
            cin>>memberMenu;


            switch(memberMenu){
                case 12:
                cout<<"Enter Book Title to Search: "; 
                cin.ignore();
                getline(cin,searchTitle);
                FastUni.searchBooksByTitle(searchTitle); //calling searchbookbytitle function and passing argument of book name; 
                break;

                case 13:
                cout<<"Enter Author Name to Search: ";
                cin.ignore();
                getline(cin,searchAuthor);
                FastUni.searchBooksByAuthor(searchAuthor);  //calling searchbookbyauthor and passing argument of author name
                break;

                case 14:
                borrowBooks(FastUni); //calling friend function borrow books with passing object
                break;

                case 15:
                returnBooks(FastUni); //calling friend function return books with passing object
                break;
                
                case 16:
                cout<<"Exiting Member Section\n"; //exiting member menu
                break;

                default:
                cout<<"Invalid Input\n";
            }
            break;     

       case '3': //Option3
           cout<<"Exiting the Program\n\n"; //Exiting the Whole Program
           break;
        
        default:
        cout<<"Invalid Input\n";
    }
    }
    while(menu!='3'); //while condition to exit the loop
    return 0;
}