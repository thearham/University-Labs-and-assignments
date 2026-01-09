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

    int j = 0; 
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            continue;
        }
        data[j++] = data[i];
    }

    n = j;
    cout << "Updated Data: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    delete[] data;
    return 0;
}
