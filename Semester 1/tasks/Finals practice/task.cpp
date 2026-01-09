#include <iostream>
using namespace std;

int main(){
    int arr[3];
    int largest;
    cout << "Input array: ";
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];        
    }
    for (int i = 1; i < 3; i++)//to store the max value at arr[0]
    {
        if(arr[i] > arr[0]){
            arr[0] = arr[i];
            largest = arr[0];            
        }
         
       
    }
    for (int i = 0; i < 3; i++)
    {
        arr[i] = largest;
        cout << arr[i] << " ";
    }
    
    
    
    return 0;
}