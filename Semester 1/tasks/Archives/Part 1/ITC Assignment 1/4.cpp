#include <iostream>
using namespace std;
int main() {
	int num1;
	cout << "Enter a number:";
	cin >> num1;
	if (num1 % 5 == 0 || num1 % 11 == 0) {
		cout << num1 << "is divisible by 5 and 11" <<endl;
	}
	else {
		cout << num1 << "is not divisible by 5 and 11" <<endl;
	}
}