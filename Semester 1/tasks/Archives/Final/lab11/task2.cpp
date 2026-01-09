#include <iostream>
using namespace std;

int main(){
    int arr[5];
    for(int i = 0; i<5; i++){
        cout << "Enter array elements: ";
        cin >> arr[i];
    }
    cout << "Array = ";
    for(int i = 0; i<5; i++){
        cout << arr[i] << ", "; 
    }
    cout << endl;
    cout << "Reversed Array = ";
    for(int i = 4; i>=0; i--){
        cout << arr[i] << ", ";
    }
    cout << endl;

    system("pause");
    return 0;
}