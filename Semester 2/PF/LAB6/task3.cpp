#include <iostream>
using namespace std;

void mergeArray(char [], char []);

int main(){
    char array1[10], array2[10];

    cout << "Enter 1st char array: ";
    cin.getline(array1, 10);
    cout << "Enter 2nd char array: ";
    cin.getline(array2, 10);

    mergeArray(array1, array2);

    return 0;
}

void mergeArray(char arr1[], char arr2[]){
    char arr3[20];
    int index = 0;

    for (int i = 0; i < 10; i++)
    {
        arr3[i] = arr1[i];
        index++;
    }
    for (int i = 0; i < 10; i++)
    {
        arr3[i+index] = arr2[i];
    }

    for (int i = 0; arr3[i] != '\0'; i++)
    {
        cout << arr3[i] << " ";
    }
    
    
    

}