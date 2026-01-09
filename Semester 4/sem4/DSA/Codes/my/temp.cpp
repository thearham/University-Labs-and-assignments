#include <iostream>
using namespace std;

void rec(){
	static int index = 0;
	index++;

	if(index < 10){
		cout << index << endl;
		rec();
	}
}
/*
the index variable is incremented each time recursiveFunction is called.
Because index is static, it retains its value between calls, so it will continue to
increment each time the function is called.
If index were a local variable (not static), it would be reinitialized to 0 each
time the function is called, and it would never reach the value of 10 to stop the recursion.
*/

int main(){
	rec();
	return 0;
}
