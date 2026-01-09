#include <iostream>
using namespace std;

int main()
{
	const int N = 16;
	int A[N] = { 1, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150 };
	int low = 0, high = N - 1, mid = 0;
	int Value = 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (A[mid] == Value)
		{
			cout << mid << endl;
			break;
		}
		else if (A[mid] < Value)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return 0;
}