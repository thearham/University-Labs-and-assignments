#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    ifstream in("numbers.txt");
    unordered_map<int, int> frequency;
    string line;
	
    while (getline(inputFile, line)) {
        istringstream iss(line);
        int numbers;
        while (iss >> numbers) {
            frequency[numbers]++;
        }
    }
    in.close();

    cout << "Frequency:" << endl;
    for (const auto& pair : frequency) {
        cout << pair.first << ": " << pair.second << endl;
    }
	
	system("pause");
    return 0;
}
