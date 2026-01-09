#include <iostream>
using namespace std;

void countSort(int arr[], int size)
{
    int k = arr[0];
    for (int i = 0; i < size; i++)
    {
        k = max(k,arr[i]);
    }
    int count[8] = {0};
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }
    for (int i = 1; i <= k; i++)
    {
        count[i] += count[i-1];
    }
    int output[size];
    for (int i = size - 1; i >= 0; i++)
    {
        output[--count[arr[i]]]=arr[i];
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }

    
    
}
int main()
{
    int arr[] = {3,2,4,6,4,8,7,1};
    countSort(arr,8);
    for (int  i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}