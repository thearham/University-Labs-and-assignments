#include<iostream>
using namespace std;
int main() {
	int num1, num2, num3;
	cout << "Enter a first number:";
	cin >> num1;
	cout << "Enter a second number:";
	cin >> num2;
	cout << "Enter a third number:";
	cin >> num3;
	if (num1 >= num2 && num1 >= num3) {
		cout << num1 << ":is the greates one!"<<endl;
	}
	else if (num2 >= num3) {
		cout << num2 << ":is greates one!"<<endl;
	}
	else {
		cout << num3 << ":is the greates one!"<<endl;
	}
	system("pause");
	return 0;

}