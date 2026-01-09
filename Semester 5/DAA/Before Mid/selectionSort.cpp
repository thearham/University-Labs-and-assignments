
#include <iostream>
using namespace std;

void sel(int arr[],int n)
{
    for (int i = 0; i < n - 1; i++) {
        int imin = i;
        for (int j = i+1; j < n; j++) {
            if(arr[j] < arr[imin])
            {
                imin = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[imin];
        arr[imin] = temp;
    }
}

int main()
{
    int arr[5] = {5,4,3,2,1};
    sel(arr, 5);
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}