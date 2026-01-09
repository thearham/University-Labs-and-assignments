#include <iostream>
using namespace std;

int main() {
  
  int size;
  cout << "Enter the size of the array: ";
  cin >> size;

  
  int *array = new int[size];

  
  for (int i = 0; i < size; i++) {
    cout << "Enter element " << i + 1 << ": ";
    cin >> array[i];
  }

 
  int largest = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > largest) {
      largest = array[i];
    }
  }

  
  cout << "The largest element in the array is: " << largest << endl;

  
  delete[] array;

  return 0;
}
