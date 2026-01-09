#include<iostream>
using namespace std;
int main() {
	int num1, num2;
	cout << "Enter a first number:";
	cin >> num1;
	cout << "enter a second number:";
	cin >> num2;
	if (num1 > num2) {
		cout << "maximum number is:"<<num1<<endl;
	}
	else if (num1 == num2) {
		cout << "Both are equal!"<<endl;
	}
	else {
		cout << "maximum number is:"<<num2<<endl;
	}
	system("pause");
	return 0;

}