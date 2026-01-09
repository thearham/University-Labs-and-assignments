#include <iostream>
using namespace std;

int main(){
    int number1, number2, iterations = 0;

    do{
        ++iterations;
        for(int i = 1; i<= iterations; i++){
            cout << "Input number pair " << i << " : ";
            cin >> number1 >> number2;
        }
        
        if(number1 % number2 == 0){
            break;
        }
        
    }while(true);
    cout << "Your desired number pair is (" << number1 << "," << number2 << ")" << endl;

    system("pause");
    return 0;
}