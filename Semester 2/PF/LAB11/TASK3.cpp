#include <iostream>

using namespace std;

const int ROWS = 2;
const int COLS = 3;


void incrementMatrix(int matrix[][COLS]);

int main() {
  
  int matrix[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}};

  
  cout << "Original matrix:" << endl;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }


  incrementMatrix(matrix);

  
  cout << "Modified matrix:" << endl;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}


void incrementMatrix(int matrix[][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      
      matrix[i][j] += 2;
    }
  }
}
