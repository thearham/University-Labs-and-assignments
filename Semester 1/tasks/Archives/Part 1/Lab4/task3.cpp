#include <iostream>
using namespace std;

int main(){
    int num1, num2;

    cout << "Enter the first variable: ";
    cin >> num1;
    cout << "Enter the second variable: ";
    cin >> num2;

    cout << "Sum of values: ";
    cout << num1 + num2 << endl;

    cout << "Product of values: ";
    cout << num1 * num2 << endl;

    cout << "Difference of values: ";
    cout << num1 - num2 << endl;

    cout << "Division of values: ";
    cout << float(num1 / num2) << endl;

    system("pause");
    return 0;
}