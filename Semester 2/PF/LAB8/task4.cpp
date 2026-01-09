#include <iostream>

using namespace std;

int main()
{
    int n;

    cout << "Enter the number of elements you want to enter: ";
    cin >> n;

   
    int* arr = new int[n];

    
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    
    cout << "The elements you entered are: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    
    delete[] arr;

    return 0;
}
