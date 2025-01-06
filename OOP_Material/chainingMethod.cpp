#include<iostream>
using namespace std;

class Bank{
private:
    int AccNum;
    int balance;

    public:
    Bank(int acc, int bal):AccNum(acc),balance(bal){}

    Bank &withdraw(int amt){
  
        balance-=amt;
        cout<<"Amount Withdraw Successfully\n";
        return *this;

    }

    Bank &deposit(int amt){
        balance+=amt;
        cout<<"Amount Deposited Succesfully\n";
        return *this;
    }

    void print(){
        cout<<"Acc Num: "<<AccNum<<endl
            <<"Acc Balance: "<<balance<<endl;
    }


};

int main(){
    Bank Acc1(101,10000);
    int withdrawAmount, depositAmount;

    cout<<"Enter Amount to Withdraw: ";
    cin>>withdrawAmount;

    cout<<"Enter Amount to Deposit: ";
    cin>>depositAmount;

    Acc1.withdraw(withdrawAmount).deposit(depositAmount).print();
}