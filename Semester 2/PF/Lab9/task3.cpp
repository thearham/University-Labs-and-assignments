#include <iostream>
using namespace std;

int size;
int *arr = new int[size];
void fill(){
	cout << "Enter size: ";
	cin >> size;
	
	cout << "Enter data in array: ";
	for(int i = 0; i < size; i++){
		cin >> arr[i];
	}
	
}
void print(){
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
}
int main(){
	
	fill();
	print();
	delete [] arr;
	return 0;
}
	
