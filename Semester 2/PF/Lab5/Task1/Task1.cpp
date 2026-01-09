#include <iostream>
#include <fstream>
using namespace std;

int main(){
    char c;
    ifstream in_f("read-1.txt");
    ofstream out_f("write-1.txt");

    while (in_f.get(c))
    {
        out_f.put(c);
    }
    
    in_f.close();
    out_f.close();
    
    return 0;
}