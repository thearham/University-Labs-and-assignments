#include <iostream>
using namespace std;

void DNF(char arr[], int size)
{
	int low = 0, mid = 0, high = size - 1;

	while(mid <= high)
	{
		switch(arr[mid])
		{
			case 'R':
				swap(arr[low++],arr[mid++]);
				break;
			case 'G':
				mid++;
				break;
			case 'B':
				swap(arr[mid],arr[high--]);
				break;
		}
	}
}

int main()
{
	char arr[13] = {'R','B','B','G','B','G','R','R','G','B','R','G','B'};
	cout << "Original array: ";
	for (int i = 0; i < 13; i++) cout << arr[i] << " ";
	cout << endl;

	DNF(arr, 13);
	cout << "Sorted array: ";
	for (int i = 0; i < 13; i++) cout << arr[i] << " ";
	cout << endl;

	return 0;
}
