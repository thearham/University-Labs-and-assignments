//#include <iostream>
//using namespace std;
//
//int searchArray(int arr[], int s, int toFind, int index) {
//	if (index >= s) {
//		return -1;
//	}
//	else if (arr[index] == toFind){
//		return index;
//	}
//	return searchArray(arr, s, toFind, index + 1);
//}
//
//int arrSize;
//int *generateArray() {
//	arrSize = rand() % 10;
//	int* arr = new int[arrSize];
//	int data;
//	for (int i = 0; i < arrSize; i++) {
//		data = rand() % 10;
//		arr[i] = data;
//	}
//	return arr;
//}
//
//int main() {
//	srand(time(0));
//	int num = 0, *arr, search;
//	char wait;
//	while (num != -1) {
//		system("CLS");
//		cout << "Enter any number to Generate New Array(-1 to Return): ";
//		cin >> num;
//		if (num == -1) {
//			break;
//		}
//		arr = generateArray();
//		cout << "Array: " << endl << "[ ";
//		for (int i = 0; i < arrSize; i++) {
//			cout << arr[i] << " ";
//		}
//		cout << "]" << endl;
//		cout << "Which element to search: " << endl;
//		cin >> search;
//		int found = searchArray(arr, arrSize, search, 0);
//		if (found == -1) {
//			cout << "Element not found in array" << endl;
//		}
//		else {
//			cout << "Element found in array at position " << found << endl;
//		}
//		delete[] arr;
//		cout << "Press any key to Return..." << endl;
//		cin >> wait;
//	}
//	system("pause");
//}