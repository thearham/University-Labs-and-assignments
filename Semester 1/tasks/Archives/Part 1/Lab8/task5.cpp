#include <iostream>
using namespace std;

int main(){
    int num1, num2, lcm;
    int count = 1;

    cout << "Enter the first number : ";
    cin >> num1;

    cout << "Enter the second number : ";
    cin >> num2;

    if (num1 < num2){
        lcm = num2;
        while (count < num1){
            if (lcm % num1 == 0 && lcm % num2 == 0){
                break;
            }
            lcm += num2;
            count++;
        }
    }
    else{
        lcm = num1;
        while (count < num2){
            if (lcm % num1 == 0 && lcm % num2 == 0){
                break;
            }
            lcm += num1;
            count++;
        }
    }
    cout << "LCM is " << lcm << endl;
    system("pause");
    return 0;
}