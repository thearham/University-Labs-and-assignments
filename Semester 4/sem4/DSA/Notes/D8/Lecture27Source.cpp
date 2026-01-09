#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
using namespace std;

int main()
{
	unordered_map<string, int> obj;
	ifstream in;
	in.open("text.txt");
	string temp = " ";

	while (!in.eof())
	{
		in >> temp;
		obj[temp]++;
	}

	in.close();

	for (auto x : obj)
		cout << x.first << " " << x.second << endl;






	/*unordered_map<int, string> obj;		//<key, mapped_value>

	//Insert:
	// obj[key] = mapped_value;
	obj[1944] = "Mohsin Abbas";
	obj[123] = "Ali Awais";
	obj[7] = "Hassan";

	//Display:
	for (auto i : obj)
		cout << i.first <<" " << i.second << endl;
	

	//Deletion:
	obj.erase(1944);

	//Display:
	cout << "Display after deletion: " << endl;
	for (auto i : obj)
		cout << i.first << " " << i.second << endl;
		*/
	return 0;
}