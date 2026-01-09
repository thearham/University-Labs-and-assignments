#include <iostream>

using namespace std;

int main() {

	char strs[3][20] = {

		{'S','t','r','i','n','g','\0'},
		"Programing Class",
		"Do Work"
	};

	cout << strs << endl;
	cout << strs+1 << endl;
	//cout << **strs << endl;

	char * temp = (char*)(strs);
	
	for (int i = 0; i < 3; i++) {

		for (int j = 0; *((*(strs + i)) + j) != '\0'; j++) {
		//for (int j = 0; j<20; j++) {

			cout << *((*(strs + i))+j) << "\t" << 
			char(*(*(strs + i) + j) + 1) << endl;
		}

		cout << *(temp + i) << endl;
		cout << *(strs + i) << endl;
	}

	return 0;
}