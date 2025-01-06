#include <iostream>
#include <string>
using namespace std;

const int size = 50; // global variable size for using in Arrays
const int maxBooks = 10;

class Book {
protected:
    string title;
    string author;
    string ISBN;
    int bookID;
    bool availabilityStatus;
    int day;
    int month;
    int year;

public:
    Book() {
        title = " ";
        author = " ";
        ISBN = " ";
        availabilityStatus = 0;
        bookID = -1;
        day = 0;
        month = 0;
        year = 0;
    }

    Book(string title, string author, string ISBN, bool availability, int Id, int day, int month, int year) {
        this->title = title;
        this->author = author;
        this->ISBN = ISBN;
        availabilityStatus = availability;
        this->day = day;
        this->month = month;
        this->year = year;
        bookID = Id;
    }

    // setters
    void setTitle() {
        cout << "===> Title: ";
        cin.ignore();
        getline(cin, title);
    }

    void setAuthor() {
        cout << "====> Author : ";
        cin.ignore();
        getline(cin, author);
    }

    void setISBN() {
        cout << "====> ISBN- ";
        cin.ignore();
        getline(cin, ISBN);
    }

    void setBookID() {
        cout << "====> Book ID:";
        cin >> bookID;
    }

    void setAvailability() {
        cout << "Is this Book Available (1 for yes/0 for no): ";
        cin >> availabilityStatus;
    }

    void setDate() {
        cout << "--Due Date--" << endl;
        do {
            cout << "====> Enter Day (1-31): ";
            cin >> day;

            if (day < 1 || day > 31) {
                cout << "Invalid Input for Date " << endl;
            }
        } while (day < 1 || day > 31);

        do {
            cout << "====> Enter Month(1-12): " ;
            cin >> month;

            if (month < 1 || month > 12) {
                cout << "Invalid Input for Month " << endl;
            }
        } while (month < 1 || month > 12);

        do {
            cout << "====> Enter Year: ";
            cin >> year;

            if (year < 2024) {
                cout << "Invalid Input" << endl;
            }
        } while (year < 2024);
    }

    // getters
    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    string getISBN() {
        return ISBN;
    }

    int getBookId() {
        return bookID;
    }

    bool getAvailability() {
        return availabilityStatus;
    }

    int getDay() {
        return day;
    }

    int getMonth() {
        return month;
    }

    int getYear() {
        return year;
    }

    ~Book() {
        // Destructor
    }

    void displayBook() {
        cout << "\n=====> Book Information <=====" << endl << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Book ID: " << bookID << endl;
        cout << "Availability: " << availabilityStatus << endl;
        cout << "Due Date: " << day << "/" << month << "/" << year << endl;
        cout << "----------------------------\n\n";
    }

};

class Author {
protected:
    string authorName;
    int authorBooks;
    string writtenBooks[maxBooks];

public:
    Author() {
        authorName = " ";
        authorBooks = 0;
    }
    Author(string name, int books) {
        authorName = name;
        authorBooks = books;
    }

    // setters
    void setAuthorName() {
        cout << "====> Enter Author Name: ";
        cin.ignore();
        getline(cin, authorName);
    }

    void setWrittenBooks() {
        cin.ignore();
        for (int i = 0; i < maxBooks; i++) {
            cout << "\n--Book No: " << i + 1 << endl;
            cout << "-->Enter Title: ";
            getline(cin, writtenBooks[i]);
        }
    }

    // getters
    string getAuthorName() {
        return authorName;
    }

    string getWrittenBooks() {
        return *writtenBooks;
    }

    void displayAuthorBooks() {
        cout << "Books written by " << authorName << ":" << endl;
        for (int i = 0; i < maxBooks; i++) {
            cout << "Book" << i + 1 << "." << writtenBooks[i] << endl;
        }
    }
    ~Author() {
        // Destructor of Author Class
    }
};

class LibraryMember {
protected:
    string memberName;
    string borrowedBooks[maxBooks];
    int lateFees;

public:
    LibraryMember() { // Default constructor
        memberName = " ";
        lateFees = 0;
    }

    // setters
    void setMemberName() {
        cout << "====> Enter Member Name: ";
        cin >> memberName;
    }

    void setLateFees() {
        cout << "====> Enter Late Fee: ";
        cin >> lateFees;
    }

    // getters
    string getMemberName() {
        return memberName;
    }

    int getFee() {
        return lateFees;
    }

    string getBorrowedBooks() {
        return *borrowedBooks;
    }

};

class Librarian {
protected:
    string librarianName;
    bool adminAccess;

public:
    Librarian() {
        librarianName = " ";
        adminAccess = false; // By default, set to false
    }

    // setters
    void setLibrarianName() {
        cout << "====> Enter Librarian Name: ";
        cin >> librarianName;
    }

    void setAdminAccess() {
        cout << "====> Is Librarian Allow to Access: ";
        cin >> adminAccess;
    }

    // getters
    string getLibraryName() {
        return librarianName;
    }

