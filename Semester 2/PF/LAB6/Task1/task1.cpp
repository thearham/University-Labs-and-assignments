#include <iostream>
#include <fstream>
using namespace std;

int main(){
    char str;
    int numbers = 0; int character = 0; int spaces = 0;
    ifstream myFile("data.txt");

    while(myFile.get(str)){
        if ((int(str) >= 97 && int(str) <= 122)||(int(str) >= 65 && int(str) <= 90))
        {
            character++;
        }
        else if(int(str) >= 48 && int(str) <= 57){
            numbers++;
        }
        else if (int(str) == 32)
        {
            spaces++;
        }
               
        
    }
    cout << "Number of Alphabets = " <<  character << "\n";
    cout << "Number of numbers = " << numbers << "\n";
    cout << "Number of spaces = " << spaces << "\n";


    return 0;
}