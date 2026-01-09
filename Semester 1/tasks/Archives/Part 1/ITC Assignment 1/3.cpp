#include<iostream>
using namespace std;
int main() {
	int num1;
	cout << "Enter the number:";
	cin >> num1;
	if (num1 > 0) {
		cout << num1 << "\tThe number is positive."<<endl;
	}
	else if (num1<0) {
		cout << num1 << "\tThe number is negative."<<endl;
	}
	else {
		cout << "\tYou entered a zero!"<<endl;
	}
	system("Pause");
	return 0;
}