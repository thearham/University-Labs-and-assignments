#include <iostream>
using namespace std;

int main(){
    int x;

    cout << "Enter x: ";
    cin >> x;

    int * ptr_x = &x;

    cout << "Value of x = " << x << endl;
    cout << "Value of pointer = " << ptr_x << endl;
    cout << "Value of * pointer = " << *ptr_x << endl;
    
    system("pause");
    return 0;
}