/*Write a program in C++ that declares an integer array of 32 elements and initializes it with some 
8-bit unsigned data. The program then uses MMX instructions in inline assembly programming to 
replace byte#3 of each element of the array with 0xFF. The program shows the array on the 
console.
If you do the same task without using MMX instructions, you won't get any points.
(Hint: This will be achieved through masking. Take care of endianness while initializing mask 
array.)
*/

#include <iostream>
using namespace std;

int main() {
	int arr[32] = { 0 };
	long long replace = 0x00ff000000ff0000;

	for (int i = 0; i < 128 ; i+=8)
	{
		__asm {
			mov esi, i
			movq mm0, [arr+esi]
			movq mm1, [replace]
			por mm0, mm1
			movq [arr+esi], mm0
			emms
		}
	}
	for (int i = 0; i < 32; i++)
	{
		cout << arr[i] << " ";
	}
}