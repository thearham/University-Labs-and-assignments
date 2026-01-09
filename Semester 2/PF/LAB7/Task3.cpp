#include <iostream>
using namespace std;

int stringLength(char  *);
int main(){
	char string1[10];
	cout << "Enter the  string: ";
	cin.getline(string1, 20);

    cout << "The length of the string = " << stringLength(string1);
    
    cout << "\n";
	
	return 0;
}

int stringLength(char *str){
	int i = 0;
	while(str[i] != '\0'){
		i++;
	}
    return i;
}