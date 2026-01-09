#include <iostream>
using namespace std;

int main(){
    int number, temp, digits = 0;
    cout << "Enter a number: ";
    cin >> number;
    temp = number;

    while(temp != 0){
        digits++;
        temp /= 10;
    }
    cout << "Total digits in " << number << " are: " << digits << endl;

    system("pause");
    return 0;
}