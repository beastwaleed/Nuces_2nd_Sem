#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

const int size=10;

class User
{
private:
    string username;
    string password;

public:
    User(const string &user, const string &pass) : username(user), password(pass) {}

    string &getUsername()
    {
        return username;
    }
    string &getPassword()
    {
        return password;
    }

    friend class FinancialReport;
};

class IncomeManager
{
private:
    double totalIncome;

public:
    IncomeManager() : totalIncome(0.0) {}

    void addIncome(double amount)
    {
        totalIncome += amount;
        cout << "\nIncome added successfully!";
    }

    double getTotalIncome() const { return totalIncome; }
};

class ExpenseManager
{
private:
    double totalExpense;

public:
    ExpenseManager() : totalExpense(0.0) {}

    void addExpense(double amount)
    {
        totalExpense += amount;
        cout << "\nExpense added successfully!";
    }

    double getTotalExpense() const { return totalExpense; }
};

class FinancialReport
{
public:
    static void generateReport(IncomeManager &incomeManager, ExpenseManager &expenseManager){
        cout << "\n-----Financial Report-----";
        cout << "\nTotal Income: $" << incomeManager.getTotalIncome();
        cout << "\nTotal Expense: $" << expenseManager.getTotalExpense();
        cout << "\nNet Income: $" << incomeManager.getTotalIncome() - expenseManager.getTotalExpense();

    }
};

int main()
{
    User **users = new User *[size]; // Dynamically allocate array of User pointers
    IncomeManager incomeManager;
    ExpenseManager expenseManager;

    char menu_choice;
    string username, password;
    double amount;

    bool usernameAvailable = true;

    do
    {
        cout << "\n\n=======LOGIN/REGISTER=======";
        cout << "\n1. Sign In";
        cout << "\n2. Sign Up";
        cout << "\n3. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> menu_choice;

        switch (menu_choice)
        {
        case '1':
            cout << "\nEnter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;
            for (int i = 0;i<size; i++)
            {
                if (users[i]!=nullptr && users[i]->getUsername()==username && users[i]->getPassword()==password)
                {
                    cout<< "\nSign in successful!";
                    break;
                }
            }
            if (users[size-1] != nullptr) //limit reached
            {
                cout << "\nError: User limit reached. Please try again later.";
                break;
            }
            cout << "\nError: User not found. Please sign up first.";
            break;
        case '2':
            cout << "\nEnter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            usernameAvailable = true;
            for (int i = 0; i < size; ++i)
            {
                if (users[i] != nullptr && users[i]->getUsername() == username)
                {
                    usernameAvailable = false;
                    break;
                }
            }
            if (usernameAvailable)
            {
                for (int i = 0; i < size; ++i)
                {
                    if (users[i] == nullptr)
                    {
                        users[i] = new User(username, password);
                        cout << "\nSign up successful!";
                        break;
                    }
                }
            }
            else
            {
                cout << "\nError: Username already exists. Please choose another username.";
            }
            break;
        case '3':
            cout << "\nExiting...";
            break;
        default:
            cout << "\nInvalid choice!";
        }

        if (users[9] != nullptr)
        {
            cout << "\nError: User limit reached. Please try again later.";
            break;
        }

        do
        {
            if (users[0] != nullptr)
            {
                cout << "\n\n-----User Menu-----";
                cout << "\na. Add Income";
                cout << "\nb. Update Income";
                cout << "\nc. Add Expense";
                cout << "\nd. Update Expense";
                cout << "\ne. Display Expenses";
                cout << "\nf. Display Total Income";
                cout << "\ng. Financial Report";
                cout << "\nh. Set Goals";
                cout << "\ni. Alerts and Notifications";
                cout << "\nj. Tax Management";
                cout << "\nk. Sign Out";
                cout << "\nEnter Your Choice: ";
                cin >> menu_choice;

                switch (menu_choice)
                {
                case 'a':
                    cout << "\nEnter income amount: $";
                    cin >> amount;
                    incomeManager.addIncome(amount);
                    break;
                case 'b':
                    cout << "\nEnter new income amount: $";
                    cin >> amount;
                    incomeManager.addIncome(amount);
                    cout << "\nIncome updated successfully!";
                    break;
                case 'c':
                    cout << "\nEnter expense amount: $";
                    cin >> amount;
                    expenseManager.addExpense(amount);
                    break;
                case 'd':
                    // Update Expense logic here
                    break;
                case 'e':
                    // Display Expenses logic here
                    break;
                case 'f':
                    cout << "\nTotal Income: $" << incomeManager.getTotalIncome();
                    break;
                case 'g':
                    FinancialReport::generateReport(incomeManager, expenseManager);
                    break;
                case 'h':
                    // Set Goals logic here
                    break;
                case 'i':
                    // Alerts and Notifications logic here
                    break;
                case 'j':
                    // Tax Management logic here
                    break;
                case 'k':
                    cout << "\nSigning out...";
                    // Deallocate memory for users
                    for (int i = 0; i <size; ++i)
                    {
                        delete users[i];
                        users[i] = nullptr;
                    }
                    break;

                default:
                    cout << "\nInvalid choice!";
                }
            }
        } while (menu_choice != 'k');

    } while (menu_choice != '3');

    // Deallocate memory for users
    for (int i = 0; i < size; i++)
    {
        delete users[i];
    }
    delete[] users;

    return 0;
}
