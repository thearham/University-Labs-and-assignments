#include <iostream>
using namespace std;


void insert(int arr[], int n)
{
    int temp, i = n;
    temp = arr[n];
    while(i > 1 && temp > arr[i/2])
    {
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[i] = temp;
}
void deleteH(int arr[], int n)
{
    int x, i, j;
    x = arr[n];
    arr[1] = arr[n];
    arr[n] = x;
    i = 1;
    j = 2 * i;
    while(j < n-1)
    {
        if(arr[j+1] > arr[j])
        {
            j = j+1;
        } 
        if(arr[i] < arr[j])
        {
            swap(arr[i], arr[j]);
            i = j;
            j = 2 * j;
        }
        else
        {
            break;
        }
    }
    arr[n] = x;
}

int main()
{
    int arr[8] = {0, 10, 20, 30, 25, 5, 40, 35};
    for(int i = 2; i < 8; i++)
    {
        insert(arr, i);
    }
    for (int i = 2; i < 8; i++)
    {
        deleteH(arr, i);
    }
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << endl;
    }
    

    return 0;
}