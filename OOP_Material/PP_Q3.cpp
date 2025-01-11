#include<iostream>
#include<string>

using namespace std;

class bankAccount {
protected:
    int accNum;
    double balance;
    double withdrawBank;

public:
    // bankAccount(int acc, double bal) {
    //     accNum = acc;
    //     balance = bal;
    // }

    void setAccNum() {
        cout << "Enter Account Number: ";
        cin >> accNum;
    }

    void setBalance() {
        cout << "Enter Balance: ";
        cin >> balance;
    }

    int getAccNum() {
        return accNum;
    }

    int getBalance() {
        return balance;
    }

    void withdraw() {

        do {
            cout << "Enter the Amount to Withdraw: ";
            cin >> withdrawBank;

            if (withdrawBank > balance) {
                cout << "Insufficient Funds\n";
            }
            else if (withdrawBank < 0) {
                cout << "Withdraw cannot be less than zero\n";
            }
            else {
                balance = balance - withdrawBank;
            }
        } while (withdrawBank < 0 || withdrawBank > balance);
    }

    void printAccount() {
        cout << "====ACCOUNT INFORMATION" << endl;
        cout << "--Account Number = " << getAccNum() << endl;
        cout << "--Account Balance = " << getBalance() << endl;
    }
};


class checkingAccount: public bankAccount{
    protected:
    float interestRate;
    double minBalance;
    float serviceCharges;
    double withdrawCheckings;

    public:
    // checkingAccount(int acc, double bal, float interest, double minBal, float service):bankAccount(acc,bal),interestRate(interest),minBalance(minBal),serviceCharges(service){}
    
    void setInterest(){
        cout<<"Enter Interest rate = ";
        cin>>interestRate;
    }

    void setMinBalance(){
       cout<<"Enter Minimum Balance = ";
       cin>>minBalance; 
    }

    void setServiceCharges(){
        cout<<"Enter Service Charges = ";
        cin>>serviceCharges;
    }

    float getInterestRate(){
        return interestRate;
    }

    double getMinBalance(){
        return minBalance;
    }

    float getServiceCharges(){
        return serviceCharges;
    }
    
    void verifyBalance(){
        if(balance<minBalance){
            cout<<"=> Warning!! Your Balance is Less than Minimum Balance\n";
        }
    }

    void withdraw(){

        do{
        cout<<"Enter the Amount to Withdraw: ";
        cin>>withdrawCheckings;

        if(withdrawCheckings>balance){
            cout<<"Insufficient Funds\n";
        }
        else if(withdrawCheckings<0){
            cout<<"Withdraw cannot be less than zero\n";
        }

        else{
            balance=balance-withdrawCheckings;
        }

        }
        while(withdrawCheckings<0 || withdrawCheckings>balance);
    }

    void displayAccount(){
        cout<<"\n\n===> Checking Account Information <==="<<endl<<endl;
        cout<<"-- Account Number = "<<getAccNum()<<endl
            <<"-- Balance = "<<getBalance()<<endl
            <<"-- Interest rate = "<<getInterestRate()<<endl 
            <<"-- Minimum Balance = "<<getMinBalance()<<endl
            <<"-- Service Charges = "<<getServiceCharges()<<endl;
        cout<<"=======================================================\n\n";
    }
};

class savingsAccount: public bankAccount{
    protected:
    float interestRate;
    double deposit;
    double withdrawSavings;

    public:

    // savingsAccount(int acc, double bal, float interest, double deposit, double withdraw): bankAccount(acc,bal), interestRate(interest),deposit(deposit),withdrawSavings(withdraw){}

    void setInterest(){
        cout<<"Enter Interest Rate: ";
        cin>>interestRate;
    }

    void setDeposit(){
        cout<<"Enter the Amount to Deposit: ";
        cin>>deposit;

        balance+=deposit;
    }

    void withdraw(){
        
        do{
        cout<<"Enter the Amount to Withdraw: ";
        cin>>withdrawSavings;
;

        if(withdrawSavings>balance){
            cout<<"Insufficient Funds\n";
        }
        else if(withdrawSavings<0){
            cout<<"Withdraw cannot be less than zero\n";
        }

        else{
            balance=balance-withdrawSavings;
        }

        }
        while(withdrawSavings<0 || withdrawSavings>balance);
    }

    float getInterestSavings(){
        return interestRate;
    }

    double getDeposit(){
        return deposit;
    }

    void displaySavingAccount(){
        cout<<"\n\n===> Saving Account Information <===\n\n";
        cout<<"-- Account Number = "<<getAccNum()<<endl
            <<"-- Balance = "<<getBalance()<<endl
            <<"-- Interest Rate = "<<getInterestSavings()<<endl
            <<"-- Amount Deposited = "<<getDeposit()<<endl
            <<"-- Amount Withdrawal = "<<withdrawSavings<<endl;
        cout<<"===========================================\n\n";
    }

};


int main(){
    int choice;

    cout<<"===> WELCOME TO BANKING SYSTEM <===\n\n";

    do{
        cout<<"---- MENU ---- "<<endl;
        cout<<"1. Make Checking Account\n";
        cout<<"2. Make Saving Account\n";
        cout<<"3. Exit\n";
        cout<<"---------------\n\n" ;

        cout<<"Enter Your Choice (1-3): ";
        cin>>choice;   
        
        if(choice==1){
            cout<<"~~~~ Creating a Checking Account ~~~~\n\n";
            checkingAccount C1;
            C1.setAccNum();
            C1.setBalance();
            C1.setInterest();
            C1.setMinBalance();
            C1.setServiceCharges();
            C1.withdraw();
            C1.displayAccount();
        }

        else if(choice==2){
            savingsAccount S1;
            S1.setAccNum();
            S1.setBalance();
            S1.setInterest();
            S1.setDeposit();
            S1.withdraw();

            S1.displaySavingAccount();
        }
    
    }

    while(choice!=3);

}