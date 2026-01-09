#include <iostream>
using namespace std;

void reverseArray(int  []);
int main(){
    
    int arr1[5];
    cout << "Input array elements = ";
    for (int i = 0; i < 5; i++)
    {
        cin >> arr1[i];
    }
    cout << "Reversed array = ";
    reverseArray(arr1);
    return 0;
}
void reverseArray(int  arr[]){
    int reversed[5];
      
    for (int i = 0; i < 5; i++)
    {
        reversed[5 - 1 - i] = arr[i];
    }
    for (int  i = 0; i < 5; i++)
    {
        cout << reversed[i] << "\t";
    }
}