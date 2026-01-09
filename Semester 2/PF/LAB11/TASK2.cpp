#include <iostream>

using namespace std;

const int ROWS = 3;
const int COLS = 3;


void swapColumns(int matrix[][COLS]);

int main() {
  
  int matrix[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  
  cout << "Original matrix:" << endl;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  
  swapColumns(matrix);

  
  cout << "Modified matrix:" << endl;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}


void swapColumns(int matrix[][COLS]) {
  for (int i = 0; i < ROWS; i++) {

    int temp = matrix[i][0];
    matrix[i][0] = matrix[i][COLS - 1];
    matrix[i][COLS - 1] = temp;
  }
}
