#include <iostream>
using namespace std;

int main(){
	int Fuel, Rent, Bills;

	cout << " Enter Value of Fuel: ";
	cin >> Fuel;

	cout << " Enter Value of Rent: ";
	cin >> Rent;

	cout << " Enter Value of Bills: ";
	cin >> Bills;

	cout << "________________________________\n";

	cout << "Fuel: \t";
	cout << Fuel << endl << endl;
	cout << "Rent: \t";
	cout << Rent << endl << endl;
	cout << "Bills: \t";
	cout << Bills << endl << endl;
	cout << "Total: \t";
	cout << Fuel + Rent + Bills << endl;
	
	cout << "________________________________\n";
	
	system("pause");
	return 0;

}
