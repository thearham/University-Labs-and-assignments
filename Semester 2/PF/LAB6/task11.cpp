#include <iostream>
using namespace std;

int main(){
    int number1;

    cout << "Enter 1st number: ";
    cin >> number1;

    int * ptr_number1 = & number1;

    for (int i = 1; i < 11; i++)
    {
        cout << * ptr_number1 << " * " << i << " = " << * ptr_number1 * i << "\n";
    }
    
    
    return 0;
}