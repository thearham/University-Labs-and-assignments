#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream dataFile("Data.txt");
    char names[4][15];

    for (int i = 0; i < 4 ; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            dataFile >> names[i][j];
        }
    }
    for (int i = 0; i < 4 ; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            cout << names[i][j];
        }
    }
    
    
    return 0;
}