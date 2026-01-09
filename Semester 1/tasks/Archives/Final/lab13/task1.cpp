#include <iostream>
using namespace std;

int BinarySearch(int arr[],int low, int high,int x) {
     while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == x)
                return mid;

            if (arr[mid] < x)
                return low = mid + 1;

            else
                return high = mid - 1;
  }
  return -1;
}

int main(){
    int size, i,j, holder, x;

    cout << "Enter the size of array = ";
    cin >> size;

    int arr[size];

    cout << "Input the number of elements of array = ";
    for (i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Sorted array elements = ";
    for (i = 0; i < size - 1; i++)
    {
       for (j = 0; j < size -1; j++)
       {
        if(arr[j] > arr[j+1])
        {
            holder = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = holder;
        }
       }       
    }
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
    
    cout << "Input the value to search = ";
    cin >> x;

    int output;

output = BinarySearch(arr,0, size-1, x);

if(output == -1){
    cout << "Value not found!" << endl;}
    else {
        cout << x << " value found at position = " << output << endl;
    }

    
    
    system("pause");
    return 0;
}