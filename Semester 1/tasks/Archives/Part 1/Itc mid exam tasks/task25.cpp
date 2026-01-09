#include <iostream>
using namespace std;
// find the sum of 10 numbers entered by user
int main(){
    int n,i, sum = 0;

    cout << "Enter 10 numbers: ";
    for(i=0; i<10; i++){
        cin >> n;

        sum += n;


    }
    cout << "The sum of 10 numbers = " << sum << endl;
    system("pause");
    return 0;
}