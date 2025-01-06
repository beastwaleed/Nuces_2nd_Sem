#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string genre;
    int availability_status;

public:
    Book() : title(""), author(""), genre(""), availability_status(0) {} // Default constructor

    // Setters
    void setTitle(const string& t) { title = t; }
    void setAuthor(const string& a) { author = a; }
    void setGenre(const string& g) { genre = g; }
    void setAvailability(int avail) { availability_status = avail; }

    // Getters
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getGenre() const { return genre; }
    int getAvailability() const { return availability_status; }
};

class Library {
private:
    int size;
    Book* books;

public:
    Library(int n) : size(n), books(new Book[n]) {} // Constructor for dynamic array

    ~Library() { delete[] books; } // Destructor

    void Input() {
        string t, a, g;
        int avail;
        char choice;
        cin.ignore(); // Clear input buffer
        cout << "\n\n=====Enter Book Information=====\n\n";
        do {
            for (int i = 0; i < size; i++) {
                cout << "Book No. " << i + 1 << endl;
                cout << "Enter Title: ";
                getline(cin, t);
                books[i].setTitle(t);
                cout << "Enter Author: ";
                getline(cin, a);
                books[i].setAuthor(a);
                cout << "Enter Genre: ";
                getline(cin, g);
                books[i].setGenre(g);
                cout << "Is the Book Available (1 for Yes, 0 for No): ";
                cin >> avail;
                books[i].setAvailability(avail);
                cout << "Book added successfully!" << endl;
            }
            cout << "Do You want to add another book? (y/n): ";
            cin >> choice;
        } while (choice != 'n');
    }
};

int main() {
    Library lib(2); // Creating a Library object with capacity for 2 books
    lib.Input(); // Input books

    return 0;
}
