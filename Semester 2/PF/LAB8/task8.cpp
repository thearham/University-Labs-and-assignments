#include <iostream>
using namespace std;

int main() {
  
  int size;
  cout << "Enter the size of the  array: ";
  cin >> size;

  
  int *array1 = new int[size];

  
  for (int i = 0; i < size; i++) {
    cout << "Enter element " << i + 1 << " of the first array: ";
    cin >> array1[i];
  }

  
  

  
  int *array2 = new int[size];

  
  for (int i = 0; i < size; i++) {
    cout << "Enter element " << i + 1 << " of the second array: ";
    cin >> array2[i];
  }

  
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += array1[i];
  }
  for (int i = 0; i < size; i++) {
    sum += array2[i];
  }

  
  cout << "The sum of the elements of both arrays is: " << sum << endl;

  
  delete[] array1;
  delete[] array2;

  return 0;
}
