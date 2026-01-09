#include <iostream>
using namespace std;

bool  stringCompare(char  *, char  *);
int main(){
	char string1[10], string2[10];
	cout << "Enter the first string: ";
	cin.getline(string1, 20);
	
	cout << "Enter the second string: ";
	cin.getline(string2, 20);
	
	if(stringCompare(string1, string2) == 1){	
		cout << "The strings are identical" << endl;
	}
	else{
		cout << "The strings are not identical" << endl;
	}
	
	return 0;
}

bool stringCompare(char *str1, char *str2){
	int i = 0;
	while(str1[i] != '\0'){
		if(str1[i] == str2[i]){
			return true;
		}
		else{
			return false;
			break;
		}
		i++;
	}
}
