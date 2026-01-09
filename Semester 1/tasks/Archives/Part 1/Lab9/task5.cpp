#include <iostream>
using namespace std;

int main(){
    int number, range = 1, sum = 0;
    cout << "Enter the number: ";
    cin >> number;

    while(range < number){
        if(number%range == 0){
            sum += range;
        }
        range++;
    }
    if(sum == number){
        cout << number << " is a perfect number." << endl;
    }
    else{
        cout << number << " is not a perfect number." << endl;
    }

    system("pause");
    return 0;
}
