/*Write a program in C++ that declares and initializes an integer array of 5 elements. The program then swaps 
the least and most significant bytes and the nibbles of the second byte of each element of the array using 
inline assembly language programming.*/

#include <iostream>
using namespace std;

int main() {
	const int size = 5;
	int arr[size] = { 1,2,3,4,5 };

	cout << "Original values: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < size * 4; i +=4)
	{
		__asm {
			mov esi, i
			mov al, byte ptr [arr+esi]
			inc esi

			
			ror byte ptr [arr + esi], 4

			add esi, 2
			mov ah, byte ptr [arr+esi]
			mov byte ptr [arr+esi], al

			mov esi, i
			mov byte ptr [arr + esi], ah

		}
	}
	cout << "values after swaping: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	

}