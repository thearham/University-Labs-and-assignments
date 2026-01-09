#include<unordered_map>
#include<iostream>
using namespace std;
int main() {
	unordered_map<string, int>un;
	un["Ali"] = 10;
	un["Ahsan"] = 33;
	un["Waseem"] = 46;
	un["Mahad"] = 14;
	un["M"] = 14;

	//for (auto x : un)
		//cout << x.first << " " << x.second << endl;
	for(auto x = un.begin(); x != un.end(); x++) {
		cout << x->first << " " << x->second << endl;
	}
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	string key = "Ali";
	if (un.find(key) != un.end())
	{
		cout << "Key Found" << endl;
	}
	else {
		cout << " Key Not Found" << endl;
	}

	if (un.find("Mahd") != un.end())
	{
		auto temp = un.find("Mahd");
		cout << "Key=" << temp->first << endl;
		cout << "Value=" << temp->second << endl;
	}
	un["Naeem"] = 64;
	for (auto x = un.begin(); x != un.end(); x++) {
		cout << x->first << " " << x->second << endl;
	}
	un.insert(make_pair("Hassan", 170));
	for (auto x = un.begin(); x != un.end(); x++) {
		cout << x->first << " " << x->second << endl;
	}
	int arr[] = { 6,3,3,4,6,3,12,11,1,9,15,11,0,1,9,3,4,2 };
	unordered_map<int, int> unor;
	for (int i = 0; i < 18; i++) {
		int key = arr[i];
		unor[key]++;
	}
	for (auto x = unor.begin(); x != unor.end(); x++) {
		cout << x->first << " " << x->second << endl;
	}
	cout<<un.size()<<endl;
	un.erase("Ali");
	cout << un.size();
}