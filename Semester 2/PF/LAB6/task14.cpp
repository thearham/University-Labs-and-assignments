#include <iostream>
using namespace std;

int main(){
    int number1, number2, number3, max;

    cout << "Enter 1st number: ";
    cin >> number1;
    cout << "Enter 2nd number: ";
    cin >> number2;
    cout << "Enter 3rd number: ";
    cin >> number3;

    int * ptr_number1 = & number1;
    int * ptr_number2 = & number2;
    int * ptr_number3 = & number3;
    
    if ( *ptr_number1 > *ptr_number2 && *ptr_number1 > *ptr_number3 )
    {
        max = *ptr_number1;
    }
    else if ( *ptr_number2 > *ptr_number1 && *ptr_number2 > *ptr_number3 )
    {
        max = *ptr_number2;
    }
    else if ( *ptr_number3 > *ptr_number2 && *ptr_number3 > *ptr_number1 )
    {
        max = *ptr_number3;
    }
    
    cout << "Max number = " << max << endl;
    
    system("pause");    
    return 0;
}