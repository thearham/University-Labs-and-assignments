#include <iostream>
using namespace std;

int main() {
	int MD[2] = { 0, 27 };
	int MR = 2;
	unsigned int product[2] = { 0,0 };

	__asm {
		mov ecx, 32

		mulbit:
			shr MR,1
			JC ADD_P
			JMP SMD

			ADD_P:
			mov eax, MD[4]
			add product[4], eax
			mov eax, MD[0]
			ADC product[0], eax

			SMD:
			SHL MD[4], 1
			RCL MD[0], 1
		LOOP MULBIT

	}
	cout << product[0] << product[1] << endl;
	return 0;
}