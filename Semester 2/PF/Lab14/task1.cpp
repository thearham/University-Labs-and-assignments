#include <iostream>
using namespace std;

int main() {
    int rows, columns, **jaggedArray;
    cout<<  "Enter the number of rows in the jagged array: ";
    cin >> rows;
    
    int **array = new int*[rows];

    for (int i = 0; i < rows; i++) {
        cout << "Enter the number of columns for row " << i + 1;
        cin >> columns;

        array[i] = new int[columns];

        cout << "Enter the elements of row " << i + 1 << ": ";
        for (int j = 0; j < columns; j++) {
            cin >> array[i][j];
        }
    }

    jaggedArray = new int*[rows];


    for (int i = 0; i < rows; i++) {
        jaggedArray[i] = array[i];
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
        delete[] array[i];
    }
    delete[] array;
    delete[] jaggedArray;

    return 0;
}