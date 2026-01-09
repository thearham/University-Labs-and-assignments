#include <iostream>
using namespace std;

int main(){
    int number, iterations = 0;
    do{
        cout << "Enter number: ";
        cin >> number;
        iterations++;

        if(number%2 == 0 && number > 0){
            break;
        }
    }while(true);
    cout << "You have entered a positive even number in " << iterations << " attempts." << endl;

    system("pause");
    return 0;
}