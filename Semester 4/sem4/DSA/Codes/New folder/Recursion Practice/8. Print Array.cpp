//#include <iostream>
//using namespace std;
//
//int* generateArray() {
//    int* arr = new int[5];
//    int data;
//    for (int i = 0; i < 5; i++) {
//        data = rand() % 10;
//        arr[i] = data;
//    }
//    return arr;
//}
//
//void displayArray(int* arr, int start, int end) {
//	if (start > end) {
//		return;
//	}
//	cout << arr[start] << " ";
//	displayArray(arr, start + 1, end);
//}
//
//void displayArrayReverse(int* arr, int start, int end) {
//	if (start > end) {
//		return;
//	}
//	cout << arr[end] << " ";
//	displayArrayReverse(arr, start, end - 1);
//}
//
//int main() {
//	int num = 0; char wait;
//	int* arr, size = 5;
//	while (num != -1) {
//		system("CLS");
//		cout << "Press any number to Generate New Array(-1 to Return): ";
//		cin >> num;
//		if (num == -1) {
//			break;
//		}
//		arr = generateArray();
//		cout << "Array: " << endl;
//		for (int i = 0; i < size; i++) {
//			cout << arr[i] << " ";
//		}
//		cout << endl << endl << "Array: " << endl;
//		displayArray(arr, 0, size - 1);
//		cout << endl << endl << "Reversed Array: " << endl;
//		displayArrayReverse(arr, 0, size - 1);
//		cout << endl << "Press any key to continue..." << endl;
//		cin >> wait;
//	}
//	system("pause");
//}