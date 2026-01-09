#include <iostream>
using namespace std;

int main(){
	int Chemistry, Maths, Physics;

	cout << "Enter Value of Chemistry: ";
	cin >> Chemistry;
	cout << "Enter Value of Maths: ";
	cin >> Maths;
	cout << "Enter Value of Physics: ";
	cin >> Physics;

	cout << "_____________________________________________\n";

	cout << "MATHS \t" << "CHEMISTRY \t" << "PHYSICS \t" << "TOTAL" << endl;
	cout << Maths << " \t" << Chemistry << " \t\t" << Physics << " \t\t" << Maths + Physics + Chemistry << endl;

	cout << "_____________________________________________\n";

	system("pause");
	return 0;

}

