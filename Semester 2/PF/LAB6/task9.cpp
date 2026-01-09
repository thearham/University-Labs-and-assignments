#include <iostream>
using namespace std;

int main(){
    float number1, number2;

    cout << "Enter 1st number: ";
    cin >> number1;

    cout << "Enter 2nd number: ";
    cin >> number2;

    float * ptr_number1 = & number1;
    float * ptr_number2 = & number2;
    
    float division = * ptr_number1 / *ptr_number2;


    cout << "Division of two numbers = " << division << endl;

    
    
    system("pause");    
    return 0;
}