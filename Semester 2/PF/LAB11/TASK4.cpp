#include <iostream>
using namespace std;

const int ROW = 3;
const int COL = 3;


void findRowSums(int[][COL]);

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

    findRowSums(matrix);

    return 0;
}


void findRowSums(int matrix[][COL]) {
    cout << "The row sums are:" << endl;
    for (int i = 0; i < ROW; i++) {
        int sum = 0;
        for (int j = 0; j < COL; j++) {
            sum += matrix[i][j];
        }
        cout << sum << endl;
    }
}
