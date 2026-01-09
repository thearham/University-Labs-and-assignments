#include <iostream>
using namespace std;
// to calculate power using loops
int main(){
    int a = 2, n = 6, result = 1;
    while(n != 0 ){
        result *= a;
        --n;
    }
    
    cout << result;
    
    return 0;
}