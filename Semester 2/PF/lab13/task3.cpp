#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int matrix[2][4];
    ifstream file("data.txt");
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            file >> matrix[i][j];
        }
    }
    for (int i = 2; i >= 0; i--) {
        for (int j = 3; j >= 0; j--) {
            if(matrix[i][j] == (-99)){
                continue;
            }
            else
                cout << matrix[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}