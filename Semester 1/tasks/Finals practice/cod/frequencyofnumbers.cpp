#include <iostream>
using namespace std;

int main(){
    int count, i, j,cntr, r;

    cout << "Enter integer: ";
    cin >> count;

    
    for (i = 0; i < 10; i++)
    {
        cout << "The frequency of " << i << " = ";
        cntr = 0;
        for (j = count; j > 0 ; j = j / 10)
        {
            r = j % 10;
            if (r == i){
                cntr++;
            }
        }
        cout << cntr << endl;
        
    }
    
    
    
    return 0;
}