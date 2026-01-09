#include <iostream>
using namespace std;

int main()
{
    const int count = 7;
    int arr[count];
    int rot[count];
    int k = 3;
    int i;


    cout << "Input array: ";
    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < count; i++)
    {
        rot[(i + k) % count] = arr[i]; // if rotation to right then (i+count - k) % count.
    }
    cout << "Rotated array: " ;
    for (int i = 0; i < count; i++)
    {
        cout << rot[i] << " ";
    }
    
    

    return 0;
}