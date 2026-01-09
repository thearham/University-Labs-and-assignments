#include <iostream>
using namespace std;

void sortArray(int []);
int main(){
    int count = 10;
    int arr1[10];

    cout << "Enter Array elements: ";
    for (int i = 0; i < count; i++)
    {
        cin >> arr1[i];
    }

    sortArray(arr1);
        
    return 0;
}

void sortArray(int arr[]){
    int ascending[10], descending[10];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            
        }
    }
    for (int i = 0; i < 10; i++)
    {
        ascending[i] = arr[i];
    }
    
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (arr[j] < arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            
        }
    }
    for (int i = 0; i < 10; i++)
    {
        descending[i] = arr[i];
    }
    cout << "Array in Ascending order = ";
    for (int i = 0; i < 10; i++)
    {
        cout << ascending[i] << " ";
    }
    cout << "\nArray in Descending order = ";
    for (int i = 0; i < 10; i++)
    {
        cout << descending[i] << " ";
    }
     
}