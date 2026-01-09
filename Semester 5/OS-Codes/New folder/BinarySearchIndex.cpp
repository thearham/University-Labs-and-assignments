#include <iostream>
using namespace std;

int searchIndex(int arr[], int size)
{
	int left = 0, right = size - 1, index = -1;
	
	while(left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] == mid)
		{
			index = mid;
			break;
		}
		if (arr[mid] < mid)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return index;
}

int main()
{
	int arr[10] = {-12, -2, 0, 2, 2, 3, 4, 7, 30, 38};
	int index = searchIndex(arr,10);
	cout << index << endl;

	return 0;
}
