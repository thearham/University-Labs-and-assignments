#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int toFind, int left, int right) {
	if (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == toFind) {
			return mid;
		}
		else if (arr[mid] > toFind) {
			return binarySearchRecursive(arr, toFind, left, mid - 1);
		}
		else {
			return binarySearchRecursive(arr, toFind, mid + 1, right);
		}
	}
	return -1;
}

int* generateArray() {
   int* arr = new int[5];
   int data;
   for (int i = 0; i < 5; i++) {
       data = rand() % 10;
       arr[i] = data;
   }
   return arr;
}

void sortArray(int* arr) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4 - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	
	int num = 0, size = 5, *arr, search;
	char wait;
	while (num != -1) {
		system("CLS");
		cout << "Enter any number to Generate New Array(-1 to Return): ";
		cin >> num;
		if (num == -1) {
			break;
		}
		arr = generateArray();
		sortArray(arr);
		cout << "Array: " << endl << "[ ";
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << "]" << endl;
		cout << "Which element to find through Binary Search: " << endl;
		cin >> search;
		int found = binarySearchRecursive(arr, search, 0, size -1);
		if (found == -1) {
			cout << "Element not found in array" << endl;
		}
		else {
			cout << "Element found in array at position " << found << endl;
		}
		delete[] arr;
		cout << "Press any key to Return..." << endl;
		cin >> wait;
	}
	system("pause");
}