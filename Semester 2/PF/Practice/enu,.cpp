#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
using namespace std;

enum seasons
{
	summer, winter = 69, spring, autumn
}s;

int main() {
	float N = 0.9;
	srand(time(NULL));
	

	cout << fixed <<  setprecision(2) << ((float) rand()) / RAND_MAX << endl;

	int s = winter | spring ;

	cout << s  << endl;

	return 0;
}