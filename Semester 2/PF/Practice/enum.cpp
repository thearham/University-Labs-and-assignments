#include <iostream>
using namespace std;

enum Year{
	Jan = 1,
	Feb,
	Mar,
	Apr,
	May,
	Jun,
	Jul,
	Aug,
	Sept,
	Oct,
	Nov,
	Dec
}i;

int main() {

	
	i = Feb;
	cout << i + 1 << endl;

	for (int i = Jan; i <= Dec; i++)
	{
		cout << i << endl;
	}
	

	return 0;
}