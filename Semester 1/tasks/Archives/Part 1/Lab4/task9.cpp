#include <iostream>
using namespace std;

int hours, minutes;

int main(){
	cout << "hours: ";
	cin >> hours;
	cout << "minutes: ";
	cin >> minutes;

	cout << "Total: ";
	cout << (hours * 60) + minutes << endl;

	system("pause");
	return 0; 
}
