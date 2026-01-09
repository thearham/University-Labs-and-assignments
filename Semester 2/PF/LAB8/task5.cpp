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

  
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += array[i];
  }

  
  cout << "The sum of all the elements in the array is: " << sum << endl;

  
  delete[] array;

  return 0;
}
