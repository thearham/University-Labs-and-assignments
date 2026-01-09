#pragma once
#include "BankAccount.h"

//Default Constructor:
Bank_Account::Bank_Account(){
	account_holder_name = "";
	account_type = "default";
	account_balance = 0;
	account_number = 0;
}
//setters:
void Bank_Account::setAccount_holder_name(string name){
	account_holder_name = name;
}
void Bank_Account::setAccount_number(int number){
	account_number = number;
}
void Bank_Account::setAccount_type(string type){
	account_type = type;
}
void Bank_Account::setAccount_balance(double balance){
	account_balance = balance;
}
//getters:
string Bank_Account::getAccount_holder_name(){
	return account_holder_name;
}
int Bank_Account::getAccount_number(){
	return account_number;
}
string Bank_Account::getAccount_type(){
	return account_type;
}
double Bank_Account::getAccount_balance(){
	return account_balance;
}
//deposit:
void Bank_Account::Deposit(double amount){
	account_balance += amount;
	cout << "The amount deposited in the bank account = " << amount << endl;
}
//withdraw:
void Bank_Account::Withdraw(double amount){
	if (account_balance - amount < 0)
	{
		cout << "Account does not have sufficient funds. Withdrawl not allowed.\n";
	}
	else
	{
		account_balance -= amount;
		cout << "Successfully withdrawn= Rs " << amount << endl;
	}	
}