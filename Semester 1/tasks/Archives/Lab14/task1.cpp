#include <iostream>
using namespace std;

int main(){
    char arr[50], letter, replace;
    cout << "Enter the array: ";
    cin >> arr;

    cout <<"Array = ";
    cout << arr << endl;
    
    cout << "enter the letter to be found: ";
    cin >> letter;

    cout << "enter the letter to be replaced: ";
    cin >> replace;

    for(int i =0; arr[i] != '\0'; i++){
        if(letter == arr[i]){
            arr[i] = replace;
        }
    }
    cout << "Updated array = ";
    cout << arr << endl;

    system("pause");
    return 0;


}