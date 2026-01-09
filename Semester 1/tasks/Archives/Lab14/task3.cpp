#include <iostream>
using namespace std;

int main(){
    char arr1[50], arr2[50];
    int sum1 = 0, sum2 = 0;
    cout << "Enter the 1st character array: ";
    cin >> arr1;
    cout << "Enter the 2nd character array: ";
    cin >> arr2;

    cout << "ASCII value of 1st array = ";
    for(int i = 0; arr1[i] != '\0'; i++){
        sum1 += int(arr1[i]);
    }
    cout << sum1 << endl;
    cout << "ASCII value of 2nd array = ";
    for(int i = 0; arr2[i] != '\0'; i++){
        sum2 += int(arr2[i]);
    }
    cout << sum2 << endl;
    
    return 0;
}
