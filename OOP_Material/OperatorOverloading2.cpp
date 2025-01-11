//Overloading >> Operator (Cin Operator)

#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    string Name;
    int Id;

    void displayInfo()
    {
        cout << "Name: " << Name << endl
             << "Id: " << Id << endl;
    }
};

istream &operator>>(istream &get, Student &std)
{
    cout << "Enter Name: ";
    getline(get, std.Name);

    cout << "Enter ID: ";
    get >> std.Id;

    return get;
}

int main()
{
    Student std1;
    cin >> std1;
    std1.displayInfo();
    return 0;
}
