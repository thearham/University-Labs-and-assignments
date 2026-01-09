
#include <iostream>
using namespace std;

void ins(int arr[], int n)
{
    for (int i = 1; i < n; i++) {
        int value = arr[i];
        int hole = i;
        while(hole > 0 && arr[hole-1] > value)
        {
            arr[hole] = arr[hole - 1];
            hole = hole-1;
        }
        arr[hole] = value;
    }
}

int main()
{
    int arr[5] = {5,4,3,2,1};
    ins(arr, 5);
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}