#include <iostream>
using namespace std;

int size;
int *arr1 = new int[size];
int *arr2 = new int[size];
void fill(){
	cout << "Enter size: ";
	cin >> size;
	
	cout << "Enter data in array 1: ";
	for(int i = 0; i < size; i++){
		cin >> arr1[i];
	}
}
void copy(){
	for(int i = 0; i < size; i++){
		arr2[i] = arr1[i];
	}
}
void print(){
	cout << "Array 1: ";
	for(int i = 0; i < size; i++){
		cout << arr1[i] << " ";
	}
	cout << "\nArray 2: ";
	for(int i = 0; i < size; i++){
		cout << arr2[i] << " ";
	}
}
int main(){
	
	fill();
	copy();
	print();
	delete [] arr1;
	delete [] arr2;
	return 0;
}
	
