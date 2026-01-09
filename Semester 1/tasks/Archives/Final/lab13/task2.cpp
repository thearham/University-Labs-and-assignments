#include <iostream>
using namespace std;

int main(){
    int i,j,arr[10], max, min;
    cout << "Input the elements of array = ";
    for(i = 0; i < 10; i++){
        cin >> arr[i];
    }
    cout << "Array = ";
    for(i = 0; i < 10; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;
    for(i = 0; i < 10; i++){
        if(arr[0] < arr[i]){
            arr[0] = arr[i];
            max = arr[0];
            cout << "Max value = " << max << endl;
            break;
        }
    }
    min = arr[0];
    for(i = 0; i < 10; i++){
        if (arr[i] < min){
            min = arr[i];
            cout << "Min value = " << min << endl;
            break;
        }
    }

    cout << "Middle element = " << arr[5] << endl;
    
    return 0;
}