    bool getAdminAccess() {
        return adminAccess;
    }

    void displayLibrarianInfo() {
        cout << "Librarian Name: " << librarianName << endl;
        cout << "Admin Access: " << adminAccess << endl;
    }
};

class Library {
    // Aggregation
    Book* books;
    Author* authors;
    LibraryMember* members;

    // Composition
    Librarian administrator;

    const int spaceInLibrary = 60;
    int bookCounts;
    int MemberCounts;
    int authorCounts;

public:
    Library() {
        bookCounts = 0;
        authorCounts = 0;
        MemberCounts = 0;
        books = new Book[spaceInLibrary];
        authors = new Author[spaceInLibrary];
        members = new LibraryMember[spaceInLibrary];
    }

    void addBook() {
        // Checking empty element in array after removing book from that element
        for (int i = 0; i < spaceInLibrary; i++) {
            if (books[i].getTitle() == " ") {
                bookCounts = i;
                break;
            }
        }

        cout << "\n================\n";
        cout << " ====> Book " << bookCounts + 1 << "<====" << endl;
        cout << "================\n";

        books[bookCounts].setTitle();
        books[bookCounts].setAuthor();
        books[bookCounts].setBookID();
        books[bookCounts].setISBN();
        books[bookCounts].setDate();
        books[bookCounts].setAvailability();

        bookCounts++; // Incrementing book count for every time this book function is used
    }

    void addAuthor() {
        for (int i = 0; i < spaceInLibrary; i++) {
            if (authors[i].getAuthorName() == " ")
                authorCounts = i;
            break;
        }

        cout << "\n================\n";
        cout << " ====> Author " << authorCounts + 1 << "<====" << endl;
        cout << "================\n";

        authors[authorCounts].setAuthorName();
        authors[authorCounts].setWrittenBooks();

        authorCounts++;
    }

    void newMemberAdd() {
        for (int i = 0; i < spaceInLibrary; i++) {
            if (members[i].getMemberName() == " ") {
                MemberCounts = i;
                break; // Break the loop
            }
        }

        cout << "\n================\n";
        cout << " ====> Member " << MemberCounts + 1 << "<====" << endl;
        cout << "================\n";

        members[MemberCounts].setMemberName();
        MemberCounts++;
    }

    void displayAllBooks() {
        cout << "\n=== Displaying All Books ===\n";
        for (int i = 0; i < bookCounts; i++) {
            books[i].displayBook();
        }
        cout << "===========================\n\n";
    }

    void displayAllAuthors() {
        cout << "\n=== Displaying All Authors ===\n";
        for (int i = 0; i < authorCounts; i++) {
            cout << "Author Name: " << authors[i].getAuthorName() << endl;
            authors[i].displayAuthorBooks();
        }
        cout << "=============================\n\n";
    }

    void displayAllLibraryMembers() {
        cout << "\n=== Displaying All Library Members ===\n";
        for (int i = 0; i < MemberCounts; i++) {
            cout << "Member Name: " << members[i].getMemberName() << endl;
        }
        cout << "======================================\n\n";
    }

    void RemoveBooks(int bookID){
        for (int i = 0; i < bookCounts; i++) {
        if (books[i].getBookId() == bookID) {
            // Shift books to fill the gap
            for (int j = i; j < bookCounts - 1; j++) {
                books[j] = books[j + 1];
            }
            bookCounts--;
            cout << "Book removed successfully\n";
            return;
        }
    }
    cout << "Book not found\n";
}

    void RemoveAuthors(string &authorName) {
        for (int i = 0; i < authorCounts; i++) {
        if (authors[i].getAuthorName() == authorName) {
            // Shift authors to fill the gap
            for (int j = i; j < authorCounts - 1; j++) {
                authors[j] = authors[j + 1];
            }
            authorCounts--;
            cout << "Author removed successfully\n";
            return;
        }
    }
    cout << "Author not found\n";
    }

    void registerNewLibraryMembers() {
        cout << "\n===== Register New Library Member =====\n";
    // Check if there is space to add a new member
        if(MemberCounts<spaceInLibrary){
        members[MemberCounts].setMemberName();
        cout<<"New library member registered suceesfully\n";
        MemberCounts++; // Increment the member count
        } 
    else{
    cout << "Library member registration failed. Library is full.\n";
    }
    }

    void viewLateFeeOfLibraryMembers() {
       cout << "\n=== Viewing Late Fee of Library Members ===\n";
        for (int i = 0; i < MemberCounts; i++) {
        cout << "Member Name: " << members[i].getMemberName() << endl;
        cout << "Late Fee: $" << members[i].getFee() << endl;
    }
    cout << "==========================================\n\n";
}

void searchBooksByTitle(string title) {
        cout << "\n=== Searching Books by Title ===\n";
        bool found = false;
        for (int i = 0; i < bookCounts; i++) {
            if (books[i].getTitle() == title) {
                books[i].displayBook();
                found = true;
            }
        }
        if (!found) {
            cout << "--> Book with Title \"" << title << "\" not found.\n";
        }
        cout << "==============================\n\n";
    }

