/*Write a program in C++ that declares and initializes an integer array of 5 elements. The program then rotates 
the least significant byte (i.e., byte #0) and most significant byte (i.e., byte #3) to the left and the byte #1 
and byte #2 to the right of each element of the array using inline assembly language programming.*/

#include <iostream>
using namespace std;

int main() {
	int arr[5] = { 1,2,3,4,5 };
	cout << "original values:\n";
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 5 * 4; i+=4)
	{
		__asm {
			mov esi,i
			rol byte ptr [arr+esi], 4
			inc esi
			ror byte ptr [arr+esi], 4
			inc esi
			ror byte ptr [arr+esi], 4
			inc esi
			rol byte ptr[arr + esi], 4
		}
	}
	cout << "values after rotation:\n";
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}

	for (int i = 0; i < 5 * 4; i += 4)
	{
		__asm {
			mov esi, i
			rol byte ptr[arr + esi], 4
			inc esi
			ror byte ptr[arr + esi], 4
			inc esi
			ror byte ptr[arr + esi], 4
			inc esi
			rol byte ptr[arr + esi], 4
		}
	}

	cout << "\nrotating rotated values to check it works properly: \n";
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}

}