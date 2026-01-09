#include "BankAccount.h"
#include "Function_definitions.h"


int main(){
	Bank_Account Account_one;
	Account_one.setAccount_holder_name("arham");
	Account_one.setAccount_number(123);
	Account_one.setAccount_type("Current");
	Account_one.setAccount_balance(10000);

	cout << "Account Name = " << Account_one.getAccount_holder_name() << endl;
	cout << "Account Number = " << Account_one.getAccount_number() << endl;
	cout << "Account Type = " << Account_one.getAccount_type() << endl;
	cout << "Account Balance = " << Account_one.getAccount_balance() << endl;

	Account_one.Deposit(1000);
	Account_one.Withdraw(5000);

	cout << "Account Balance remaining = " << Account_one.getAccount_balance() << endl;

	return 0;
}