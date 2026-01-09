#include <iostream>
using namespace std;

int main() {
    int rows, columns;
    cout << "Enter the number of rows in the jagged array: ";
    cin >> rows;

    int **jaggedArray = new int*[rows];


    for (int i = 0; i < rows; i++) {
        cout << "Enter the number of columns for row " << i + 1;
        cin >> columns;

        jaggedArray[i] = new int[columns];

        cout << "Enter the elements of row " << i + 1 << ": ";
        for (int j = 0; j < columns; j++) {
            cin >> jaggedArray[i][j];
        }
    }

    cout << "The elements of the jagged array are: " << endl;
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < columns; j++) {
            cout << jaggedArray[i][j] << " ";
        }
    cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] jaggedArray[i];
    }
    delete[] jaggedArray;

    return 0;
}

