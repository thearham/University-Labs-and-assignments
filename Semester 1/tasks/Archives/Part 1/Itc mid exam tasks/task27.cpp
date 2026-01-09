#include <iostream>
using namespace std;
// find the smallest and largest number using loops
int main(){
    int range, numbers, max_number, min_number;
    cout << "Enter range: ";
    cin >> range;

    for(int i = 1; i<=range; i++){
        cout << i << " Number: ";
        cin >> numbers;

        if(i==0 || numbers > max_number){
            max_number = numbers;
        }
        if(i==0 || numbers < min_number){
            min_number = numbers;
        }
    }
    cout << "The max number is " << max_number << endl;
    cout << "The min number is " << min_number << endl;
    
    return 0;
}