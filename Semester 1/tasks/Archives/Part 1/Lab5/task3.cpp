#include <iostream>

using namespace std;

int main() {

	int num1, num2, num3;

	cout << "Enter 1st number : ";
	cin >> num1;

	cout << endl << "Enter 2nd number : ";
	cin >> num2;

	cout << endl << "Enter 3rd number : ";
	cin >> num3;

	if (num1 >= num2 && num1 >= num3) {

		cout << endl << num1 << " is largest number";

	}
	else if (num2 >= num3) {

		cout << endl << num2 << " is largest number";

	}
	else {

		cout << endl << num3 << " is largest number";
	}

	return 0;
}