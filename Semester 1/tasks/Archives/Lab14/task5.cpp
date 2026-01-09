#include <iostream>
using namespace std;

int main(){
    char arr[20];
    int count;
    cout << "Enter the array: ";
    cin.get(arr, 20);

    for(int i = 0; arr[i] != '\0'; i++){
        for (int j = 0; j <=i ; j++){
            if(arr[i] == arr[j]){
                ++count;   
            }
        }
        
        
        
    }
    for(int i = 0; arr[i] != '\0'; i++){
        cout << arr[i] <<  " = " << count << endl;
    }
    return 0;
}