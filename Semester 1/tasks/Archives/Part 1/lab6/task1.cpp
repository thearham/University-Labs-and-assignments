#include <iostream>
using namespace std;

int main(){
    int current_year, joined_year;
    cout << "Enter current year: ";
    cin>> current_year;
    cout << "Enter joined year: ";
    cin >> joined_year;

    if(current_year - joined_year > 3){
        cout << "You will get the bonus of Rs 2500\n";
    } 
    else{
        return 0;
    }
    system("pause");
    return 0;
}