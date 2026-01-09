#include<unordered_set>
#include<iostream>
using namespace std;
int main() {
	unordered_set<string>s;
	s.insert("ALi");
	s.insert("Waseem");
	s.insert("Kamal");
	s.insert("Zaeem");
	s.insert("Zaeem");
	for (auto it = s.begin(); it != s.end(); it++)
		cout << (*it) << endl;
	cout << s.size()<<endl;
	//int key = 20;
	if (s.find("Ali") != s.end()) {
		cout << "Key not found" << endl;
	}
	else {
		cout << "Key found" << endl;
	}
	s.erase("Waseem");
	for (auto it = s.begin(); it != s.end(); it++)
		cout << (*it) << endl;
	s.clear();
	cout << s.size() << endl;
}
