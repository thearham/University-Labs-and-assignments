#pragma once
#include <iostream>
#include<string>
using namespace std;

class Bank_Account{
private:
	string account_holder_name;
	int account_number;
	string account_type;
	double account_balance;
public:
	Bank_Account();
	void setAccount_holder_name(string);
	void setAccount_number(int);
	void setAccount_type(string);
	void setAccount_balance(double);

	string getAccount_holder_name();
	int getAccount_number();
	string getAccount_type();
	double getAccount_balance();

	void Deposit(double);
	void Withdraw(double);
};

