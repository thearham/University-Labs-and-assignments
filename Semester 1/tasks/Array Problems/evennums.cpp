// program to find even numbers in even index array

#include <iostream>
using namespace std;

int main(){
    int size = 10;
    int arr[size] = {1,2,3,4,6,7,8,9,10,12};
    int total = 0;

    for (int i = 0; i < size; i++)
    {
        if(arr[i]%2 == 0)
        {
            total++;
        }
    }
    cout << "Number of even numbers in even index are: " << total << endl;
    
    
    return 0;
}