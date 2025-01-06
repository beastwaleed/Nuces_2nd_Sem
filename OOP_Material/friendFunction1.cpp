#include<iostream>
using namespace std;

class bankAccount{
  private:
  int accNum, balance;
  
  public:
//   bankAccount(){accNum=0,balance=0;}
  bankAccount(int acc, int bal):accNum(acc),balance(bal){}
  
  
  void withdraw(int amount){
      balance=balance-amount;
      cout<<"Withdraw Successful!!\n\n";
  }
  
  void deposit(int amount){
     
     balance=balance+amount;
     cout<<"Deposit Successful!!\n\n";
  }
  
  int getbankAcc(){
      return accNum;
  }
  
  int getBalance(){
      return balance;
  }
  
  void print(){
      cout<<"Account Number : "<<accNum<<endl
          <<"Account Balance: "<<balance<<endl
          <<"---------------------------"<<endl;
  }
  
  friend void transferFunds(bankAccount &from, bankAccount &to, int amount);
    
};

 void transferFunds(bankAccount &from, bankAccount &to, int amount){
    from.withdraw(amount);
    to.deposit(amount);
    cout<<"Transfer Funds Successfully\n\n";
}


int main(){
    int amount;
    bankAccount Acc1(101,500);
    bankAccount Acc2(105,1500);
    
    Acc1.print();
    Acc2.print();
    
    cout<<"Enter Amount to Transfer from Account 101 to Account 105: ";
    cin>>amount;
    transferFunds(Acc1,Acc2,amount);
    
    Acc1.print();
    Acc2.print();
}