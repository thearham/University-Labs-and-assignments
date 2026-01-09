#include <iostream>
using namespace std;

int main(){
    int numbers, size = 3, max_numbers;
    // input 3 numbers and determine the largest using loops
    for(int i = 0; i < size; ++i){
        cin >> numbers;

        if(i==0 || numbers > max_numbers){
            max_numbers = numbers;
        }
    }
    cout << max_numbers;
       
    system("pause");
    return 0;
}