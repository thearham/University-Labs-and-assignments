#include <iostream>
using namespace std;

int main(){
    int number1;

    cout << "Enter 1st number: ";
    cin >> number1;

    int * ptr_number1 = & number1;

    int increment = *ptr_number1 + 1;
    int decrement = increment - 1;

    cout << "Increment value = " << increment << "\n";
    cout << "Decrement value = " << decrement << "\n";

    system("pause");
    return 0;
}