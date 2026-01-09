#include<iostream>
using namespace std;
int main() {
	int length, breath;
	cout << "enter the value of length:";
	cin >> length;
	cout << "enter the value of breath:";
	cin >> breath;
	cout << endl;
	if (length == breath) {
		cout << "Yes it is square!";
	}
	else {
		cout << "Not it is not Square!";
	}
	system("pause");
	return 0;
}