#include <iostream>
using namespace std;

int main(){
    int y;
    float n, result = 1;

    cout << "Input n: ";
    cin >> n;
    cout << "Input power y: ";
    cin >> y;

    cout << y << " power of " << n << " = ";
    
    while(y != 0){
        result *= n;
        --y;
    }
    cout << result << endl;

    system("pause");
    return 0; 
}