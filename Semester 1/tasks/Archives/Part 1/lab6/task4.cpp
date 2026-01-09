#include <iostream>
using namespace std;

int main(){
char input;

cout << "Input a single character(digit, symbol, alphabet): ";
cin >> input;

if(input >= '0' || input <= '9'){
cout << input << " is a digit \n";
}
else if(input >= 'a' && input <= 'z'){
cout << input << " is not a digit \n";
}
system("pause");
return 0;
}