#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string filename;
    cout << "Enter the name of the file: ";
    cin >> filename;

    ifstream file(filename); 
    if (!file.is_open()) { 
        cout << "Unable to open file" << endl;
        return 1;
    }
    int n = 0; 
    int x; 
    while (file >> x) {
        n++;
    }
	file.close();
	
    ofstream ofile(filename);

    int* data = new int[n];
    int j = 0;
    while (ofile >> x) {
        if (x < 10 || x > 99) {
            continue;
        }
        data[j++] = x;
    }
    n = j;
    
	ofile.close();
    cout << "Two-digit: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    delete[] data;
    return 0;
}
