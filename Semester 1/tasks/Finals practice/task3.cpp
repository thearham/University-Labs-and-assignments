#include <iostream>
using namespace std;

int main(){
    int arr[3], arr1[6];

    cout << "array: ";
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }

    int last = arr[2];

    for (int i = 0; i < 6; i++)
    {
        arr1[i] = '\0';
        arr[5] = last;
        cout << arr1[i] << " ";
    }
    
    
    
    return 0;
}