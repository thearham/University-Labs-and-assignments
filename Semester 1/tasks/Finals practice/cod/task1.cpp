#include <iostream>
using namespace std;

int main(){
    int count = 3;
    int arr[count];
    int highest;

    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
    }
    
    
    for (int i = 1; i < count; i++)
    {
        if(arr[i] > arr[0]){
            highest = arr[i];
        }
    }
    for (int i = 0; i < count; i++)
    {
        arr[i] = highest;
        cout << arr[i] << " ";
    }
    
    
    
    

    return 0;
}