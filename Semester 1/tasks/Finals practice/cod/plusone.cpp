#include <iostream>
using namespace std;

int main(){
    int arr[30];
    int count, i;

    cout << "Enter the size of the array: ";
    cin>> count;
    for (int j = 0; j < count; j++)
    {
        cin>> arr[j];
    }
    

    i = count - 1;

    while (i >= 0)
    {
        if(arr[i] != 9){
            arr[i] += 1;
        }
        else{
            arr[i] = 0;
        }
        
        --i;
    }
    for (int j = 0; j < count; j++)
    {
        cout <<  arr[j];
    }
    
    return 0;
}