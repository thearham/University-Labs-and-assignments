//program to move all the zeros to the end in an array

#include <iostream>
using namespace std;

int main(){
    int size = 5;
    int arr[size] = {1,0,4,0,5};
    int j = 0;
    // we will use zero as the pivot and will swap the non zeros values to the left.
    for (int i = 0; i < size; i++)
    {
        if(arr[i] != 0)// checks whether the element is non zero
        {
            int hold = arr[i];// brings the non-zero elements the left
            arr[i] = arr[j];
            arr[j] = hold;
            j++;
        }
        
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
    
    return 0;
}