#include <iostream>
using namespace std;

// Function that takes an integer argument passed by value
void incrementByValue(int x) {
  x++;
}

int main() {
  int a = 5;
  cout << "Before calling the function, a = " << a << endl;
  incrementByValue(a);
  cout << "After calling the function, a = " << a << endl;
  return 0;
}
