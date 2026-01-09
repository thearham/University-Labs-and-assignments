#include<iostream>
using namespace std;
int main() {
	int num1, num2;
	cout << "Enter the first number:";
	cin >> num1;
	cout << "Enter the second number:";
	cin >> num2;
	if (num1 > num2) {
		cout << "First number: " << num1 << "\tis largest"<<endl;
	}
	else {
		cout << "Second number: " << num2 << "\tis largest"<<endl;
	}
	system("pause");
	return 0;
}
