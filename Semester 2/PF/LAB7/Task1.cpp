#include <iostream>
using namespace std;

void stringCopy(char  *, char  *);
int main(){
	char srcstring[10], desstring[10];
	cout << "Enter the string: ";
	cin.getline(srcstring, 20);
	
	stringCopy(desstring, srcstring);
	cout << "The copied string = " << desstring << endl;
	
	system("pause");	
	return 0;
}

void stringCopy(char *des, char *src){
	int i = 0;
	while(src[i] != '\0'){
		des[i] = src[i];
		i++;
	}
}
