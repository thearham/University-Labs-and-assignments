#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int* data = new int[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    int numberToInsertAfter;
    int numberToInsert;
    cout << "Enter the number after which you want to insert: ";
    cin >> numberToInsertAfter;
    cout << "Enter the number you want to insert: ";
    cin >> numberToInsert;

    int* newData = new int[n + 1];  
    int j = 0;
    for (int i = 0; i < n; i++) {
        newData[j++] = data[i];
        if (data[i] == numberToInsertAfter) {
            newData[j++] = numberToInsert;
        }
    }

    cout << "New dynamic array: ";
    for (int i = 0; i < j; i++) {
        cout << newData[i] << " ";
    }
    cout << endl;

    delete[] data;
    delete[] newData;
    return 0;
}
