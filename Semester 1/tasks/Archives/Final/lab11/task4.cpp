#include <iostream>
using namespace std;

int main(){
    int size = 5, i, sum = 0, arr[size];

    for(i = 0; i<size; i++){
        cout << "Enter element " << i+1 << ": ";
        cin >> arr[i];
    }
    cout << "Array = ";
    for (i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Sum = ";
    for(i = 0; i<size; i++){
        sum += arr[i];
    }
    cout << sum << endl;

    system("pause");
    return 0;
}