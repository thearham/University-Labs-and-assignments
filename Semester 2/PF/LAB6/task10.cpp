#include <iostream>
using namespace std;

int main(){
    int number1;

    cout << "Enter 1st number: ";
    cin >> number1;

    int * ptr_number1 = & number1;
    
    if ( *ptr_number1 > 0 )
    {
        cout << "Number is Positive.\n";
    }
    else if ( *ptr_number1 < 0)
    {
        cout << "Number is Negative.\n";
    }
    else if ( *ptr_number1 == 0)
    {
        cout << "Number is equal to zero.\n";
    }
    
    

    
    system("pause");    
    return 0;
}