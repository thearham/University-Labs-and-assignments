#include <iostream>
#include <fstream>

using namespace std;

int c_filesize(char* filename) {
    ifstream file(filename);
    int size = 0;
	char num[20];
	while(file >> num){
		size++;
	}
    file.close();
    return size;
}

int* dynamic_mem(int s) {
    int* arr = new int[s];
//	cout << arr << endl;
    return arr;
}

void read(char* filename, int* arr, int s) {
    ifstream file(filename);
    for (int i = 0; i < s; i++) {
        file >> arr[i];
    }
    file.close();
}

void display(int* ptr, int s) {
    cout << "The array contains the following elements: " << endl;
    for (int i = 0; i < s; i++) {
        cout << ptr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size = 0;
    int* arr = NULL;
    char f_name[20] = "data.txt";
    size = c_filesize(f_name);
    arr = dynamic_mem(size);
    read(f_name, arr, size);
    display(arr, size);
    return 0;
}
