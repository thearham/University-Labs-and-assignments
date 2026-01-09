#include <iostream>
#include <fstream>
using namespace std;

int main() {
int size = 0, max_ones = 0, cur_ones = 0, start_index = 0, max_start_index = 0;
char ch;
ifstream file("task1.txt");
// Calculate size of the data in the file
while (file >> ch) {
    size++;
}
file.clear();
file.seekg(0, ios::beg);

// Allocate memory for the dynamic array
char *data = new char[size];
// Read the data from file and store in the dynamic array
int i = 0;
while (file >> ch) {
    data[i++] = ch;
}

// Find the maximum consecutive ones
for (int i = 0; i < size; i++) {
    if (data[i] == '1') {
        cur_ones++;
        if (cur_ones == 1) {
            start_index = i;
        }
    } else {
        if (cur_ones > max_ones) {
            max_ones = cur_ones;
            max_start_index = start_index;
        }
        cur_ones = 0;
    }
}

// Print the result
cout << "maximum consecutive ones are: ";
for (int i = max_start_index; i < max_start_index + max_ones; i++) {
    cout << data[i];
}
cout << endl;
cout << "Starting index is: " << max_start_index << endl;
cout << "Length is: " << max_ones << endl;

// Deallocate the memory
delete[] data;

return 0;
}
