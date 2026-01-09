#include <iostream>
using namespace std;

void days(int num){
    switch (num)
    {
    case 1:
        cout << "Monday\n";
        break;
    case 2:
        cout << "Tuesday\n";
        break;
    case 3:
        cout << "Wednesday\n";
        break;
    case 4:
        cout << "Thursday\n";
        break;
    case 5:
        cout << "Friday\n";
        break;
    case 6:
        cout << "Saturday\n";
        break;
    case 7:
        cout << "Sunday\n";
        break;
    default:
        cout << "Enter a number from 1 to 7!\n";
        break;
    }
}

int main(){
    int num;
    cout << "Enter number from 1 to 7 = ";
    cin >> num;
    cout << "The day is: ";
    days(num);

    system("pause");
    return 0;
}