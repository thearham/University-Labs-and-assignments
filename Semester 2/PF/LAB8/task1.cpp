#include <iostream>
using namespace std;

void checkWin(int numbers[], int target) {
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    sum += numbers[i];
  }

  if (sum >= target) {
    cout << "Ashan wins the game!" << endl;
  } else {
    cout << "Ashan loses the game." << endl;
  }
}

int main() {
  
  int target;
  cout << "Ask Ali to guess a random number: ";
  cin >> target;

  
  int numbers[5];
  cout << "Ask Ahsan to guess 5 different random numbers: ";
  for (int i = 0; i < 5; i++) {
    cin >> numbers[i];
  }

  
  checkWin(numbers, target);

  return 0;
}
