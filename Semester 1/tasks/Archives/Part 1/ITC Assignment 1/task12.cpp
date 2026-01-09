#include <iostream>
using namespace std;

int  main() {
		int salary, years, bonus;
		cout << "Enter your salary: Rs ";
		cin >> salary;
		cout << "Enter your year of service: ";
		cin >> years;
		if (years > 5) {
			bonus = salary * 5 / 100;
			cout << "your bonus amount is Rs " << bonus << endl;
		}
		else {
			cout << "You don't get any bonus amount!" << endl;
		}
		system("pause");
		return 0;
}