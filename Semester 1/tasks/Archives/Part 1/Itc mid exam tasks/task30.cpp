#include <iostream>
using namespace std;

int main(){
    int i,range, numbers;
    float sum = 0, average;
    cout << "Enter the range of numbers: ";
    cin >> range;

    for(i=0; i<range; ++i){
        cout << "Enter number " << i + 1 << ": ";
        i = numbers;
        cin >> numbers;

        sum += numbers;

    }
    average = sum / 100;
    cout << "The average of numbers = " << average << endl;

    system("pause");
    return 0;
}