//#include <iostream>
//using namespace std;
//
//int fibo(int n) {
//	if (n == 0 || n == 1) {
//		return n;
//	}
//	else {
//		return fibo(n - 1) + fibo(n - 2);
//	}
//}
//
//int main() {
//	int num = 0; char wait;
//	while (num != -1) {
//		system("CLS");
//		cout << "How many fibonacci terms(-1 to Return): ";
//		cin >> num;
//		if (num == -1) {
//			break;
//		}
//		cout << "Fibonacci: ";
//		for (int i = 0; i < num; i++) {
//			cout << fibo(i) << " ";
//		}
//		cout << "Press any key to continue..." << endl;
//		cin >> wait;
//	}
//	system("pause");
//}