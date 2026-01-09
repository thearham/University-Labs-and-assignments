#include <iostream>
using namespace std;

int main(){
    float x;

    cout << "Enter x: ";
    cin >> x;

    void * ptr_x = &x;

    cout << "Value of &x = " << &x << endl;
    cout << "Value of pointer = " << ptr_x << endl;
    
    
    system("pause");    
    return 0;
}