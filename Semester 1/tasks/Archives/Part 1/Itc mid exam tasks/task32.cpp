#include <iostream>
using namespace std;
//take n numbers from the user and determine that how many positive and negative integers were entered by user.

int main(){
    int positive=0, negative=0, range, numbers;
    cout << "Enter range: ";
    cin >> range;

    for(int i =1; i <= range; i++){
        cout << "Enter number: ";
        cin >> numbers;

        if(numbers > 0){
        positive++;}
        else if(numbers < 0){
        negative++;}
    }
    cout << "Positive integers: " << positive<<endl;
    cout << negative;

    
    return 0;
}