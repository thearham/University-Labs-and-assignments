#include <iostream>
using namespace std;

int main(){
    int number,i;
    bool prime = true;
    cout << "Enter number: ";
    cin >> number;

    for(i=2; i<= number/2; i++ ){
        if(number%i == 0){
            prime = false;
            break;
        }
    }
    
    if(prime){
        cout << "Number is a prime!" << endl;
    }
    else{
        cout << "Number is not a prime!" << endl;
    }
    system("pause");
    return 0;
}