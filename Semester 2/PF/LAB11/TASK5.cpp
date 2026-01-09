#include <iostream>
using namespace std;

const int ROW = 3;
const int COL = 3;


void multiplyMatrix(int[][COL], int[][COL]);

int main() {
    int matrix[ROW][COL];

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "The input matrix is:" << endl;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    multiplyMatrix(matrix, matrix);

    return 0;
}


void multiplyMatrix(int matrix1[][COL], int matrix2[][COL]) {
    int result[ROW][COL];

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COL; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    cout << "The result of multiplying the matrix by itself is:" << endl;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
