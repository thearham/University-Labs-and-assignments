#include <iostream>
using namespace std;

int main(){
	cout << "Characters for the ASCII Codes"<<endl;
	cout << "--------------------------------------"<< endl;

	for(int code = 32; code <= 127; code++){
		if (code %16==0){
		    cout << endl;
            }
		cout << (char)code << "  ";
	}
	cout << endl << endl;
    system("pause");
	return 0;
}