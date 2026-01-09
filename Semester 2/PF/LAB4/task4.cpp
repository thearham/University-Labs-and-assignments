#include <iostream>
using namespace std;

int factorial(int num){
    int fact = 1;
    for (int i = 1; i <= num; i++){
        fact *= i;
    } 
    return fact;
}

int main(){
    int num;
    cout << "Enter number greater than zero: ";
    cin >> num;

    cout << "Factorial = " << factorial(num) << "\n";

    system("pause");
    return 0;
}