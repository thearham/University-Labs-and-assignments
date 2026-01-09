#include <iostream>
using namespace std;

int main(){
    float minutes;
    int hours;

    cout << "Input minutes: ";
    cin >> minutes;

    cout << "Result: ";
    hours = minutes / 60;
    cout << hours << " hours " << minutes - (hours * 60) << " minutes\n" ;
    system("pause");
    return 0;
}