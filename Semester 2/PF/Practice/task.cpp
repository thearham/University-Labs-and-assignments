#include <iostream>
using namespace std;

int main(){
	srand(1000);

	cout << rand() / RAND_MAX << endl;
	cout << rand()  << endl;

	return 0;
}
