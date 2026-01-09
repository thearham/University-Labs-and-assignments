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

    int numberToRemove;
    cout << "Enter the number you want to remove: ";
    cin >> numberToRemove;

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (data[i] == numberToRemove) {
            continue;
        }
        data[j++] = data[i];
    }
    n = j;
    cout << "Maximum Number: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    delete[] data;
    return 0;
}
