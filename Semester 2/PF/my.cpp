#include <iostream>
#include <fstream>

using namespace std;


void readSize(ifstream& fin, int& row, int& col) {
  fin >> row >> col;
}


void createMatrix(int**& m, int row, int col) {
  m = new int* [row];
  for (int i = 0; i < row; i++) {
    m[i] = new int[col];
  }
}


void inputMatrixFromFile(ifstream& fin, int**& m, int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      fin >> m[i][j];
    }
  }
}


int at(int**& p, int r, int c) {
  return p[r][c];
}


void printMatrix(int**& p, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << p[i][j] << " ";
    }
    cout << endl;
  }
}


int isIdentity(int**& p, int rows, int cols) {
  if (rows != cols) return false;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (i == j && p[i][j] != 1) return false;
      if (i != j && p[i][j] != 0) return false;
    }
  }
  return true;
}


bool isRectangular(int**& p, int rows, int cols) {
  return rows != cols;
}


bool isDiagonal(int**& p, int rows, int cols) {
  if (rows != cols) return false;
  bool flag = false;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (i != j && p[i][j] != 0) return false;
      if (i == j && p[i][j] != 0) flag = true;
    }
  }
  return flag;
}


bool isNullMatrix(int**& p, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (p[i][j] != 0) return false;
    }
  }
  return true;
}

bool isLowerTriangular(int**& p, int rows, int cols)
{
    if (rows != cols) return false;
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < cols; j++) {
            if (p[i][j] != 0) return false;
        }
    }

    return true;
}
bool isUpperTriangular(int**& p, int rows, int cols)
{
    if (rows != cols) return false;
    for (int i = 1; i < rows; i++) {
        for (int j = 0; j < i; j++) {
            if (p[i][j] != 0) return false;
        }
    }

    return true;
}

void freeMatrix(int**& p, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        delete[] p[i];
    }
    delete[] p;
    p = nullptr;
}

int** Transpose(int**& p, int rows, int cols)
{
    int** transposed = new int* [cols];
    for (int i = 0; i < cols; i++) {
        transposed[i] = new int[rows];
        for (int j = 0; j < rows; j++) {
            transposed[i][j] = p[j][i];
        }
    }

    return transposed;
}

int** add(int**& a, int row1, int col1, int**& b, int row2, int col2)
{
    if (row1 != row2 || col1 != col2) return nullptr;
    int** sum = new int* [row1];

    for (int i = 0; i < row1; i++) {
        sum[i] = new int[col1];
        for (int j = 0; j < col1; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    return sum;
}