#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int sum = 0, max, min;
    int numbers[10];
    ifstream in_f("integers.txt");
    ofstream out_f("result.txt");

    for (int i = 0; i < 5; i++)
    {
        in_f >> numbers[i];
    }
    for (int i = 1; i < 5; i++)
    {
        if (numbers[0] < numbers[i])
        {
            numbers[0] = numbers[i];
            max = numbers[0];
        }   
    }
    for (int i = 1; i < 5; i++)
    {
        if (numbers[0] > numbers[i])
        {
            numbers[0] = numbers[i];
            min = numbers[0];
        }
        
    }

    out_f << "Max = " << max << endl
    << "Min = " << min << endl; 
   
    
    
    
    return 0;
}