#include<iostream>
using namespace std;
int main() {
	char ch;
	cout << "Enter an Alphabet:";
	cin >> ch;
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 's') {
		cout << ch << " is a Vowel";
	}
	else {
		cout << ch <<" is not Vowel"<<endl;
	}
	system("pause");
	return 0;
}
