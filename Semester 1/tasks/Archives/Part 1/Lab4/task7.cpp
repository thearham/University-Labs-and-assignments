#include <iostream>
using namespace std;

int WheatP, RiceP, SugarP, WheatQ, RiceQ, SugarQ;

int main(){
	
	cout << "Enter price of wheat: ";
	cin >> WheatP;
	cout << "Enter quantity of wheat: ";
	cin >> WheatQ;
	cout << "Enter price of rice: ";
	cin >> RiceP;
	cout << "Enter quantity of rice: ";
	cin >> RiceQ;
	cout << "Enter price of Sugar: ";
	cin >> SugarP;
	cout << "Enter quantity of Sugar: ";
	cin >> SugarQ;

	cout << "_____________________________\n";

	cout << "Value of Wheat: ";
	cout << WheatP * WheatQ << endl;
	cout << "Value of Rice: ";
	cout << RiceP * RiceQ << endl;
	cout << "Value of Sugar: ";
	cout << SugarP * SugarQ << endl;

	cout << "_____________________________\n";

	system("pause");
	return 0;
}

