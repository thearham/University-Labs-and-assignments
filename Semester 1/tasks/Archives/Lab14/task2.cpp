#include <iostream>
using namespace std;

int main(){
    char arr[50];
    int number;
    cout << "Enter the array: ";
    cin >> arr;
    cout <<"Array = ";
    cout << arr;
    cout << endl;

    cout << "Enter number: ";
    cin >> number;

    for(int i = 0; arr[i] != '\0'; i++){
        arr[i] += char(number);
    }
    cout << "updated array: ";
    cout << arr << endl;
    return 0;
}
