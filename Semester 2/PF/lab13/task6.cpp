#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int matrix[3][4];
    int diagonal[3];
    ifstream file("input.txt");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            file >> matrix[i][j];
        }
        
    }
    int k = 0;
    for (int i = 0; i < 3; i++)
    {
        cout << matrix[i][k] << " ";
        k++;
    }
    



    return 0;
}