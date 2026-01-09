#include <iostream>
using namespace std;

int main(){
    int i,j;
    int count = 5;
    int arr[count] = {51,32,43,24,5};

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
    
    
    return 0;
}