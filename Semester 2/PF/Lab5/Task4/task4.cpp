#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int number;
    ifstream in_f("average.txt");
    ofstream out_f("newFile.txt");
    
    in_f >> number;

    if(number < 4)
    {
        out_f << "Below average";
    }
    else if (number >= 4 && number <= 6)
    {
        out_f << "Average";
    }
    else if (number > 6)
    {
        out_f << "Above average";
    }
    
    

    return 0;
}