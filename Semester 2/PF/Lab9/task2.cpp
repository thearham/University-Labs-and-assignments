#include <iostream>

using namespace std;

int main() {
    int a, b;
    int* ptrA, *ptrB;

    cout << "Enter an integer for 'a': ";
    cin >> a;
    cout << "Enter an integer for 'b': ";
    cin >> b;

    ptrA = &a;
    ptrB = &b;

    cout << "ptrA = " << *ptrA << endl;
    cout << "ptrB = " << *ptrB << endl;

    return 0;
}
