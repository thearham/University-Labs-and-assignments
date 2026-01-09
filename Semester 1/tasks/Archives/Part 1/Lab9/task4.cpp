#include <iostream>
using namespace std;

int main(){
    int number, last_number;

    while(true){
        cout << "Enter a number: ";
        cin >> number;

        if(number != 0){
            last_number = number;
        }
        else if(number == 0){
            break;
        }

    }
    cout << "Last non-zero number = " << last_number << endl;
    system("pause");
    return 0;
}