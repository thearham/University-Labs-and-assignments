#include <iostream>
using namespace std;

int main() {
	unsigned char arr[80] = {0};
	for (int i = 0; i < 80; i++)
	{
		arr[i] = 3;
	}
	 unsigned char a[8] = {0};
	 
	 __asm {
		 mov ecx, 72
		 mov esi, 0
		 
		 movq mm0, arr[esi]
		 loop1:
		 movq mm1, arr[esi+8]
		 paddb mm0,mm1
		 add esi, 8
		 sub ecx,8
		 cmp ecx, 0
		 jne loop1
		 movq [a], mm0
		 emms
		 
	 }
	 int sum = 0;
	 for (int i = 0; i < 8; i++)
	 {
		 cout << (int)a[i] << " ";
		 sum += a[i];
	 }
	 cout << "sum = " << (int)sum << endl;
	
}