#include <iostream>
using namespace std;

void inputArray(int alpha[]) {
    for (int i = 0; i < 12; i++) {
        cout << "Enter " << i + 1 << " Element for Alpha:\t";
        cin >> alpha[i];
    }
}
void doubleArray(const int a[], int beta[]) {
    for (int i = 0; i < 12; i++) {
        beta[i] = a[i] * 2;
    }
}
void copyAlphaBeta(int matrix[][4], const int alpha[], const int beta[]) {
    int rowSize = 6, columSize = 4;
    int index = 0;
    int i = 0;
    for (; i < 3; i++) {
        for (int j = 0; j < columSize; j++) {
            matrix[i][j] = alpha[index++];
        }
    }
    index = 0;
    for (; i < rowSize; i++) {
        for (int j = 0; j < columSize; j++) {
            matrix[i][j] = beta[index++];
        }
    }
}

int main(){
    int counter = 0, i, j;
    int alpha[12];
    int beta[12];
    int matrix[6][4];
    inputArray(alpha);
    doubleArray(alpha, beta);
    copyAlphaBeta(matrix, alpha, beta);
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 4; j++) {
            cout << matrix[i][j] << "\t";
            if (++counter >= 10) {
            counter = 0;
            cout << endl;
            }
        }
    }
    system("pause");
    return 0;
}