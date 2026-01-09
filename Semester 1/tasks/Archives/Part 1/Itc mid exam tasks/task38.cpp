#include <iostream>
using namespace std;
// to find the factorial of a number
int main(){
    int n;
    int factorial = 1;
    cout<< "Enter a positive integer: ";
    cin >> n;
    if(n<0){
        cout << "no factorial of negatve number! ";
    }
    else{
        for(int i =1; i <= n; i++){
            factorial *= i;
        }
    }
    cout << factorial;
    return 0;
}