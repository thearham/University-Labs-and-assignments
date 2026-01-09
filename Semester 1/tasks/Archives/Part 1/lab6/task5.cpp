#include <iostream>
using namespace std;

int main(){
int num;
cout << "Enter integer: ";
cin >> num;

if(num%2 == 0){
cout << num << " is an even number.\n";
}
else if(num%2 != 0){
cout << num << " is odd number.\n";
}
system("pause");
return 0;
}