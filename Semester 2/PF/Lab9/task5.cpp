#include <iostream>
using namespace std;

int size;
int *arr = new int[size];
int *sortedArr = new int[size];

void input(){
	cout << "Enter size: ";
	cin >> size;
	
	cout << "Enter unsorted data in array : ";
	for(int i = 0; i < size; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < size; i++){
		sortedArr[i] = arr[i];
	}
}
void sort(){
	int temp;
	for(int i=0;i<size;i++){		
		for(int j=i+1;j<size;j++){
			if(sortedArr[i] > sortedArr[j]){
				temp  = sortedArr[i];
				sortedArr[i] = sortedArr[j];
				sortedArr[j] = temp;
			}
		}
	}
}
void print(){
	cout << "Unsorted Array : ";
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << "\nSorted Array : ";
	for(int i = 0; i < size; i++){
		cout << sortedArr[i] << " ";
	}
}
int main(){
	
	input();
	sort();
	
	print();
	delete [] arr;
	delete [] sortedArr;
	return 0;
}
	
