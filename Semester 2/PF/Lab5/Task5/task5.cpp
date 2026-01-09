#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int numbers[10];
    int number;
    ifstream in_f("integers.txt");
    
    for (int i = 1; i < 6; i++)
    {
        in_f >> numbers[i];
    }

    in_f.close();
    
    ofstream out_f("integers.txt");
    cout << "Enter the number to add: ";
    cin >> number;

    numbers[0] = number;

   for (int i = 0; i < 6; i++)
    {
        out_f << numbers[i] << " ";
    }
    
    
    
    
    return 0;
}