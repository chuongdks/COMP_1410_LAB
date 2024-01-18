#include <stdio.h>
#include <string.h>

//#include "BankAccount.h"

typedef struct BankAccount_struct {
    char *customerName;
    double savingBalance;
    double checkingBalance;
} BankAccount;

BankAccount InitBankAccount(char* newName, double amt1, double amt2); //- set the customer name to parameter newName, set the checking account balance to parameter amt1 and set the savings account balance to parameter amt2. (amt stands for amount)

BankAccount SetName(char* newName, BankAccount account); //set the customer name

void GetName(char* customerName, BankAccount account); //return the customer name in customerName

BankAccount SetChecking(double amt, BankAccount account); //set the checking account balance to parameter amt

double GetChecking(BankAccount account); //return the checking account balance

BankAccount SetSavings(double amt, BankAccount account); //set the savings account balance to parameter amt

double GetSavings(BankAccount account); //return the savings account balance

BankAccount DepositChecking(double amt, BankAccount account); //add parameter amt to the checking account balance (only if positive)

BankAccount DepositSavings(double amt, BankAccount account); //add parameter amt to the savings account balance (only if positive)

BankAccount WithdrawChecking(double amt, BankAccount account); //subtract parameter amt from the checking account balance (only if positive)

BankAccount WithdrawSavings(double amt, BankAccount account); //subtract parameter amt from the savings account balance (only if positive)

BankAccount TransferToSavings(double amt, BankAccount account); //subtract parameter amt from the checking account balance and add to the savings account balance (only if positive)




int main() {
   BankAccount account = InitBankAccount("Mickey", 500.00, 1000.00);
   char name[20];
   
   account = SetChecking(500, account);
   account = SetSavings(500, account);
   account = WithdrawSavings(100, account);
   account = WithdrawChecking(100, account);
   account = TransferToSavings(300, account);
   
   GetName(name, account);
   printf("%s\n", name);
   printf("$%.2f\n", GetChecking(account));
   printf("$%.2f\n", GetSavings(account));

   return 0;
}



BankAccount InitBankAccount(char* newName, double amt1, double amt2){
    BankAccount newBankAccount;
    newBankAccount.customerName = newName;
    newBankAccount.checkingBalance = amt1;
    newBankAccount.savingBalance = amt2;
    return newBankAccount;
}

BankAccount SetName(char* newName, BankAccount account){
    account.customerName = newName;
    return account;
}

void GetName(char* customerName, BankAccount account){
    strcpy(customerName, account.customerName);
}

BankAccount SetChecking(double amt, BankAccount account){
    account.checkingBalance = amt;
    return account;
}

double GetChecking(BankAccount account){
    return account.checkingBalance;
}

BankAccount SetSavings(double amt, BankAccount account){
    account.savingBalance = amt;
    return account;
}

double GetSavings(BankAccount account){
    return account.savingBalance;
}

BankAccount DepositChecking(double amt, BankAccount account){
    if (account.checkingBalance > 0)
    {
        account.checkingBalance += amt;
    }
    return account;
}

BankAccount DepositSavings(double amt, BankAccount account){
    if (amt > 0 )
    {
        account.savingBalance += amt;
    }
    return account;
}

BankAccount WithdrawChecking(double amt, BankAccount account){
    if (amt > 0)
    {
        account.checkingBalance -= amt;
    }
    return account;
}

BankAccount WithdrawSavings(double amt, BankAccount account){
    if (amt > 0)
    {
        account.savingBalance -= amt;
    }
    return account;
}

BankAccount TransferToSavings(double amt, BankAccount account){
    if (amt > 0)
    {
        account.checkingBalance -= amt;
        account.savingBalance += amt;
    }
    return account;
}