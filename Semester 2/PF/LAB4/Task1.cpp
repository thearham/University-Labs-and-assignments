#include <iostream>
using namespace std;

int add(int num1, int num2) {
	return num1 + num2;
}
int sub(int num1, int num2) {
	return num1 - num2;
}
int mul(int num1, int num2) {
	return num1 * num2;
}
float divide(int num1, int num2) {
	return num1 / num2;
}

int main() {
	int num1, num2;
	cout << "Enter 1st number: ";
	cin >> num1;
	cout << "Enter 2nd number: ";
	cin >> num2;

	cout << "Addition = " << add(num1, num2)<<endl;
	cout << "Subtraction = " << sub(num1, num2)<<endl;
	cout << "Multiplication = " << mul(num1, num2)<<endl;
	cout << "Division = " << divide(num1, num2)<<endl;

	system("pause");
	return 0;

}