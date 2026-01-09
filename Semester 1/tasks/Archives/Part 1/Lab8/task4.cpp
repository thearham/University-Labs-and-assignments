#include <iostream>
using namespace std;

int main(){
    int hours, rate = 10, employees = 10;

    for(int i=0; i< employees; i++){
        cout << "Enter the hours worked: ";
        cin >> hours;
        cout << "The pay of employee " << i + 1 << " is: " << hours * rate << endl;
    }
    system("pause");
    return 0;
}