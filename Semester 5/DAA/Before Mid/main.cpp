#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int start, int end)
{
    int x = arr[end];
    int i = start-1;
    for (int j = start; j <= end - 1  ; j++) {
        if(arr[j] <= x)
        {
            i ++;
            swap(arr, i, j);
        }
       
    }
    swap(arr, i+1, end);
    return i+1;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pi = partition(arr, start, end);
        quickSort(arr,start, pi-1);
        quickSort(arr, pi+1, end);
    }
}

int main()
{
    int arr[5] = {5,4,3,2,1};
    quickSort(arr, 0, 4);
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    
}