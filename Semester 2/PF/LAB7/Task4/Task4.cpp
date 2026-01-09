#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream dataFile("Data.txt");

    float numbers[2][10];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            dataFile >> numbers[i][j];
        }
    }
    float max = numbers[0][0];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (numbers[i][j] > max)
            {
                max = numbers[i][j];
            }   
        }
    }
    cout << max << endl;
    dataFile.close();
    return 0;
}