    void searchBooksByAuthor(string author) {
        cout << "\n=== Searching Books by Author ===\n";
        bool found = false;
        for (int i = 0; i < bookCounts; i++) {
            if (books[i].getAuthor() == author) {
                books[i].displayBook();
                found = true;
            }
        }
        if (!found) {
            cout << "--> No books found for Author \"" << author << "\".\n";
        }
        cout << "===============================\n\n";
    }

    ~Library(){
        delete[] books, members, authors;
    }

    friend void returnBooks(Library&); // Declaring friend function to return books
    friend void borrowBooks(Library&); // Declaring friend function to borrow books
};

void borrowBooks(Library &borrowbook) {
    int bookID;
    cout << "Enter the Book ID to borrow: ";
    cin >> bookID;

    bool found = false;
    for (int i = 0; i < borrowbook.bookCounts; i++) {
        if (borrowbook.books[i].getBookId() == bookID && borrowbook.books[i].getAvailability()) {
            borrowbook.books[i].setAvailability(); 
            borrowbook.members[0].getBorrowedBooks() = borrowbook.books[i].getTitle(); // Assign borrowed book to member
            found = true;
            cout << "Book borrowed successfully\n";
            break;
        }
    }
    if (!found) {
        cout << "Book not available for borrowing or Book ID not found\n";
    }
}


void returnBooks(Library &library) {
     int bookID;
    cout << "Enter the Book ID to return: ";
    cin >> bookID;

   // library.RemoveBooks(bookID); // Call the RemoveBooks function to remove the book from the library
    cout << "Book returned successfully\n";
}



int main() {

    Library FastUni;
    char menu;
    string removeAuthor;
    string searchTitle;
    string searchAuthor;

    cout << "===== Library Management ==== \n" << endl;

    do {
        cout << "~~~~~MENU~~~~~" << endl;
        cout << "1. Administrator" << endl;
        cout << "2. Member" << endl;
        cout << "3. Exit " << endl;
        cout << " Enter Your Choice: ";
        cin >> menu;

        switch (menu) {
        case '1':
            cout << "----ADMINISTRATION SECTION----\n" << endl;
            cout << "1. Add a Book"
                << "\n2. Add an Author"
                << "\n3. Register New Library Member"
                << "\n4. Display All Books"
                << "\n5. Display All Authors"
                << "\n6. Display All Library Members"
                << "\n7. Add or Remove Books from Library"
                << "\n8. Add or Remove Authors from Library"
                << "\n9. Register New Library Members"
                << "\n10. View Late Fee of Library Members"
                << "\n11. Exit Administration Section\n";
            int adminChoice;
            cin >> adminChoice;
            switch(adminChoice) {
            case 1:
                FastUni.addBook();
                break;
            case 2:
                FastUni.addAuthor();
                break;
            case 3:
                FastUni.newMemberAdd();
                break;
            case 4:
                FastUni.displayAllBooks();
                break;
            case 5:
                FastUni.displayAllAuthors();
                break;
            case 6:
                FastUni.displayAllLibraryMembers();
                break;
            case 7:
                int removebook;
                cout<<"Enter Book ID to remove: ";
                cin>>removebook;
                FastUni.RemoveBooks(removebook);
                break;
            case 8:
                cout<<"Enter Author to Remove: ";
                cin.ignore();
                getline(cin,removeAuthor);
                FastUni.RemoveAuthors(removeAuthor);
                break;
            case 9:
                FastUni.newMemberAdd();
                break;
            case 10:
                FastUni.viewLateFeeOfLibraryMembers();
                break;
            case 11:
                cout << "Exiting Administration Section\n";
                break;
            default:
                cout << "Invalid Input\n";
                break;
            }
            break;

       case '2':
        cout << "------MEMBERS SECTION------\n";
        cout << "1. Search for Books by Title\n"
         << "2. Search for Books by Author\n"
         << "3. Borrow a Book\n"
         << "4. Return a Book\n"
         << "5. Exit Member Section\n"
         << "6. Enter Your Choice";
            int memberChoice;
            cin >> memberChoice;
            switch (memberChoice) {
            case 1:
                cout<<"Enter Book Title to Search: ";
                cin.ignore();
                getline(cin,searchTitle);
                FastUni.searchBooksByTitle(searchTitle);
                break;
            case 2:
                cout<<"Enter Author Name to Search: ";
                cin.ignore();
                getline(cin,searchAuthor);
                FastUni.searchBooksByAuthor(searchAuthor);
                break;
            case 3:
                borrowBooks(FastUni);
                break;
            case 4:
               returnBooks(FastUni);
                break;
            case 5:
                cout << "Exiting Member Section\n";
                break;
            default:
                cout << "Invalid Input\n";
                break;
            }
            break;


        case '3':
            cout << "Exiting the Program\n\n";
            break;

        default:
            cout << "Invalid Input\n";
        }
    } while (menu != '3');
    return 0;
}
