#include <iostream>
using namespace std;

int main(){
    int count,i,k;
    int arr1[30],arr2[30],arr3[30];

    cout <<"Enter no of elements?";
    cin>>count;

    cout<<"Enter element array1:";
    for (i = 0; i < count; i++)
    {
        cin >> arr1[i];
        arr3[i] = arr1[i];
    }
    k = i;
    cout<<"Enter element array2:";
    for (i = 0; i < count; i++)
    {
        cin >> arr2[i];
        arr3[k] = arr2[i];
        k++;
    }
    cout << "merged array = ";
    for (i = 0; i < k; i++)
    {
        cout << arr3[i] << " ";
    }
    

    
    return 0;
}