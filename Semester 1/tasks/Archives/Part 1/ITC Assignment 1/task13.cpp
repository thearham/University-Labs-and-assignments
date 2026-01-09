#include<iostream>
using namespace std;
int main() {
	int your_grade,marks;
	cout << "Enter your marks:";
	cin >> marks;
	if (marks < 25) {
		cout << "Your grade is :\tF"<<endl;
	}
	else if (marks >= 25 && marks < 45) {
		cout << "Your grade is:\tE"<<endl;
	}
	else if (marks >=45 && marks < 50) {
		cout << "Your grade is:\tD" << endl;
	}
	else if (marks >=50  && marks <60  ) {
		cout << "Your grade is:\tC" << endl;
	}
	else if (marks >= 60 && marks < 80) {
		cout << "Your grade is:B" << endl;
	}
	else {
		cout << " your grade is:A" << endl;
	}
	system("Pause");
	return 0;
}