#include<iostream>
using namespace std;
int main() {
	char value;
	cout << "Would you like to continue further?" << endl;
	cout << "Press Y if yes" << endl;
	cout << "Press N if no" << endl;
	cout << "Please enter:" << endl;
	cin >> value;
	if (value == 'Y' || value == 'y') {
		cout << "Loading....." << endl;
	}
	else if (value == 'N' || value == 'n') {
		cout << "Goodbye..." << endl;
	}
	else {
		cout << "Invalid input"<<endl;
	}
	system("pause");
	return 0;

}