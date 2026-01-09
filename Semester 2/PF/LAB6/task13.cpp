#include <iostream>
using namespace std;

int main(){
    int number1, number2;

    cout << "Enter 1st number: ";
    cin >> number1;

    cout << "Enter 2nd number: ";
    cin >> number2;

    int * ptr_number1 = & number1;
    int * ptr_number2 = & number2;
    
    int Difference = * ptr_number1 - *ptr_number2;


    cout << "Difference of two numbers = " << Difference << endl;

    
    
    system("pause");    
    return 0;
}