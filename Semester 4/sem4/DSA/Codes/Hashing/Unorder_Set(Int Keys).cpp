#include<unordered_set>
#include<iostream>
using namespace std;
int main() {
	unordered_set<int>s;
	s.insert(10);
	s.insert(30);
	s.insert(60);
	s.insert(40);
	//s.insert(40);
	for (auto iterator = s.begin(); iterator != s.end(); iterator++)
		cout << (*iterator) << endl;
	cout << "Size=" << s.size() << endl;
	//1.  s.clear();
	//1. cout << "Size=" << s.size() << endl;
	int key = 10;
	if (s.find(key) == s.end())
	{
		cout << "Key is not found" << endl;
	}
	else {
		cout << "Key is found" << endl;
	}
	s.erase(30);
	cout << "Size=" << s.size() << endl;
	for (auto iterator = s.begin(); iterator != s.end(); iterator++)
		cout << (*iterator) << endl;
	cout << s.count(key);
}
