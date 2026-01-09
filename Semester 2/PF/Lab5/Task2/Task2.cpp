#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int sum = 0;
    int numbers[10];
    ifstream in_f("integers.txt");
    ofstream out_f("result.txt");

    for (int i = 0; i < 5; i++)
    {
        in_f >> numbers[i];
    }
    for (int i = 0; i < 5; i++)
    {
        sum += numbers[i];
    }
    

    out_f << "The sum of numbers = " << sum << endl
    << "The average = " << sum / 5 << endl; 
   
    
    
    
    return 0;
}